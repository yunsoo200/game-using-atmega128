﻿/*
 * bit_map_character.c
 *
 * Created: 2016-11-21 오후 4:42:43
 *  Author : 정헌휘 & 윤태훈
 */ 
 #include <avr/io.h>
 #include <avr/pgmspace.h>


 /** 스타트 화면용 progem **/

  const unsigned char start_lion1 [] PROGMEM = { //48 * 48
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x7F, 0x80, 0x00, 0x00, 0x00, 0x07, 0x80, 0x60, 0x00, 0x00, 0x00, 0x04, 0x00, 0x18, 0x03, 0x80,
  0x00, 0x18, 0x00, 0x0C, 0x02, 0x80, 0x00, 0x30, 0x00, 0x04, 0x02, 0x80, 0x00, 0x40, 0x00, 0x02,
  0x03, 0x80, 0x00, 0x40, 0xC0, 0x01, 0x07, 0x00, 0x00, 0x81, 0x80, 0x01, 0x04, 0x00, 0x03, 0x03,
  0x00, 0x70, 0x80, 0x00, 0x05, 0x06, 0x07, 0x0F, 0x80, 0x00, 0x01, 0x00, 0xC8, 0x00, 0xC0, 0x00,
  0x0A, 0x00, 0x70, 0x78, 0x60, 0x00, 0x0A, 0x00, 0x60, 0x84, 0x10, 0x00, 0x06, 0x00, 0x41, 0x04,
  0x18, 0x00, 0x06, 0xC1, 0x81, 0x02, 0x08, 0x00, 0x03, 0x87, 0x01, 0x02, 0x04, 0x00, 0x03, 0x07,
  0x00, 0x84, 0x04, 0x00, 0x02, 0x6A, 0x00, 0xCC, 0x02, 0x00, 0x01, 0x14, 0x00, 0x00, 0x02, 0x00,
  0x01, 0x14, 0x00, 0x00, 0x03, 0x00, 0x01, 0x08, 0x00, 0x00, 0x03, 0x00, 0x00, 0x89, 0x00, 0x00,
  0x02, 0x80, 0x00, 0xC8, 0x00, 0x00, 0x02, 0x80, 0x00, 0x50, 0x80, 0x00, 0x02, 0x40, 0x00, 0x30,
  0x80, 0x42, 0x02, 0x40, 0x00, 0x10, 0x80, 0x3C, 0x02, 0x40, 0x00, 0x20, 0x80, 0x08, 0x02, 0x80,
  0x00, 0x20, 0x80, 0x08, 0x03, 0x80, 0x00, 0x20, 0x40, 0x08, 0x02, 0x00, 0x00, 0x20, 0x40, 0x08,
  0x02, 0x00, 0x00, 0x20, 0xC0, 0x08, 0x02, 0x00, 0x00, 0x11, 0x80, 0x00, 0x02, 0x00, 0x00, 0x0E,
  0x20, 0x04, 0x02, 0x00, 0x01, 0x00, 0x20, 0x04, 0x02, 0x00, 0x00, 0xC0, 0x10, 0x04, 0x02, 0x00,
  0x00, 0x80, 0x10, 0x04, 0x02, 0x00, 0x00, 0x40, 0x08, 0x04, 0x04, 0x00, 0x00, 0x40, 0x08, 0x04,

  0x04, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08, 0x00, 0x00, 0x00, 0x02, 0x0B, 0x18, 0x00, 0x00, 0x00,
  0x01, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  const unsigned char start_lion2 [] PROGMEM = { //48 * 48
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x3F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0xC0, 0x00, 0x00, 0x00, 0x06, 0x00, 0x30, 0x02, 0x00,
  0x00, 0x08, 0x00, 0x08, 0x03, 0x00, 0x00, 0x10, 0x00, 0x04, 0x02, 0x00, 0x00, 0x20, 0x00, 0x02,
  0x02, 0x00, 0x00, 0x40, 0x00, 0x02, 0x06, 0x00, 0x00, 0x80, 0x80, 0x01, 0x00, 0x00, 0x01, 0x81,
  0x00, 0x01, 0x00, 0x00, 0x03, 0x06, 0x00, 0x1F, 0xE0, 0x00, 0x05, 0x00, 0xC0, 0xE0, 0x18, 0x00,
  0x05, 0x00, 0xC1, 0x00, 0x04, 0x00, 0x02, 0x00, 0x02, 0x01, 0xE2, 0x00, 0x06, 0x00, 0x0C, 0x02,
  0x11, 0x00, 0x06, 0x41, 0x98, 0x04, 0x10, 0x80, 0x02, 0x82, 0x50, 0x04, 0x08, 0x80, 0x03, 0x06,
  0x60, 0x04, 0x00, 0x40, 0x02, 0x6E, 0x40, 0x02, 0x10, 0x40, 0x01, 0x69, 0x80, 0x01, 0xE0, 0x00,
  0x01, 0x01, 0x80, 0x00, 0x00, 0x20, 0x01, 0x0B, 0x00, 0x00, 0x00, 0x20, 0x00, 0x86, 0x00, 0x00,
  0x00, 0x20, 0x00, 0x82, 0x08, 0x00, 0x00, 0x20, 0x00, 0x44, 0x08, 0x00, 0x00, 0x60, 0x00, 0x24,
  0x08, 0x00, 0x00, 0x60, 0x00, 0x14, 0x08, 0x07, 0xE0, 0x60, 0x00, 0x08, 0x08, 0x00, 0x00, 0x60,
  0x00, 0x08, 0x00, 0x01, 0x00, 0x60, 0x00, 0x08, 0x00, 0x01, 0x00, 0x60, 0x00, 0x08, 0x10, 0x01,
  0x00, 0xE0, 0x00, 0x04, 0x60, 0x00, 0x00, 0x80, 0x00, 0x07, 0xC0, 0x02, 0x00, 0x80, 0x00, 0x00,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x01, 0x80, 0x08, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x08, 0x04, 0x02, 0x00, 0x00, 0x80, 0x08, 0x04, 0x02, 0x00, 0x00, 0x40, 0x08, 0x04,

  0x04, 0x00, 0x00, 0x00, 0x08, 0x04, 0x04, 0x00, 0x00, 0x00, 0x04, 0x0C, 0x08, 0x00, 0x00, 0x00,
  0x06, 0x1B, 0x10, 0x00, 0x00, 0x00, 0x01, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

 const unsigned char start_title [] PROGMEM = { // 40 * 72
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x20, 0x41, 0x83, 0x0C, 0x00, 0x40, 0x00, 0x00, 0x3F, 0x20, 0xF1, 0x8F, 0xCC,
0x7E, 0x40, 0x00, 0x00, 0x03, 0x21, 0x99, 0x8C, 0xCC, 0x02, 0x40, 0x00, 0x00, 0x03, 0x21, 0x19,
0x88, 0x7C, 0x02, 0x40, 0x00, 0x00, 0x3F, 0x21, 0x09, 0x88, 0x4C, 0x02, 0x40, 0x00, 0x00, 0x3F,
0x39, 0x09, 0x8C, 0xCC, 0x12, 0x70, 0x00, 0x00, 0x20, 0x21, 0x09, 0x87, 0x8C, 0x12, 0x70, 0x00,
0x00, 0x20, 0x21, 0x99, 0x80, 0x0C, 0x12, 0x40, 0x00, 0x00, 0x20, 0xA0, 0xF1, 0x82, 0x0C, 0x10,
0x40, 0x00, 0x00, 0x3F, 0xA0, 0x61, 0x82, 0x00, 0x13, 0x40, 0x00, 0x00, 0x00, 0x20, 0x01, 0x82,
0x00, 0xFF, 0x40, 0x00, 0x00, 0x00, 0x20, 0x01, 0x83, 0xFC, 0x00, 0x40, 0x00, 0x00, 0x00, 0x20,
0x01, 0x83, 0xFC, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x08, 0x00,
0x00, 0x00, 0x00, 0x61, 0x00, 0x34, 0x00, 0x08, 0x03, 0xF8, 0x00, 0x03, 0xFD, 0x1F, 0xB4, 0x00,
0xFF, 0x82, 0x0C, 0x00, 0x00, 0x01, 0x04, 0xB4, 0x00, 0x1C, 0x02, 0x0C, 0x00, 0x00, 0xF9, 0xC4,

0xB4, 0x00, 0x77, 0x03, 0xF8, 0x00, 0x01, 0x89, 0xCD, 0xF4, 0x00, 0xC1, 0x80, 0x00, 0x00, 0x01,
0x89, 0x0D, 0xF4, 0x00, 0x00, 0x0F, 0xFE, 0x00, 0x01, 0xF9, 0x09, 0xB4, 0x01, 0xFF, 0xCF, 0xFE,
0x00, 0x00, 0x21, 0x09, 0x34, 0x00, 0x08, 0x03, 0xFC, 0x00, 0x00, 0xFF, 0x19, 0x34, 0x00, 0x7F,
0x83, 0xFC, 0x00, 0x00, 0xFF, 0x03, 0x34, 0x00, 0x7F, 0x80, 0x0C, 0x00, 0x00, 0xC1, 0x00, 0x34,
0x00, 0x41, 0x83, 0xFC, 0x00, 0x00, 0xFF, 0x00, 0x34, 0x00, 0x7F, 0x82, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x34, 0x00, 0x7F, 0x83, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
