#include <math.h>

#include "s21_decimal.h"

#define UINT_MAX 4294967295
#define DECIMAL_MAX 7.9228162514264337593543950335e+28
#define DECIMAL_MIN_SEGA 1e-28

int s21_from_int_to_decimal(int src, s21_decimal *dst) {  // success
  for (int i = 1; i != 4; ++i) dst->bits[i] = 0;
  if (src < 0) {
    dst->bits[3] |= 1 << 31;
    src = -src;
  }
  dst->bits[0] = src;
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {  // success
  int res = 0;
  if (src.bits[1] || src.bits[2])
    res = 1;
  else {
    *dst = src.bits[0] / (int)pow(10, s21_get_exp(&src));
    if (s21_get_sign(&src))
      *dst = -*dst;
    else
      *dst = *dst;
  }
  return res;
}

int searchBit(s21_decimal src, int index) {
  int mask = 1u << (index % 32);
  return (src.bits[index / 32] & mask) != 0;
}
int searchBitFloat(float src, int index) {
  int mask = 1u << index;
  return (*(int *)&src & mask) != 0;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  // if (src.bits[2] != 0) {
  //   res = 1;
  // } else {
  int mask = 16711680;  // c 30 to 24 '1'
  int exp = (src.bits[3] & mask) >> 16;
  // int exp = s21_get_exp(&src);
  double tmp = 0.0;
  for (int i = 0; i < 96; i++) {
    tmp += searchBit(src, i) * pow(2, i);
  }
  tmp = tmp * pow(10, -exp);
  if (s21_get_sign(&src))
    *dst = -tmp;
  else
    *dst = tmp;
  // }
  return res;
}

int searchExpFloat(float x) {
  int ExpFloat = 0;
  int bits = 23;
  int Step = 0;
  while (bits <= 30) {
    int i = searchBitFloat(x, bits);
    ExpFloat += i * pow(2, Step);
    Step++;
    bits++;
  }
  ExpFloat -= 127;
  return ExpFloat;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int ret = 1;
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;

  if (!isinf(src) && !isnan(src)) {
    if (src != 0) {
      int sign = *(int *)&src >> 31;
      int exponent = ((*(int *)&src & ~0x80000000) >> 23) - 127;
      double temp = (double)fabs(src);
      int off = 0;

      while (off < 28 && (int)temp / (int)pow(2, 21) == 0) {
        temp *= 10;
        off++;
      }

      temp = round(temp);

      if (off <= 28 && (exponent > -94 && exponent < 96)) {
        s21_float_bits mantissa = {0};
        temp = (float)temp;

        while (fmod(temp, 10) == 0 && off > 0) {
          off--;
          temp /= 10;
        }

        mantissa.floa_t = temp;
        exponent = ((*(int *)&mantissa.floa_t & ~0x80000000) >> 23) - 127;
        dst->bits[exponent / 32] |= 1 << exponent % 32;

        for (int i = exponent - 1, j = 22; j >= 0; i--, j--)
          if ((mantissa.uin_t & (1 << j)) != 0)
            dst->bits[i / 32] |= 1 << i % 32;

        dst->bits[3] = (sign << 31) | (off << 16);
      }
    }
    ret = 0;
  }
  return ret;
}