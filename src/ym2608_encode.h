#ifndef __H_YM2608_ENCODE__
#define __H_YM2608_ENCODE__

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct {

  int32_t sample_rate;
  int16_t channels;

  uint8_t* ra;
  uint8_t* la;

  int16_t ry;
  int16_t ly;

} YM2608_ENCODE_HANDLE;

int32_t ym2608_encode_open(YM2608_ENCODE_HANDLE* ym2608, int32_t sample_rate, int16_t channels);
void ym2608_encode_close(YM2608_ENCODE_HANDLE* ym2608);
size_t ym2608_encode_exec(YM2608_ENCODE_HANDLE* ym2608, uint8_t* output_buffer, int16_t* source_buffer, size_t source_buffer_len);

extern uint8_t ym2608_ptoa_conv_table[];

#endif