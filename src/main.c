#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>

// codec
#include "raw_decode.h"
#include "wav_decode.h"
#include "ym2608_encode.h"

// application
#include "a44enc.h"

// abort control
static int16_t abort_flag = 0;

//
//  sigint handler
//
static void sigint_handler(int signal) {
  if (signal == SIGINT) {
    abort_flag = 1;
  }
}

//
//  show help message
//
static void show_help_message() {
  printf("usage: a44enc [options] <input-file(.sXX|.mXX|.wav)> <output-file(.aXX|.nXX)>\n");
  printf("options:\n");
  printf("     -v[n] ... volume (1-200, default:100)\n");
  printf("     -h    ... show help message\n");
}

//
//  main
//
int32_t main(int32_t argc, char* argv[]) {

  // default exit code
  int32_t rc = -1;

  // pcm attribs
  int16_t volume = 100;
  int16_t* fread_buffer = NULL;
  int16_t* pcm_buffer = NULL;
  uint8_t* output_buffer = NULL; 
  char* input_file_name = NULL;
  char* output_file_name = NULL;
  output_file_name[0] = '\0';

  // input and output file handle
  FILE* fp = NULL;
  FILE* fo = NULL;

  // decoders
  RAW_DECODE_HANDLE raw_decoder = { 0 };
  WAV_DECODE_HANDLE wav_decoder = { 0 };

  // encoder
  YM2608_ENCODE_HANDLE ym2608_encoder = { 0 };

  // credit
  printf("a44enc - S44/WAV to A44 encoder version " PROGRAM_VERSION " by tantan\n");

  // command line
  for (int16_t i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && strlen(argv[i]) >= 2) {
      if (argv[i][1] == 'v') {
        volume = atoi(argv[i]+1);
        if (volume < 1 || volume > 200) {
          show_help_message();
          goto exit;
        }
      } else if (argv[i][1] == 'h') {
        show_help_message();
        goto exit;
      } else {
        printf("error: unknown option (%s).\n",argv[i]);
        goto exit;
      }
    } else {
      if (output_file_name != NULL) {
        printf("error: too many file names\n");
        show_help_message();
        goto exit;
      } else if (input_file_name != NULL) {
        output_file_name = argv[i];
      } else {
        input_file_name = argv[i];
      }
    }
  }

  // no input file?
  if (input_file_name == NULL) {
    show_help_message();
    goto exit;
  }

  // no output file?
  if (output_file_name == NULL) {
    show_help_message();
    goto exit;
  }

  // input format check
  char* input_file_exp = input_file_name + strlen(input_file_name) - 4;
  int16_t input_format = FORMAT_WAV;
  int32_t pcm_freq = 44100;
  int16_t pcm_channels = 2;
  if (stricmp(".s32", input_file_exp) == 0) {
    input_format = FORMAT_RAW;
    pcm_freq = 32000;
    pcm_channels = 2;
  } else if (stricmp(".s44", input_file_exp) == 0) {
    input_format = FORMAT_RAW;
    pcm_freq = 44100;
    pcm_channels = 2;
  } else if (stricmp(".s48", input_file_exp) == 0) {
    input_format = FORMAT_RAW;
    pcm_freq = 48000;
    pcm_channels = 2;
  } else if (stricmp(".m32", input_file_exp) == 0) {
    input_format = FORMAT_RAW;
    pcm_freq = 32000;
    pcm_channels = 1;
  } else if (stricmp(".m44", input_file_exp) == 0) {
    input_format = FORMAT_RAW;
    pcm_freq = 44100;
    pcm_channels = 1;
  } else if (stricmp(".m48", input_file_exp) == 0) {
    input_format = FORMAT_RAW;
    pcm_freq = 48000;
    pcm_channels = 1;
  } else if (stricmp(".wav", input_file_exp) == 0) {
    input_format = FORMAT_WAV;
    pcm_freq = -1;        // not yet determined
    pcm_channels = -1;    // not yet determined
  } else {
    printf("error: unknown format file (%s).\n", input_file_name);
    goto exit;
  }

  // init raw pcm decoder if needed
  if (input_format == FORMAT_RAW) {
    if (raw_decode_open(&raw_decoder, pcm_freq, pcm_channels, volume) != 0) {
      printf("error: PCM decoder initialization error.\n");
      goto exit;
    }
  }

  // init wav decoder if needed
  if (input_format == FORMAT_WAV) {
    if (wav_decode_open(&wav_decoder, volume) != 0) {
      printf("error: WAV decoder initialization error.\n");
      goto exit;
    }
  }

  // open input file
  fp = fopen(input_file_name, "rb");
  if (fp == NULL) {
    printf("error: input file open error. (%s)\n", input_file_name);
    goto exit;
  }

  // read header part of WAV file
  size_t skip_offset = 0;
  if (input_format == FORMAT_WAV) {
    int32_t ofs = wav_decode_parse_header(&wav_decoder, fp);
    if (ofs < 0) {
      printf("error: wav header parse error.\n");
      goto exit;
    }
    pcm_freq = wav_decoder.sample_rate;
    pcm_channels = wav_decoder.channels;
    skip_offset = ofs;
  }

  // check file size
  fseek(fp, 0, SEEK_END);
  size_t pcm_data_size = ftell(fp) - skip_offset;
  fseek(fp, skip_offset, SEEK_SET);

  // init adpcm (ym2608) encoder
  if (ym2608_encode_open(&ym2608_encoder, pcm_freq, pcm_channels) != 0) {
    printf("error: YM2608 adpcm encoder initialization error.\n");
    goto exit;
  }

  // check output file format
  char* output_file_ext = output_file_name + strlen(output_file_name) - 4;
  if ((pcm_channels == 1 && output_file_ext[1] != 'n' && output_file_ext[1] != 'N') ||
      (pcm_channels == 2 && output_file_ext[1] != 'a' && output_file_ext[1] != 'A') ||
      (pcm_freq == 32000 && memcmp(output_file_ext + 2, "32", 2) != 0) ||
      (pcm_freq == 44100 && memcmp(output_file_ext + 2, "44", 2) != 0) ||
      (pcm_freq == 48000 && memcmp(output_file_ext + 2, "48", 2) != 0)) {
        printf("error: output file extension name (%s) is not as expected.\n", output_file_ext);
        goto exit;
      }

  // check output file
  fo = fopen(output_file_name, "rb");
  if (fo != NULL) {
    fclose(fo);
    fo = NULL;
    printf("warn: output file already exists. do you want to overwrite? (y/n)>");
    int16_t c = getchar();
    if (c != 'y' && c != 'Y') {
      printf("canceled.\n");
      goto exit;
    }
  }

  // open output file
  fo = fopen(output_file_name, "wb");
  if (fo == NULL) {
    printf("error: output file open error.\n");
    goto exit;
  }

  // describe PCM file information
  printf("File name     : %s\n", input_file_name);
  printf("Data size     : %zu [bytes]\n", pcm_data_size);
  printf("Data format   : %s\n", 
    input_format == FORMAT_WAV ? "WAV" :
    input_format == FORMAT_RAW ? "16bit signed raw PCM (big)" : "");

  // describe raw format
  if (input_format == FORMAT_RAW) {
    float pcm_1sec_size = pcm_freq * 2;
    printf("PCM frequency : %d [Hz]\n", pcm_freq);
    printf("PCM channels  : %s\n", pcm_channels == 1 ? "mono" : "stereo");
    printf("PCM length    : %4.2f [sec]\n", (float)pcm_data_size / pcm_channels / pcm_1sec_size);
  }

  // describe wav format
  if (input_format == FORMAT_WAV) {
    printf("PCM frequency : %d [Hz]\n", pcm_freq);
    printf("PCM channels  : %s\n", pcm_channels == 1 ? "mono" : "stereo");
    printf("PCM length    : %4.2f [sec]\n", (float)wav_decoder.duration / pcm_freq);
  }

  printf("\n");

  // allocate file read buffer
  size_t fread_buffer_len = pcm_channels * pcm_freq * 16;   // 16 sec
  fread_buffer = (int16_t*)malloc(sizeof(int16_t) * fread_buffer_len);
  
  // allocate pcm buffer
  size_t pcm_buffer_len = pcm_channels * pcm_freq * 16;   // 16 sec
  pcm_buffer = (int16_t*)malloc(sizeof(int16_t) * pcm_buffer_len);
  
  // allocate output adpcm buffer
  size_t output_buffer_len = pcm_buffer_len / 4;
  output_buffer = (uint8_t*)malloc(sizeof(uint8_t) * output_buffer_len);
  
  // sigint handler
  abort_flag = 0;
  signal(SIGINT, sigint_handler);

  // do conversion
  size_t fread_len = 0;

  do {
    size_t len = fread(fread_buffer, sizeof(int16_t), fread_buffer_len, fp);
    if (len == 0) break;
    fread_len += len;
    size_t decode_len =
      (input_format == FORMAT_RAW) ? 
        decode_len = raw_decode_exec(&raw_decoder, pcm_buffer, fread_buffer, len) :
      (input_format == FORMAT_WAV) ?
        decode_len = wav_decode_exec(&wav_decoder, pcm_buffer, fread_buffer, len) : 0;
//    printf("len=%zu, fread_len=%zu, decode_len=%zu\n", len, fread_len, decode_len);
    size_t output_len = ym2608_encode_exec(&ym2608_encoder, output_buffer, pcm_buffer, len);
    fwrite(output_buffer, sizeof(uint8_t), output_len, fo);
    printf("\r%zu/%zu (%4.2f%%)", fread_len * sizeof(int16_t), pcm_data_size, fread_len * sizeof(int16_t) * 100.0 / pcm_data_size);
    fflush(stdout);
  } while (fread_len * sizeof(int16_t) < pcm_data_size && abort_flag == 0);

  printf("\n");

  // close output file
  fclose(fo);
  fo = NULL;

  // close input file
  fclose(fp);
  fp = NULL;

  // aborted?
  if (abort_flag) {
    printf("aborted.\n");
    rc = 1;
  } else {
    rc = 0;
  }

exit:

  // close output file
  if (fo != NULL) {
    fclose(fo);
    fo = NULL;
  }

  // close input file
  if (fp != NULL) {
    fclose(fp);
    fp = NULL;
  }

  // reclaim output buffer
  if (output_buffer != NULL) {
    free(output_buffer);
    output_buffer = NULL;
  }

  // reclaim pcm buffer
  if (pcm_buffer != NULL) {
    free(pcm_buffer);
    pcm_buffer = NULL;
  }

  // reclaim file read buffer
  if (fread_buffer != NULL) {
    free(fread_buffer);
    fread_buffer = NULL;
  }

  // close raw decoder
  raw_decode_close(&raw_decoder);

  // close wav decoder
  wav_decode_close(&wav_decoder);

  // close ym2608 encoder
  ym2608_encode_close(&ym2608_encoder);

  return rc;
}
