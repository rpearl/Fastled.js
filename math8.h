#ifndef _MATH_H_
#define _MATH_H_

#include <stdint.h>

typedef uint8_t fract8;
typedef uint16_t fract16;
typedef uint16_t  accum88;  ///< ANSI: unsigned short _Accum.  8 bits int, 8 bits fraction
typedef int16_t   saccum78; ///< ANSI: signed   short _Accum.  7 bits int, 8 bits fraction
typedef uint32_t  accum1616;///< ANSI: signed         _Accum. 16 bits int, 16 bits fraction
typedef int32_t   saccum1516;///< ANSI: signed         _Accum. 15 bits int, 16 bits fraction
typedef uint16_t  accum124; ///< no direct ANSI counterpart. 12 bits int, 4 bits fraction
typedef int32_t   saccum114;///< no direct ANSI counterpart. 1 bit int, 14 bits fraction

// math
uint8_t  qadd8(uint8_t i, uint8_t j);
int8_t   qadd7(int8_t i, int8_t j);
uint8_t  qsub8(uint8_t i, uint8_t j);

uint8_t  qmul8(uint8_t i, uint8_t j);

uint8_t   avg8(uint8_t i, uint8_t j);
int8_t    avg7(int8_t i, int8_t j);
int16_t  avg15(int16_t i, int16_t j);
uint16_t avg16(uint16_t i, uint16_t j);
int8_t    abs8(int8_t i);
uint8_t sqrt16(uint16_t x);

int16_t sin16(uint16_t theta);
int16_t cos16(uint16_t theta);
int8_t sin8(uint8_t theta);
int8_t cos8(uint8_t theta);


// scaling
uint8_t  scale8(uint8_t i, fract8 scale);
uint8_t  scale8_video(uint8_t i, fract8 scale);
uint16_t scale16by8(uint16_t i, fract8 scale);
uint16_t scale16(uint16_t i, fract16 scale);

void nscale8x3( uint8_t& r, uint8_t& g, uint8_t& b, fract8 scale);
void nscale8x3_video( uint8_t& r, uint8_t& g, uint8_t& b, fract8 scale);

uint8_t  dim8_raw(uint8_t x);
uint8_t  dim8_video(uint8_t x);
uint8_t  dim8_lin(uint8_t x );

uint8_t  brighten8_raw(uint8_t x);
uint8_t  brighten8_video(uint8_t x);
uint8_t  brighten8_lin(uint8_t x);

// interpolation
uint8_t  lerp8by8(uint8_t a, uint8_t b, fract8 frac);
uint16_t lerp16by16(uint16_t a, uint16_t b, fract16 frac);
uint16_t lerp16by8(uint16_t a, uint16_t b, fract8 frac);
int16_t  lerp15by8(int16_t a, int16_t b, fract8 frac);
int16_t  lerp15by16(int16_t a, int16_t b, fract16 frac);
uint8_t  map8(uint8_t in, uint8_t rangeStart, uint8_t rangeEnd);

// easing
uint8_t ease8InOutQuad( uint8_t i);
fract8 ease8InOutCubic( fract8 i);
fract8 ease8InOutApprox( fract8 i);

// pulses
uint8_t triwave8(uint8_t in);
uint8_t quadwave8(uint8_t in);
uint8_t cubicwave8(uint8_t in);
uint8_t squarewave8( uint8_t in, uint8_t pulsewidth=128);

#endif
