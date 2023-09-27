#include "s21_decimal.h"

unsigned int s21_get_sign(const s21_decimal *dec) { return dec->bits[3] >> 31; }

char s21_is_zero(const s21_decimal *num1) {
  return !num1->bits[0] && !num1->bits[1] && !num1->bits[2];
}

void decimal_copy(const s21_decimal *src, s21_decimal *dst) {
  for (size_t i = 0; i != 4; ++i) dst->bits[i] = src->bits[i];
}

unsigned int s21_get_exp(const s21_decimal *dec) {
  return dec->bits[3] << 1 >> 17;
}
int dec_div_10(s21_decimal *src) {
  int tmp = 0;
  s21_decimal res = {0};
  set_exp(s21_get_exp(src) - 1, &res);
  int sign = s21_get_sign(src);
  for (int i = 95; i >= 0; i--) {
    tmp *= 2;
    shift_left(&res);
    tmp += get_decimal(i, src);
    if (tmp > 9) {
      res.bits[0] += 1;
      tmp -= 10;
    }
  }
  s21_set_decimal_to_zero(src);
  decimal_copy(&res, src);

  set_sign(sign, src);
  return tmp;
}
void s21_set_bit(s21_decimal *value, int i, int x) {
  int number_of_bite = i / 32;
  int number_of_bit = i % 32;
  if (x == 1)
    value->bits[number_of_bite] |= (1u << number_of_bit);
  else
    value->bits[number_of_bite] &= (~((1u) << number_of_bit));
}
void s21_set_decimal_to_zero(s21_decimal *dec) {
  for (int i = 0; i != 4; ++i) {
    dec->bits[i] = 0;
  }
}
void shift_left(s21_decimal *dec) {
  int tmp_31 = dec->bits[0] >> 31, tmp_63 = dec->bits[1] >> 31;
  dec->bits[0] <<= 1;
  dec->bits[1] <<= 1;
  dec->bits[2] <<= 1;
  s21_set_bit(dec, 32, tmp_31);
  s21_set_bit(dec, 64, tmp_63);
}

int get_scale(s21_decimal src) {
  int scale = 0;
  for (unsigned mask = 0x800000; mask != 0x8000; mask >>= 1) {
    scale <<= 1;
    scale |= !!(src.bits[3] & mask);
  }
  return scale;
}

void set_mp(s21_decimal *s21_decimal, int sign) {
  s21_set_bit(s21_decimal, 127, sign);
}
int get_mp(s21_decimal src) { return get_bit(src.bits[3], 31); }
void set_sign(int sign, s21_decimal *dest) {
  if (sign) {
    dest->bits[3] |= (1 << 31);
  } else {
    dest->bits[3] &= ~(1 << 31);
  }
}
void set_exp(int exp, s21_decimal *dest) {
  int sign = s21_get_sign(dest);
  dest->bits[3] = 0;
  dest->bits[3] += exp << 16;
  set_sign(sign, dest);
}
int get_decimal(int i, s21_decimal *value) {
  int res = -1;
  if (0 <= i && i <= 127) {
    res = (value->bits[i / 32] & (1 << (i % 32))) != 0;
  }
  return res;
}
int sum_mantissa(s21_decimal *dec1, s21_decimal *dec2, s21_decimal *res) {
  int overflow = 0;
  int bit1 = 0;
  int bit2 = 0;
  for (int i = 0; i < 96; i++) {
    bit1 = get_decimal(i, dec1);
    bit2 = get_decimal(i, dec2);
    set_decimal(i, (overflow + bit1 + bit2) % 2, res);
    overflow = (overflow + bit1 + bit2) / 2;
  }
  return overflow;
}

void set_decimal(int i, int x, s21_decimal *value) {
  if (x) {
    value->bits[i / 32] |= (1 << (i % 32));
  } else {
    value->bits[i / 32] &= ~(1 << (i % 32));
  }
}
unsigned int s21_get_bit(const s21_decimal *dec, int bit) {
  unsigned int index = bit / 32;
  unsigned int pos = bit % 32;
  unsigned int res = 0;
  if (index < 4) {
    res = (dec->bits[index] >> pos) & 1;
  }
  return res;
}

int s21_div_by_10(s21_decimal *dest) {
  unsigned long int temp = (dest->bits[2] % 10) * (UINT_MAX + 1);
  unsigned long int temp2 = ((dest->bits[1] + temp) % 10) * (UINT_MAX + 1);
  dest->bits[2] = (unsigned)dest->bits[2] / 10;
  dest->bits[1] = ((unsigned)dest->bits[1] + temp) / 10;
  int ost = ((unsigned)dest->bits[0] + temp2) % 10;
  dest->bits[0] = ((unsigned)dest->bits[0] + temp2) / 10;
  return ost;
}

// int s21_mult_by_10(s21_decimal* dest) {
//   another_code code = OK;
//   unsigned long int temp = (unsigned long)dest->bits[0] * 10;
//   int div_cout = 0;
//   while (temp > UINT_MAX) {
//     temp -= UINT_MAX;
//     ++div_cout;
//   }
//   dest->bits[0] = temp;
//   if ((unsigned long)(dest->bits[1] + div_cout) > UINT_MAX) {
//     if((unsigned)dest->bits[2] == UINT_MAX) code = ERROR;
//     else {
//       unsigned long int temp2 = UINT_MAX - dest->bits[1];
//       div_cout -= temp2;
//       dest->bits[1] = div_cout;
//     }
//   }
//   else {
//     dest->bits[1] += div_cout;
//   }
//   return code;
// }

int s21_mult_by_10(s21_decimal *dest) {
  unsigned long int carry = 0;
  s21_decimal copy;
  copy.bits[3] = dest->bits[3];
  another_code code = ERROR;
  for (int i = 0; i < 3; ++i) {
    unsigned long temp = (unsigned long)(unsigned)dest->bits[i] * 10;
    copy.bits[i] = dest->bits[i] * 10;
    copy.bits[i] += carry;
    carry = (temp) >> 32;
  }
  if (carry == 0) {
    code = OK;
    decimal_copy(&copy, dest);
  }
  return code;
}

int normalization(const s21_decimal *number1, const s21_decimal *number2,
                  s21_decimal *new_num1, s21_decimal *new_num2) {
  another_code code = OK;
  int exp1 = number1->bits[3] << 1 >> 17, exp2 = number2->bits[3] << 1 >> 17;
  decimal_copy(number1, new_num1);
  decimal_copy(number2, new_num2);
  if (exp1 != exp2) {
    if (exp1 < exp2) {
      while (exp1++ < exp2) {
        if (s21_mult_by_10(new_num1) == ERROR) {
          code = ERROR;
          break;
        }
      }
    } else if (exp2 < exp1) {
      while (exp2++ < exp1) {
        if (s21_mult_by_10(new_num2) == ERROR) {
          code = ERROR;
          break;
        }
      }
    }
  }
  return code;
}

void s21_decimal_to_zero(s21_decimal *dst) {
  for (int i = 0; i != 4; ++i) dst->bits[i] = 0;
}

char s21_compare(const s21_decimal *dec1, const s21_decimal *dec2) {
  int status = EQUAL;
  if (s21_is_zero(dec1) != 1 || s21_is_zero(dec2) != 1) {
    int is_negative1 = s21_get_sign(dec1);
    int is_negative2 = s21_get_sign(dec2);
    if (is_negative1 && !is_negative2) {
      status = LESS;
    } else if (is_negative2 && !is_negative1) {
      status = GREATER;
    }
    for (int i = 95; i >= 0 && status == 2; --i) {
      int first_bit = s21_get_bit(dec1, i);
      int second_bit = s21_get_bit(dec2, i);
      if (first_bit > second_bit) {
        status = is_negative1 ? LESS : GREATER;
      } else if (second_bit > first_bit) {
        status = is_negative1 ? GREATER : LESS;
      }
    }
  }
  return status;
}
