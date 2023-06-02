#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "wav_decode.h"

//
//  init wav decoder handle
//
int32_t wav_decode_open(WAV_DECODE_HANDLE* wav, int16_t volume) {

  int32_t rc = -1;

  wav->volume = volume;

  wav->sample_rate = -1;
  wav->channels = -1;

  wav->byte_rate = -1;
  wav->block_align = -1;
  wav->bits_per_sample = -1;
  wav->duration = -1;

  int16_t endian_check = 0xfffe;
  wav->little_endian = (((uint8_t*)(&endian_check))[0] == 0xfe) ? 1 : 0;

  rc = 0;

exit:
  return rc;
}

//
//  close decoder handle
//
void wav_decode_close(WAV_DECODE_HANDLE* wav) {

}

//
//  parse wav header
//
int32_t wav_decode_parse_header(WAV_DECODE_HANDLE* wav, FILE* fp) {

  int32_t rc = -1;
  size_t bytes_read = 0;

  // ChunkID
  char buf[5];
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  buf[4] = '\0';
  if (strcmp(buf, "RIFF") != 0) {
    printf("error: incorrect wav format.\n");
    goto exit;
  }
//  printf("chunkID ok. %d\n", bytes_read);

  // ChunkSize
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
//  printf("chunk size ok. %d\n", bytes_read);

  // Format
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  buf[4] = '\0';
  if (strcmp(buf, "WAVE") != 0) {
    printf("error: incorrect wav format.\n");
    goto exit;
  }
//  printf("format ok. %d\n", bytes_read);

  // Subchunk1ID
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  buf[4] = '\0';
//  printf("sub chunk1 ID ok. %d\n", bytes_read);

  // check if we have a JUNK Chunk
  if (strcmp(buf, "JUNK") == 0) {
    size_t bytes_junk = fread(buf, sizeof(uint8_t), 4, fp);
    buf[4] = '\0';
    bytes_junk += buf[0] + (buf[1] << 8) + (buf[2] << 16) + (buf[3] << 24);
   if (fseek(fp, bytes_read + bytes_junk, SEEK_SET) != 0) {
      printf("error: wav seek error.\n");
      goto exit;
    }
    bytes_read += bytes_junk;
//    bytes_expected += bytes_junk + 4;
    // now really read the fmt chunk
    bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
    buf[4] = '\0';
  }
//  printf("junk ok. %d\n", bytes_read);

  // get the fmt chunk
  if (strcmp(buf, "fmt ") != 0) {
    printf("error: wav fmt chunk read error.\n");
    goto exit;
  }
//  printf("fmt ok. %d\n", bytes_read);

  // Subchunk1Size
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  int16_t format = buf[0];
  if (format != 16 && format != 18) {
    printf("error: wav unknown format (%d).\n", format);
    goto exit;
  }
  if (buf[1] != 0 || buf[2] != 0 || buf[3] != 0) {
    printf("error: wav Subchunk1Size error.\n");
    goto exit;
  }
//  printf("sub chunk1 size ok. %d\n", bytes_read);

  // AudioFormat
  bytes_read += fread(buf, sizeof(uint8_t), 2, fp);
  if (buf[0] != 1 || buf[1] != 0) {
    printf("error: wav AudioFormat error.\n");
    goto exit;
  }
//  printf("audio fmt ok. %d\n", bytes_read);

  // NumChannels
  bytes_read += fread(buf, sizeof(uint8_t), 2, fp);
  wav->channels = (uint8_t)buf[0] + ((uint8_t)buf[1] << 8);
  if (wav->channels != 1 && wav->channels != 2) {
    printf("error: wav unsupported channels (%d).\n", wav->channels);
    goto exit;
  }
//  printf("num channels ok. %d\n", bytes_read);

  // SampleRate
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  wav->sample_rate = buf[0] + ((uint8_t)buf[1] << 8) + ((uint8_t)buf[2] << 16) + ((uint8_t)buf[3] << 24);
  if (wav->sample_rate != 32000 && wav->sample_rate != 44100 && wav->sample_rate != 48000) {
    printf("error: wav unsupported sample rate (%d).\n", wav->sample_rate);
    goto exit;
  }
//  printf("sample rate ok. %d\n", bytes_read);

  // ByteRate
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  wav->byte_rate = (uint8_t)buf[0] + ((uint8_t)buf[1] <<8) + ((uint8_t)buf[2] << 16) + ((uint8_t)buf[3] << 24);
//  printf("byte rate ok. %d\n", bytes_read);

  // BlockAlign
  bytes_read += fread(buf, sizeof(uint8_t), 2, fp);
  wav->block_align = (uint8_t)buf[0] + ((uint8_t)buf[1] << 8);
//  printf("block align ok. %d\n", bytes_read);

  // BitsPerSample
  bytes_read += fread(buf, sizeof(uint8_t), 2, fp);
  wav->bits_per_sample = (uint8_t)buf[0] + ((uint8_t)buf[1] << 8);
  if (wav->bits_per_sample != 16) {
    printf("error: wav unsupported bit per sample (%d).\n", wav->bits_per_sample);
    goto exit;
  }
//  printf("bit per sample ok. %d\n", bytes_read);

  // skip 2 bytes if format is 18
  if (format == 18) {
    bytes_read += fread(buf, sizeof(uint8_t), 2, fp);
  }
//  printf("format 18 ok. %d\n", bytes_read);

  // Subchunk2ID
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  buf[4] = '\0';
  while (strcmp(buf, "data") != 0) {
    if (feof(fp) || ferror(fp)) {
      printf("error: wav Shubchunk2 read error.\n");
      goto exit;
    }
    size_t bytes_junk = fread(buf, sizeof(uint8_t), 4, fp);
    buf[4] = '\0';
    bytes_junk += (uint8_t)buf[0] + ((uint8_t)buf[1] << 8) + ((uint8_t)buf[2] << 16) + ((uint8_t)buf[3] << 24);
    if (fseek(fp, bytes_read + bytes_junk, SEEK_SET) != 0) {
      printf("error: wav seek error.\n");
      goto exit;
    }
    bytes_read += bytes_junk;
    //bytes_expected += bytes_junk+ 4;
    bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
    buf[4] = '\0';
  }
//  printf("sub chunk2 id ok. %d\n", bytes_read);

  // Subchunk2Size
  bytes_read += fread(buf, sizeof(uint8_t), 4, fp);
  wav->duration = ((uint8_t)buf[0] + ((uint8_t)buf[1]<<8) + ((uint8_t)buf[2]<<16) + ((uint8_t)buf[3]<<24)) / wav->block_align;
//  printf("sub chunk 2 size ok. %d\n", bytes_read);

  rc = (int32_t)bytes_read;

exit:
  return rc;
}

//
//  decode
//
size_t wav_decode_exec(WAV_DECODE_HANDLE* wav, int16_t* output_buffer, int16_t* source_buffer, size_t source_buffer_len) {

  size_t source_buffer_ofs = 0;
  size_t output_buffer_ofs = 0;

  if (wav->volume != 100) {
    if (wav->little_endian) {
      uint8_t* output_buffer_uint8 = (uint8_t*)output_buffer;
      while (source_buffer_ofs < source_buffer_len) {
        int16_t value = source_buffer[ source_buffer_ofs ++ ];
        int32_t value32 = (int32_t)value * wav->volume / 100.0;
        value32 = (value32 > 32768) ? 32768 : (value32 < -32768) ? -32768 : value32;
        output_buffer_uint8[ output_buffer_ofs * 2 + 0 ] = ((uint8_t*)(&value32))[1];
        output_buffer_uint8[ output_buffer_ofs * 2 + 1 ] = ((uint8_t*)(&value32))[0];
        output_buffer_ofs++;
      }
    } else {
      uint8_t* source_buffer_uint8 = (uint8_t*)source_buffer;
      while (source_buffer_ofs < source_buffer_len) {
        int16_t value;
        ((uint8_t*)(&value))[0] = source_buffer_uint8[ source_buffer_ofs * 2 + 1 ];
        ((uint8_t*)(&value))[1] = source_buffer_uint8[ source_buffer_ofs * 2 + 0 ];
        int32_t value32 = (int32_t)value * wav->volume / 100.0;
        value32 = (value32 > 32768) ? 32768 : (value32 < -32768) ? -32768 : value32;
        output_buffer[ output_buffer_ofs ++ ] = (int16_t)value32;
      }
    }
  } else {
    if (wav->little_endian) {
      uint8_t* output_buffer_uint8 = (uint8_t*)output_buffer;
      while (source_buffer_ofs < source_buffer_len) {
        int16_t value = source_buffer[ source_buffer_ofs ++ ];
        output_buffer_uint8[ output_buffer_ofs * 2 + 0 ] = ((uint8_t*)(&value))[1];
        output_buffer_uint8[ output_buffer_ofs * 2 + 1 ] = ((uint8_t*)(&value))[0];
        output_buffer_ofs++;
      }
    } else {
      uint8_t* source_buffer_uint8 = (uint8_t*)source_buffer;
      while (source_buffer_ofs < source_buffer_len) {
        int16_t value;
        ((uint8_t*)(&value))[0] = source_buffer_uint8[ source_buffer_ofs * 2 + 1 ];
        ((uint8_t*)(&value))[1] = source_buffer_uint8[ source_buffer_ofs * 2 + 0 ];
        output_buffer[ output_buffer_ofs ++ ] = (int16_t)value;
      }
    }
  }

  return output_buffer_ofs;
}
