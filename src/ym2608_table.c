#include <stdint.h>
  
//
//  YM2608 PCM to ADPCM conversion table generated by adpcmlib.s for X680x0 (C)1995 Otankonas
//
  uint8_t ym2608_ptoa_conv_table[] = {
    0x00,0x04,0x00,0x08,0x00,0x0c,0x00,0x10,0x00,0x14,0x00,0x18,0x00,0x1c,0x00,0x10,
    0x00,0x02,0x00,0x06,0x00,0x0a,0x00,0x0e,0x00,0x12,0x00,0x16,0x00,0x1a,0x00,0x1e,
    0xff,0xfe,0xff,0xfa,0xff,0xf6,0xff,0xf2,0xff,0xee,0xff,0xea,0xff,0xe6,0xff,0xe2,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0xc6,0xff,0xc4,0xff,0xc2,0xff,0xc0,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x04,0x00,0x08,0x00,0x0c,0x00,0x11,0x00,0x15,0x00,0x19,0x00,0x1d,0x00,0x11,
    0x00,0x02,0x00,0x06,0x00,0x0a,0x00,0x0e,0x00,0x13,0x00,0x17,0x00,0x1b,0x00,0x1f,
    0xff,0xfd,0xff,0xf9,0xff,0xf5,0xff,0xf1,0xff,0xec,0xff,0xe8,0xff,0xe4,0xff,0xe0,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x04,0x00,0x09,0x00,0x0e,0x00,0x13,0x00,0x17,0x00,0x1c,0x00,0x21,0x00,0x13,
    0x00,0x02,0x00,0x07,0x00,0x0b,0x00,0x10,0x00,0x15,0x00,0x1a,0x00,0x1e,0x00,0x23,
    0xff,0xfd,0xff,0xf8,0xff,0xf4,0xff,0xef,0xff,0xea,0xff,0xe5,0xff,0xe1,0xff,0xdc,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x05,0x00,0x0a,0x00,0x0f,0x00,0x15,0x00,0x1a,0x00,0x1f,0x00,0x24,0x00,0x15,
    0x00,0x02,0x00,0x07,0x00,0x0d,0x00,0x12,0x00,0x17,0x00,0x1c,0x00,0x22,0x00,0x27,
    0xff,0xfd,0xff,0xf8,0xff,0xf2,0xff,0xed,0xff,0xe8,0xff,0xe3,0xff,0xdd,0xff,0xd8,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x05,0x00,0x0b,0x00,0x11,0x00,0x17,0x00,0x1c,0x00,0x22,0x00,0x28,0x00,0x17,
    0x00,0x02,0x00,0x08,0x00,0x0e,0x00,0x14,0x00,0x19,0x00,0x1f,0x00,0x25,0x00,0x2b,
    0xff,0xfd,0xff,0xf7,0xff,0xf1,0xff,0xeb,0xff,0xe6,0xff,0xe0,0xff,0xda,0xff,0xd4,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x06,0x00,0x0c,0x00,0x12,0x00,0x19,0x00,0x1f,0x00,0x25,0x00,0x2b,0x00,0x19,
    0x00,0x03,0x00,0x09,0x00,0x0f,0x00,0x15,0x00,0x1c,0x00,0x22,0x00,0x28,0x00,0x2e,
    0xff,0xfc,0xff,0xf6,0xff,0xf0,0xff,0xea,0xff,0xe3,0xff,0xdd,0xff,0xd7,0xff,0xd1,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x07,0x00,0x0e,0x00,0x15,0x00,0x1c,0x00,0x23,0x00,0x2a,0x00,0x31,0x00,0x1c,
    0x00,0x03,0x00,0x0a,0x00,0x11,0x00,0x18,0x00,0x1f,0x00,0x26,0x00,0x2d,0x00,0x34,
    0xff,0xfc,0xff,0xf5,0xff,0xee,0xff,0xe7,0xff,0xe0,0xff,0xd9,0xff,0xd2,0xff,0xcb,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x07,0x00,0x0f,0x00,0x17,0x00,0x1f,0x00,0x26,0x00,0x2e,0x00,0x36,0x00,0x1f,
    0x00,0x03,0x00,0x0b,0x00,0x13,0x00,0x1b,0x00,0x22,0x00,0x2a,0x00,0x32,0x00,0x3a,
    0xff,0xfc,0xff,0xf4,0xff,0xec,0xff,0xe4,0xff,0xdd,0xff,0xd5,0xff,0xcd,0xff,0xc5,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x08,0x00,0x11,0x00,0x19,0x00,0x22,0x00,0x2a,0x00,0x33,0x00,0x3b,0x00,0x22,
    0x00,0x04,0x00,0x0c,0x00,0x15,0x00,0x1d,0x00,0x26,0x00,0x2e,0x00,0x37,0x00,0x3f,
    0xff,0xfb,0xff,0xf3,0xff,0xea,0xff,0xe2,0xff,0xd9,0xff,0xd1,0xff,0xc8,0xff,0xc0,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x09,0x00,0x12,0x00,0x1b,0x00,0x25,0x00,0x2e,0x00,0x37,0x00,0x40,0x00,0x25,
    0x00,0x04,0x00,0x0d,0x00,0x17,0x00,0x20,0x00,0x29,0x00,0x32,0x00,0x3c,0x00,0x45,
    0xff,0xfb,0xff,0xf2,0xff,0xe8,0xff,0xdf,0xff,0xd6,0xff,0xcd,0xff,0xc3,0xff,0xba,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x0a,0x00,0x14,0x00,0x1e,0x00,0x29,0x00,0x33,0x00,0x3d,0x00,0x47,0x00,0x29,
    0x00,0x05,0x00,0x0f,0x00,0x19,0x00,0x23,0x00,0x2e,0x00,0x38,0x00,0x42,0x00,0x4c,
    0xff,0xfa,0xff,0xf0,0xff,0xe6,0xff,0xdc,0xff,0xd1,0xff,0xc7,0xff,0xbd,0xff,0xb3,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x0b,0x00,0x16,0x00,0x21,0x00,0x2d,0x00,0x38,0x00,0x43,0x00,0x4e,0x00,0x2d,
    0x00,0x05,0x00,0x10,0x00,0x1c,0x00,0x27,0x00,0x32,0x00,0x3d,0x00,0x49,0x00,0x54,
    0xff,0xfa,0xff,0xef,0xff,0xe3,0xff,0xd8,0xff,0xcd,0xff,0xc2,0xff,0xb6,0xff,0xab,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x0c,0x00,0x19,0x00,0x25,0x00,0x32,0x00,0x3e,0x00,0x4b,0x00,0x57,0x00,0x32,
    0x00,0x06,0x00,0x12,0x00,0x1f,0x00,0x2b,0x00,0x38,0x00,0x44,0x00,0x51,0x00,0x5d,
    0xff,0xf9,0xff,0xed,0xff,0xe0,0xff,0xd4,0xff,0xc7,0xff,0xbb,0xff,0xae,0xff,0xa2,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x0d,0x00,0x1b,0x00,0x29,0x00,0x37,0x00,0x44,0x00,0x52,0x00,0x60,0x00,0x37,
    0x00,0x06,0x00,0x14,0x00,0x22,0x00,0x30,0x00,0x3d,0x00,0x4b,0x00,0x59,0x00,0x67,
    0xff,0xf9,0xff,0xeb,0xff,0xdd,0xff,0xcf,0xff,0xc2,0xff,0xb4,0xff,0xa6,0xff,0x98,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x0f,0x00,0x1e,0x00,0x2d,0x00,0x3c,0x00,0x4b,0x00,0x5a,0x00,0x69,0x00,0x3c,
    0x00,0x07,0x00,0x16,0x00,0x25,0x00,0x34,0x00,0x43,0x00,0x52,0x00,0x61,0x00,0x70,
    0xff,0xf8,0xff,0xe9,0xff,0xda,0xff,0xcb,0xff,0xbc,0xff,0xad,0xff,0x9e,0xff,0x8f,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x10,0x00,0x21,0x00,0x31,0x00,0x42,0x00,0x52,0x00,0x63,0x00,0x73,0x00,0x42,
    0x00,0x08,0x00,0x18,0x00,0x29,0x00,0x39,0x00,0x4a,0x00,0x5a,0x00,0x6b,0x00,0x7b,
    0xff,0xf7,0xff,0xe7,0xff,0xd6,0xff,0xc6,0xff,0xb5,0xff,0xa5,0xff,0x94,0xff,0x84,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x12,0x00,0x24,0x00,0x36,0x00,0x49,0x00,0x5b,0x00,0x6d,0x00,0x7f,0x00,0x49,
    0x00,0x09,0x00,0x1b,0x00,0x2d,0x00,0x3f,0x00,0x52,0x00,0x64,0x00,0x76,0x00,0x88,
    0xff,0xf6,0xff,0xe4,0xff,0xd2,0xff,0xc0,0xff,0xad,0xff,0x9b,0xff,0x89,0xff,0x77,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x14,0x00,0x28,0x00,0x3c,0x00,0x50,0x00,0x64,0x00,0x78,0x00,0x8c,0x00,0x50,
    0x00,0x0a,0x00,0x1e,0x00,0x32,0x00,0x46,0x00,0x5a,0x00,0x6e,0x00,0x82,0x00,0x96,
    0xff,0xf6,0xff,0xe2,0xff,0xce,0xff,0xba,0xff,0xa6,0xff,0x92,0xff,0x7e,0xff,0x6a,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x16,0x00,0x2c,0x00,0x42,0x00,0x58,0x00,0x6e,0x00,0x84,0x00,0x9a,0x00,0x58,
    0x00,0x0b,0x00,0x21,0x00,0x37,0x00,0x4d,0x00,0x63,0x00,0x79,0x00,0x8f,0x00,0xa5,
    0xff,0xf5,0xff,0xdf,0xff,0xc9,0xff,0xb3,0xff,0x9d,0xff,0x87,0xff,0x71,0xff,0x5b,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x18,0x00,0x30,0x00,0x48,0x00,0x61,0x00,0x79,0x00,0x91,0x00,0xa9,0x00,0x61,
    0x00,0x0c,0x00,0x24,0x00,0x3c,0x00,0x54,0x00,0x6d,0x00,0x85,0x00,0x9d,0x00,0xb5,
    0xff,0xf3,0xff,0xdb,0xff,0xc3,0xff,0xab,0xff,0x92,0xff,0x7a,0xff,0x62,0xff,0x4a,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x1a,0x00,0x35,0x00,0x50,0x00,0x6b,0x00,0x85,0x00,0xa0,0x00,0xbb,0x00,0x6b,
    0x00,0x0d,0x00,0x28,0x00,0x42,0x00,0x5d,0x00,0x78,0x00,0x93,0x00,0xad,0x00,0xc8,
    0xff,0xf2,0xff,0xd7,0xff,0xbd,0xff,0xa2,0xff,0x87,0xff,0x6c,0xff,0x52,0xff,0x37,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x1d,0x00,0x3b,0x00,0x58,0x00,0x76,0x00,0x93,0x00,0xb1,0x00,0xce,0x00,0x76,
    0x00,0x0e,0x00,0x2c,0x00,0x49,0x00,0x67,0x00,0x84,0x00,0xa2,0x00,0xbf,0x00,0xdd,
    0xff,0xf1,0xff,0xd3,0xff,0xb6,0xff,0x98,0xff,0x7b,0xff,0x5d,0xff,0x40,0xff,0x22,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x20,0x00,0x41,0x00,0x61,0x00,0x82,0x00,0xa2,0x00,0xc3,0x00,0xe3,0x00,0x82,
    0x00,0x10,0x00,0x30,0x00,0x51,0x00,0x71,0x00,0x92,0x00,0xb2,0x00,0xd3,0x00,0xf3,
    0xff,0xef,0xff,0xcf,0xff,0xae,0xff,0x8e,0xff,0x6d,0xff,0x4d,0xff,0x2c,0xff,0x0c,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x23,0x00,0x47,0x00,0x6b,0x00,0x8f,0x00,0xb2,0x00,0xd6,0x00,0xfa,0x00,0x8f,
    0x00,0x11,0x00,0x35,0x00,0x59,0x00,0x7d,0x00,0xa0,0x00,0xc4,0x00,0xe8,0x01,0x0c,
    0xff,0xee,0xff,0xca,0xff,0xa6,0xff,0x82,0xff,0x5f,0xff,0x3b,0xff,0x17,0xfe,0xf3,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x27,0x00,0x4e,0x00,0x75,0x00,0x9d,0x00,0xc4,0x00,0xeb,0x01,0x12,0x00,0x9d,
    0x00,0x13,0x00,0x3a,0x00,0x62,0x00,0x89,0x00,0xb0,0x00,0xd7,0x00,0xff,0x01,0x26,
    0xff,0xec,0xff,0xc5,0xff,0x9d,0xff,0x76,0xff,0x4f,0xff,0x28,0xff,0x00,0xfe,0xd9,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x2b,0x00,0x56,0x00,0x81,0x00,0xad,0x00,0xd8,0x01,0x03,0x01,0x2e,0x00,0xad,
    0x00,0x15,0x00,0x40,0x00,0x6c,0x00,0x97,0x00,0xc2,0x00,0xed,0x01,0x19,0x01,0x44,
    0xff,0xea,0xff,0xbf,0xff,0x93,0xff,0x68,0xff,0x3d,0xff,0x12,0xfe,0xe6,0xfe,0xbb,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x2f,0x00,0x5f,0x00,0x8e,0x00,0xbe,0x00,0xed,0x01,0x1d,0x01,0x4c,0x00,0xbe,
    0x00,0x17,0x00,0x47,0x00,0x76,0x00,0xa6,0x00,0xd5,0x01,0x05,0x01,0x34,0x01,0x64,
    0xff,0xe8,0xff,0xb8,0xff,0x89,0xff,0x59,0xff,0x2a,0xfe,0xfa,0xfe,0xcb,0xfe,0x9b,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x34,0x00,0x68,0x00,0x9c,0x00,0xd1,0x01,0x05,0x01,0x39,0x01,0x6d,0x00,0xd1,
    0x00,0x1a,0x00,0x4e,0x00,0x82,0x00,0xb6,0x00,0xeb,0x01,0x1f,0x01,0x53,0x01,0x87,
    0xff,0xe5,0xff,0xb1,0xff,0x7d,0xff,0x49,0xff,0x14,0xfe,0xe0,0xfe,0xac,0xfe,0x78,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x39,0x00,0x73,0x00,0xac,0x00,0xe6,0x01,0x1f,0x01,0x59,0x01,0x92,0x00,0xe6,
    0x00,0x1c,0x00,0x56,0x00,0x8f,0x00,0xc9,0x01,0x02,0x01,0x3c,0x01,0x75,0x01,0xaf,
    0xff,0xe3,0xff,0xa9,0xff,0x70,0xff,0x36,0xfe,0xfd,0xfe,0xc3,0xfe,0x8a,0xfe,0x50,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x3f,0x00,0x7e,0x00,0xbd,0x00,0xfd,0x01,0x3c,0x01,0x7b,0x01,0xba,0x00,0xfd,
    0x00,0x1f,0x00,0x5e,0x00,0x9e,0x00,0xdd,0x01,0x1c,0x01,0x5b,0x01,0x9b,0x01,0xda,
    0xff,0xe0,0xff,0xa1,0xff,0x61,0xff,0x22,0xfe,0xe3,0xfe,0xa4,0xfe,0x64,0xfe,0x25,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x45,0x00,0x8b,0x00,0xd1,0x01,0x17,0x01,0x5c,0x01,0xa2,0x01,0xe8,0x01,0x17,
    0x00,0x22,0x00,0x68,0x00,0xae,0x00,0xf4,0x01,0x39,0x01,0x7f,0x01,0xc5,0x02,0x0b,
    0xff,0xdd,0xff,0x97,0xff,0x51,0xff,0x0b,0xfe,0xc6,0xfe,0x80,0xfe,0x3a,0xfd,0xf4,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x4c,0x00,0x99,0x00,0xe6,0x01,0x33,0x01,0x7f,0x01,0xcc,0x02,0x19,0x01,0x33,
    0x00,0x26,0x00,0x73,0x00,0xbf,0x01,0x0c,0x01,0x59,0x01,0xa6,0x01,0xf2,0x02,0x3f,
    0xff,0xd9,0xff,0x8c,0xff,0x40,0xfe,0xf3,0xfe,0xa6,0xfe,0x59,0xfe,0x0d,0xfd,0xc0,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x54,0x00,0xa8,0x00,0xfc,0x01,0x51,0x01,0xa5,0x01,0xf9,0x02,0x4d,0x01,0x51,
    0x00,0x2a,0x00,0x7e,0x00,0xd2,0x01,0x26,0x01,0x7b,0x01,0xcf,0x02,0x23,0x02,0x77,
    0xff,0xd5,0xff,0x81,0xff,0x2d,0xfe,0xd9,0xfe,0x84,0xfe,0x30,0xfd,0xdc,0xfd,0x88,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x5c,0x00,0xb9,0x01,0x16,0x01,0x73,0x01,0xcf,0x02,0x2c,0x02,0x89,0x01,0x73,
    0x00,0x2e,0x00,0x8b,0x00,0xe7,0x01,0x44,0x01,0xa1,0x01,0xfe,0x02,0x5a,0x02,0xb7,
    0xff,0xd1,0xff,0x74,0xff,0x18,0xfe,0xbb,0xfe,0x5e,0xfe,0x01,0xfd,0xa5,0xfd,0x48,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x66,0x00,0xcc,0x01,0x32,0x01,0x98,0x01,0xfe,0x02,0x64,0x02,0xca,0x01,0x98,
    0x00,0x33,0x00,0x99,0x00,0xff,0x01,0x65,0x01,0xcb,0x02,0x31,0x02,0x97,0x02,0xfd,
    0xff,0xcd,0xff,0x67,0xff,0x01,0xfe,0x9b,0xfe,0x35,0xfd,0xcf,0xfd,0x69,0xfd,0x03,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x70,0x00,0xe0,0x01,0x50,0x01,0xc1,0x02,0x31,0x02,0xa1,0x03,0x11,0x01,0xc1,
    0x00,0x38,0x00,0xa8,0x01,0x18,0x01,0x88,0x01,0xf9,0x02,0x69,0x02,0xd9,0x03,0x49,
    0xff,0xc7,0xff,0x57,0xfe,0xe7,0xfe,0x77,0xfe,0x06,0xfd,0x96,0xfd,0x26,0xfc,0xb6,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x7b,0x00,0xf7,0x01,0x72,0x01,0xee,0x02,0x69,0x02,0xe5,0x03,0x60,0x01,0xee,
    0x00,0x3d,0x00,0xb9,0x01,0x34,0x01,0xb0,0x02,0x2b,0x02,0xa7,0x03,0x22,0x03,0x9e,
    0xff,0xc2,0xff,0x46,0xfe,0xcb,0xfe,0x4f,0xfd,0xd4,0xfd,0x58,0xfc,0xdd,0xfc,0x61,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x88,0x01,0x10,0x01,0x98,0x02,0x20,0x02,0xa8,0x03,0x30,0x03,0xb8,0x02,0x20,
    0x00,0x44,0x00,0xcc,0x01,0x54,0x01,0xdc,0x02,0x64,0x02,0xec,0x03,0x74,0x03,0xfc,
    0xff,0xbc,0xff,0x34,0xfe,0xac,0xfe,0x24,0xfd,0x9c,0xfd,0x14,0xfc,0x8c,0xfc,0x04,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0x95,0x01,0x2b,0x01,0xc0,0x02,0x56,0x02,0xeb,0x03,0x81,0x04,0x16,0x02,0x56,
    0x00,0x4a,0x00,0xe0,0x01,0x75,0x02,0x0b,0x02,0xa0,0x03,0x36,0x03,0xcb,0x04,0x61,
    0xff,0xb5,0xff,0x1f,0xfe,0x8a,0xfd,0xf4,0xfd,0x5f,0xfc,0xc9,0xfc,0x34,0xfb,0x9e,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0xa4,0x01,0x49,0x01,0xed,0x02,0x92,0x03,0x36,0x03,0xdb,0x04,0x7f,0x02,0x92,
    0x00,0x52,0x00,0xf6,0x01,0x9b,0x02,0x3f,0x02,0xe4,0x03,0x88,0x04,0x2d,0x04,0xd1,
    0xff,0xad,0xff,0x09,0xfe,0x64,0xfd,0xc0,0xfd,0x1b,0xfc,0x77,0xfb,0xd2,0xfb,0x2e,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0xb5,0x01,0x6a,0x02,0x1f,0x02,0xd4,0x03,0x89,0x04,0x3e,0x04,0xf3,0x02,0xd4,
    0x00,0x5a,0x01,0x0f,0x01,0xc4,0x02,0x79,0x03,0x2e,0x03,0xe3,0x04,0x98,0x05,0x4d,
    0xff,0xa5,0xfe,0xf0,0xfe,0x3b,0xfd,0x86,0xfc,0xd1,0xfc,0x1c,0xfb,0x67,0xfa,0xb2,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0xc7,0x01,0x8e,0x02,0x55,0x03,0x1c,0x03,0xe3,0x04,0xaa,0x05,0x71,0x03,0x1c,
    0x00,0x63,0x01,0x2a,0x01,0xf1,0x02,0xb8,0x03,0x7f,0x04,0x46,0x05,0x0d,0x05,0xd4,
    0xff,0x9c,0xfe,0xd5,0xfe,0x0e,0xfd,0x47,0xfc,0x80,0xfb,0xb9,0xfa,0xf2,0xfa,0x2b,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0xda,0x01,0xb5,0x02,0x90,0x03,0x6b,0x04,0x45,0x05,0x20,0x05,0xfb,0x03,0x6b,
    0x00,0x6d,0x01,0x48,0x02,0x22,0x02,0xfd,0x03,0xd8,0x04,0xb3,0x05,0x8d,0x06,0x68,
    0xff,0x92,0xfe,0xb7,0xfd,0xdd,0xfd,0x02,0xfc,0x27,0xfb,0x4c,0xfa,0x72,0xf9,0x97,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x00,0xf0,0x01,0xe1,0x02,0xd2,0x03,0xc3,0x04,0xb3,0x05,0xa4,0x06,0x95,0x03,0xc3,
    0x00,0x78,0x01,0x69,0x02,0x59,0x03,0x4a,0x04,0x3b,0x05,0x2c,0x06,0x1c,0x07,0x0d,
    0xff,0x87,0xfe,0x96,0xfd,0xa6,0xfc,0xb5,0xfb,0xc4,0xfa,0xd3,0xf9,0xe3,0xf8,0xf2,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x01,0x09,0x02,0x12,0x03,0x1b,0x04,0x24,0x05,0x2d,0x06,0x36,0x07,0x3f,0x04,0x24,
    0x00,0x84,0x01,0x8d,0x02,0x96,0x03,0x9f,0x04,0xa8,0x05,0xb1,0x06,0xba,0x07,0xc3,
    0xff,0x7b,0xfe,0x72,0xfd,0x69,0xfc,0x60,0xfb,0x57,0xfa,0x4e,0xf9,0x45,0xf8,0x3c,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x01,0x23,0x02,0x47,0x03,0x6a,0x04,0x8e,0x05,0xb1,0x06,0xd5,0x07,0xf8,0x04,0x8e,
    0x00,0x91,0x01,0xb5,0x02,0xd8,0x03,0xfc,0x05,0x1f,0x06,0x43,0x07,0x66,0x08,0x8a,
    0xff,0x6e,0xfe,0x4a,0xfd,0x27,0xfc,0x03,0xfa,0xe0,0xf9,0xbc,0xf8,0x99,0xf7,0x75,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x01,0x40,0x02,0x81,0x03,0xc1,0x05,0x02,0x06,0x42,0x07,0x83,0x08,0xc3,0x05,0x02,
    0x00,0xa0,0x01,0xe0,0x03,0x21,0x04,0x61,0x05,0xa2,0x06,0xe2,0x08,0x23,0x09,0x63,
    0xff,0x5f,0xfe,0x1f,0xfc,0xde,0xfb,0x9e,0xfa,0x5d,0xf9,0x1d,0xf7,0xdc,0xf6,0x9c,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x01,0x60,0x02,0xc1,0x04,0x22,0x05,0x83,0x06,0xe3,0x08,0x44,0x09,0xa5,0x05,0x83,
    0x00,0xb0,0x02,0x11,0x03,0x71,0x04,0xd2,0x06,0x33,0x07,0x94,0x08,0xf4,0x0a,0x55,
    0xff,0x4f,0xfd,0xee,0xfc,0x8e,0xfb,0x2d,0xf9,0xcc,0xf8,0x6b,0xf7,0x0b,0xf5,0xaa,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x01,0x84,0x03,0x08,0x04,0x8c,0x06,0x10,0x07,0x94,0x09,0x18,0x0a,0x9c,0x06,0x10,
    0x00,0xc2,0x02,0x46,0x03,0xca,0x05,0x4e,0x06,0xd2,0x08,0x56,0x09,0xda,0x0b,0x5e,
    0xff,0x3e,0xfd,0xba,0xfc,0x36,0xfa,0xb2,0xf9,0x2e,0xf7,0xaa,0xf6,0x26,0xf4,0xa2,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x01,0xaa,0x03,0x55,0x05,0x00,0x06,0xab,0x08,0x55,0x0a,0x00,0x0b,0xab,0x06,0xab,
    0x00,0xd5,0x02,0x80,0x04,0x2a,0x05,0xd5,0x07,0x80,0x09,0x2b,0x0a,0xd5,0x0c,0x80,
    0xff,0x2a,0xfd,0x7f,0xfb,0xd5,0xfa,0x2a,0xf8,0x7f,0xf6,0xd4,0xf5,0x2a,0xf3,0x7f,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x01,0xd5,0x03,0xaa,0x05,0x7f,0x07,0x55,0x09,0x2a,0x0a,0xff,0x0c,0xd4,0x07,0x55,
    0x00,0xea,0x02,0xbf,0x04,0x95,0x06,0x6a,0x08,0x3f,0x0a,0x14,0x0b,0xea,0x0d,0xbf,
    0xff,0x15,0xfd,0x40,0xfb,0x6a,0xf9,0x95,0xf7,0xc0,0xf5,0xeb,0xf4,0x15,0xf2,0x40,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x02,0x04,0x04,0x08,0x06,0x0c,0x08,0x11,0x0a,0x15,0x0c,0x19,0x0e,0x1d,0x08,0x11,
    0x01,0x02,0x03,0x06,0x05,0x0a,0x07,0x0e,0x09,0x13,0x0b,0x17,0x0d,0x1b,0x0f,0x1f,
    0xfe,0xfd,0xfc,0xf9,0xfa,0xf5,0xf8,0xf1,0xf6,0xec,0xf4,0xe8,0xf2,0xe4,0xf0,0xe0,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x02,0x38,0x04,0x70,0x06,0xa8,0x08,0xe0,0x0b,0x18,0x0d,0x50,0x0f,0x88,0x08,0xe0,
    0x01,0x1c,0x03,0x54,0x05,0x8c,0x07,0xc4,0x09,0xfc,0x0c,0x34,0x0e,0x6c,0x10,0xa4,
    0xfe,0xe4,0xfc,0xac,0xfa,0x74,0xf8,0x3c,0xf6,0x04,0xf3,0xcc,0xf1,0x94,0xef,0x5c,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x02,0x70,0x04,0xe1,0x07,0x52,0x09,0xc3,0x0c,0x33,0x0e,0xa4,0x11,0x15,0x09,0xc3,
    0x01,0x38,0x03,0xa9,0x06,0x19,0x08,0x8a,0x0a,0xfb,0x0d,0x6c,0x0f,0xdc,0x12,0x4d,
    0xfe,0xc7,0xfc,0x56,0xf9,0xe6,0xf7,0x75,0xf5,0x04,0xf2,0x93,0xf0,0x23,0xed,0xb2,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x02,0xaf,0x05,0x5e,0x08,0x0d,0x0a,0xbd,0x0d,0x6c,0x10,0x1b,0x12,0xca,0x0a,0xbd,
    0x01,0x57,0x04,0x06,0x06,0xb6,0x09,0x65,0x0c,0x14,0x0e,0xc3,0x11,0x73,0x14,0x22,
    0xfe,0xa8,0xfb,0xf9,0xf9,0x49,0xf6,0x9a,0xf3,0xeb,0xf1,0x3c,0xee,0x8c,0xeb,0xdd,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x02,0xf3,0x05,0xe7,0x08,0xdb,0x0b,0xcf,0x0e,0xc2,0x11,0xb6,0x14,0xaa,0x0b,0xcf,
    0x01,0x79,0x04,0x6d,0x07,0x61,0x0a,0x55,0x0d,0x48,0x10,0x3c,0x13,0x30,0x16,0x24,
    0xfe,0x86,0xfb,0x92,0xf8,0x9e,0xf5,0xaa,0xf2,0xb7,0xef,0xc3,0xec,0xcf,0xe9,0xdb,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x03,0x3f,0x06,0x7e,0x09,0xbd,0x0c,0xfd,0x10,0x3c,0x13,0x7b,0x16,0xba,0x0c,0xfd,
    0x01,0x9f,0x04,0xde,0x08,0x1e,0x0b,0x5d,0x0e,0x9c,0x11,0xdb,0x15,0x1b,0x18,0x5a,
    0xfe,0x60,0xfb,0x21,0xf7,0xe1,0xf4,0xa2,0xf1,0x63,0xee,0x24,0xea,0xe4,0xe7,0xa5,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x03,0x92,0x07,0x24,0x0a,0xb6,0x0e,0x49,0x11,0xdb,0x15,0x6d,0x18,0xff,0x0e,0x49,
    0x01,0xc9,0x05,0x5b,0x08,0xed,0x0c,0x7f,0x10,0x12,0x13,0xa4,0x17,0x36,0x1a,0xc8,
    0xfe,0x36,0xfa,0xa4,0xf7,0x12,0xf3,0x80,0xef,0xed,0xec,0x5b,0xe8,0xc9,0xe5,0x37,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x03,0xed,0x07,0xdb,0x0b,0xc8,0x0f,0xb6,0x13,0xa3,0x17,0x91,0x1b,0x7e,0x0f,0xb6,
    0x01,0xf6,0x05,0xe4,0x09,0xd1,0x0d,0xbf,0x11,0xac,0x15,0x9a,0x19,0x87,0x1d,0x75,
    0xfe,0x09,0xfa,0x1b,0xf6,0x2e,0xf2,0x40,0xee,0x53,0xea,0x65,0xe6,0x78,0xe2,0x8a,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x04,0x52,0x08,0xa4,0x0c,0xf6,0x11,0x48,0x15,0x9a,0x19,0xec,0x1e,0x3e,0x11,0x48,
    0x02,0x29,0x06,0x7b,0x0a,0xcd,0x0f,0x1f,0x13,0x71,0x17,0xc3,0x1c,0x15,0x20,0x67,
    0xfd,0xd7,0xf9,0x85,0xf5,0x33,0xf0,0xe1,0xec,0x8f,0xe8,0x3d,0xe3,0xeb,0xdf,0x99,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x04,0xc0,0x09,0x81,0x0e,0x41,0x13,0x02,0x17,0xc2,0x1c,0x83,0x21,0x43,0x13,0x02,
    0x02,0x60,0x07,0x20,0x0b,0xe1,0x10,0xa1,0x15,0x62,0x1a,0x22,0x1e,0xe3,0x23,0xa3,
    0xfd,0x9f,0xf8,0xdf,0xf4,0x1e,0xef,0x5e,0xea,0x9d,0xe5,0xdd,0xe1,0x1c,0xdc,0x5c,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x02,0x38,
    0x05,0x3a,0x0a,0x74,0x0f,0xae,0x14,0xe8,0x1a,0x22,0x1f,0x5c,0x24,0x96,0x14,0xe8,
    0x02,0x9d,0x07,0xd7,0x0d,0x11,0x12,0x4b,0x17,0x85,0x1c,0xbf,0x21,0xf9,0x27,0x33,
    0xfd,0x63,0xf8,0x29,0xf2,0xef,0xed,0xb5,0xe8,0x7b,0xe3,0x41,0xde,0x07,0xd8,0xcd,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x01,0xe8,
    0x05,0xbf,0x0b,0x7f,0x11,0x3f,0x16,0xff,0x1c,0xbe,0x22,0x7e,0x28,0x3e,0x16,0xff,
    0x02,0xdf,0x08,0x9f,0x0e,0x5f,0x14,0x1f,0x19,0xde,0x1f,0x9e,0x25,0x5e,0x2b,0x1e,
    0xfd,0x20,0xf7,0x60,0xf1,0xa0,0xeb,0xe0,0xe6,0x21,0xe0,0x61,0xda,0xa1,0xd4,0xe1,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x9a,0x01,0x98,
    0x06,0x52,0x0c,0xa5,0x12,0xf8,0x19,0x4b,0x1f,0x9d,0x25,0xf0,0x2c,0x43,0x19,0x4b,
    0x03,0x29,0x09,0x7c,0x0f,0xce,0x16,0x21,0x1c,0x74,0x22,0xc7,0x29,0x19,0x2f,0x6c,
    0xfc,0xd6,0xf6,0x83,0xf0,0x31,0xe9,0xde,0xe3,0x8b,0xdd,0x38,0xd6,0xe6,0xd0,0x93,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x01,0x4a,0x01,0x48,
    0x06,0xf4,0x0d,0xe9,0x14,0xdd,0x1b,0xd2,0x22,0xc6,0x29,0xbb,0x30,0xaf,0x1b,0xd2,
    0x03,0x7a,0x0a,0x6e,0x11,0x63,0x18,0x57,0x1f,0x4c,0x26,0x40,0x2d,0x35,0x34,0x29,
    0xfc,0x85,0xf5,0x91,0xee,0x9c,0xe7,0xa8,0xe0,0xb3,0xd9,0xbf,0xd2,0xca,0xcb,0xd6,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xfc,0x00,0xfa,0x00,0xf8,
    0x07,0xa6,0x0f,0x4d,0x16,0xf3,0x1e,0x9a,0x26,0x40,0x2d,0xe7,0x35,0x8d,0x1e,0x9a,
    0x03,0xd3,0x0b,0x79,0x13,0x20,0x1a,0xc6,0x22,0x6d,0x2a,0x13,0x31,0xba,0x39,0x60,
    0xfc,0x2c,0xf4,0x86,0xec,0xdf,0xe5,0x39,0xdd,0x92,0xd5,0xec,0xce,0x45,0xc6,0x9f,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0xac,0x00,0xaa,0x00,0xa8,
    0x08,0x6a,0x10,0xd4,0x19,0x3e,0x21,0xa9,0x2a,0x13,0x32,0x7d,0x3a,0xe7,0x21,0xa9,
    0x04,0x35,0x0c,0x9f,0x15,0x09,0x1d,0x73,0x25,0xde,0x2e,0x48,0x36,0xb2,0x3f,0x1c,
    0xfb,0xca,0xf3,0x60,0xea,0xf6,0xe2,0x8c,0xda,0x21,0xd1,0xb7,0xc9,0x4d,0xc0,0xe3,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x5e,0x00,0x5c,0x00,0x5a,0x00,0x58,
    0x09,0x41,0x12,0x83,0x1b,0xc4,0x25,0x06,0x2e,0x47,0x37,0x89,0x40,0xca,0x25,0x06,
    0x04,0xa0,0x0d,0xe2,0x17,0x23,0x20,0x65,0x29,0xa6,0x32,0xe8,0x3c,0x29,0x45,0x6b,
    0xfb,0x5f,0xf2,0x1d,0xe8,0xdc,0xdf,0x9a,0xd6,0x59,0xcd,0x17,0xc3,0xd6,0xba,0x94,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0x00,0x0e,0x00,0x0c,0x00,0x0a,0x00,0x08,
    0x0a,0x2e,0x14,0x5c,0x1e,0x8a,0x28,0xb9,0x32,0xe7,0x3d,0x15,0x47,0x43,0x28,0xb9,
    0x05,0x17,0x0f,0x45,0x19,0x73,0x23,0xa1,0x2d,0xd0,0x37,0xfe,0x42,0x2c,0x4c,0x5a,
    0xfa,0xe8,0xf0,0xba,0xe6,0x8c,0xdc,0x5e,0xd2,0x2f,0xc8,0x01,0xbd,0xd3,0xb3,0xa5,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0xff,0xbe,0xff,0xbc,0xff,0xba,0xff,0xb8,
    0x00,0x08,0x00,0x10,0x00,0x18,0x00,0x20,0x00,0x28,0x00,0x30,0x00,0x38,0x00,0x20,
    0x00,0x04,0x00,0x0c,0x00,0x14,0x00,0x1c,0x00,0x24,0x00,0x2c,0x00,0x34,0x00,0x3c,
    0xff,0xfc,0xff,0xf4,0xff,0xec,0xff,0xe4,0xff,0xdc,0xff,0xd4,0xff,0xcc,0xff,0xc4,
    0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,
    0xff,0x76,0xff,0x74,0xff,0x72,0xff,0x70,0xff,0x6e,0xff,0x6c,0xff,0x6a,0xff,0x68,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  };

