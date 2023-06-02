#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "raw_decode.h"

//
//  init raw pcm decoder handle
//
int32_t raw_decode_open(RAW_DECODE_HANDLE* pcm, int32_t sample_rate, int16_t channels, int16_t volume) {

  int32_t rc = -1;

  pcm->sample_rate = sample_rate;
  pcm->channels = channels;
  pcm->volume = volume;

  int16_t endian_check = 0xfffe;
  pcm->little_endian = (((uint8_t*)(&endian_check))[0] == 0xfe) ? 1 : 0;

  rc = 0;

exit:
  return rc;
}

//
//  close decoder handle
//
void raw_decode_close(RAW_DECODE_HANDLE* pcm) {

}

//
//  decode
//
size_t raw_decode_exec(RAW_DECODE_HANDLE* pcm, int16_t* output_buffer, int16_t* source_buffer, size_t source_buffer_len) {

  size_t source_buffer_ofs = 0;
  size_t output_buffer_ofs = 0;

  if (pcm->volume != 100) {
    if (pcm->little_endian) {
      uint8_t* output_buffer_uint8 = (uint8_t*)output_buffer;
      uint8_t* source_buffer_uint8 = (uint8_t*)source_buffer;
      while (source_buffer_ofs < source_buffer_len) {
        int16_t value;
        ((uint8_t*)(&value))[0] = source_buffer_uint8[ source_buffer_ofs * 2 + 1 ];
        ((uint8_t*)(&value))[1] = source_buffer_uint8[ source_buffer_ofs * 2 + 0 ];
        int32_t value32 = (int32_t)value * pcm->volume / 100.0;
        value32 = (value32 > 32768) ? 32768 : (value32 < -32768) ? -32768 : value32;
        output_buffer_uint8[ output_buffer_ofs * 2 + 0 ] = ((uint8_t*)(&value32))[1];
        output_buffer_uint8[ output_buffer_ofs * 2 + 1 ] = ((uint8_t*)(&value32))[0];
        output_buffer_ofs++;
      }
    } else {
      while (source_buffer_ofs < source_buffer_len) {
        int16_t value = source_buffer[ source_buffer_ofs ++ ];
        int32_t value32 = (int32_t)value * pcm->volume / 100.0;
        value32 = (value32 > 32768) ? 32768 : (value32 < -32768) ? -32768 : value32;
        output_buffer[ output_buffer_ofs ++ ] = (int16_t)value32;
      }
    }
  } else {
    memcpy((uint8_t*)output_buffer, (uint8_t*)source_buffer, source_buffer_len * sizeof(int16_t));
    output_buffer_ofs = source_buffer_len;
  }

  return output_buffer_ofs;
}
