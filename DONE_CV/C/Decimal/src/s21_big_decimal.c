#include "s21_big_decimal.h"

s21_big_decimal from_decimal_to_big_decimal(s21_decimal value) {
  s21_big_decimal result = {0};
  for (int i = 0; i < 3; i++) {
    result.bits[i] = value.bits[i];
  }
  result.bits[6] = value.bits[3];
  return result;
}

int s21_get_bit_bdcml(s21_big_decimal value, int position) {
  return (value.bits[position / 32] >> (position % 32)) & 1;
}

int s21_get_sign_bdcml(s21_big_decimal value) {
  return (value.bits[6] >> 31) & 1U;
}

int s21_get_exp_bdcml(s21_big_decimal value) {
  int exp = 0;
  for (int expPos = EXP_START, shift = 0; expPos <= EXP_END;
       expPos++, shift++) {
    if ((value.bits[6] >> expPos) & 1u) {
      exp |= (1u << shift);
    }
  }
  return exp;
}

void s21_set_sign_bdcml(s21_big_decimal *value, int sign) {
  if (sign) {
    value->bits[6] |= (1U << 31);
  } else {
    value->bits[6] &= ~(1UL << 31);
  }
}

void s21_set_bit_bdcml(s21_big_decimal *value, int position, int bit) {
  if (bit) {
    value->bits[position / 32] |= (1U << (position % 32));
  } else {
    value->bits[position / 32] &= ~(1UL << (position % 32));
  }
}

void s21_set_exp_bdcml(s21_big_decimal *value, int exponent) {
  int min_exp = 0;
  int max_exp = 57;
  if (min_exp <= exponent && exponent <= max_exp) {
    int sign = s21_get_sign_bdcml(*value);
    value->bits[6] = 0;
    value->bits[6] |= (exponent << EXP_START);
    s21_set_sign_bdcml(value, sign);
  }
}

int s21_is_zero_bdcml(s21_big_decimal value) {
  return !value.bits[0] && !value.bits[1] && !value.bits[2] && !value.bits[3] &&
         !value.bits[4] && !value.bits[5];
}

int s21_lshift_bdcml(s21_big_decimal *value) {
  int lastBit0 = s21_get_bit_bdcml(*value, LAST_BIT0);
  int lastBit1 = s21_get_bit_bdcml(*value, LAST_BIT1);
  int lastBit2 = s21_get_bit_bdcml(*value, LAST_BIT2);
  int lastBit3 = s21_get_bit_bdcml(*value, LAST_BIT3);
  int lastBit4 = s21_get_bit_bdcml(*value, LAST_BIT4);
  int lastBit5 = s21_get_bit_bdcml(*value, LAST_BIT5);

  for (int i = 0; i < 6; i++) {
    value->bits[i] <<= 1;
  }
  s21_set_bit_bdcml(value, LAST_BIT0 + 1, lastBit0);
  s21_set_bit_bdcml(value, LAST_BIT1 + 1, lastBit1);
  s21_set_bit_bdcml(value, LAST_BIT2 + 1, lastBit2);
  s21_set_bit_bdcml(value, LAST_BIT3 + 1, lastBit3);
  s21_set_bit_bdcml(value, LAST_BIT4 + 1, lastBit4);

  return lastBit5;  // 1 == overflow; 0 == !overflow
}

void s21_shift_bdcml(s21_big_decimal *value) {
  int firstBit1 = s21_get_bit_bdcml(*value, LAST_BIT0 + 1);
  int firstBit2 = s21_get_bit_bdcml(*value, LAST_BIT1 + 1);
  int firstBit3 = s21_get_bit_bdcml(*value, LAST_BIT2 + 1);
  int firstBit4 = s21_get_bit_bdcml(*value, LAST_BIT3 + 1);
  int firstBit5 = s21_get_bit_bdcml(*value, LAST_BIT4 + 1);

  for (int i = 6; i >= 0; i--) {
    value->bits[i] >>= 1;
  }
  s21_set_bit_bdcml(value, LAST_BIT5, 0);
  s21_set_bit_bdcml(value, LAST_BIT4, firstBit5);
  s21_set_bit_bdcml(value, LAST_BIT3, firstBit4);
  s21_set_bit_bdcml(value, LAST_BIT2, firstBit3);
  s21_set_bit_bdcml(value, LAST_BIT1, firstBit2);
  s21_set_bit_bdcml(value, LAST_BIT0, firstBit1);
}

s21_big_decimal s21_bin_xor(s21_big_decimal value_1, s21_big_decimal value_2) {
  s21_big_decimal result = {0};
  for (int i = 0; i < 6; i++) {
    result.bits[i] = value_1.bits[i] ^ value_2.bits[i];
  }
  return result;
}

s21_big_decimal s21_bin_xor_all(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  s21_big_decimal result = s21_bin_xor(value_1, value_2);
  result.bits[6] = value_1.bits[6] ^ value_2.bits[6];
  return result;
}

s21_big_decimal s21_bin_and(s21_big_decimal value_1, s21_big_decimal value_2) {
  s21_big_decimal result = {0};
  for (int i = 0; i < 6; i++) {
    result.bits[i] = value_1.bits[i] & value_2.bits[i];
  }
  return result;
}

s21_big_decimal s21_bin_and_all(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  s21_big_decimal result = s21_bin_and(value_1, value_2);
  result.bits[6] = value_1.bits[6] & value_2.bits[6];
  return result;
}

s21_big_decimal binaryNotBig(s21_big_decimal value) {
  s21_big_decimal result = {0};
  for (int i = 0; i < 6; i++) {
    result.bits[i] = ~value.bits[i];
  }
  return result;
}

int s21_bin_add_bdcml(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result) {
  int error = 0;
  while (!s21_is_zero_bdcml(value_2) && !error) {
    s21_big_decimal temp = s21_bin_and(value_1, value_2);
    value_1 = s21_bin_xor(value_1, value_2);
    error = s21_lshift_bdcml(&temp);
    value_2 = temp;
  }

  *result = value_1;

  return error;
}

void s21_sub_bdcml(s21_big_decimal value_1, s21_big_decimal value_2,
                   s21_big_decimal *result) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal negative_value_2 = {0};
  s21_bin_add_bdcml(binaryNotBig(value_2), one, &negative_value_2);

  while (!(s21_is_zero_bdcml(negative_value_2) && !negative_value_2.bits[6])) {
    s21_big_decimal temp = s21_bin_and_all(value_1, negative_value_2);
    value_1 = s21_bin_xor_all(value_1, negative_value_2);
    temp.bits[6] <<= 1;
    s21_set_bit_bdcml(&temp, LAST_BIT5 + 1, s21_lshift_bdcml(&temp));
    negative_value_2 = temp;
  }
  s21_set_bit_bdcml(&value_1, LAST_BIT5 + 1, 0);
  *result = value_1;
}

int s21_bin_mul_bdcml(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result) {
  int error = 0;
  s21_big_decimal tmp = {0};

  while (!s21_is_zero_bdcml(value_2) && !error) {
    if (s21_get_bit_bdcml(value_2, 0)) {
      error = s21_bin_add_bdcml(value_1, tmp, &tmp);
      if (error) break;
    }
    error = s21_lshift_bdcml(&value_1);
    s21_shift_bdcml(&value_2);
  }
  *result = tmp;

  return error;
}

void s21_set_sign_and_exp_bdcml(s21_big_decimal *value) {
  if (s21_is_zero_bdcml(*value)) {
    s21_set_sign_bdcml(value, 0);
    s21_set_exp_bdcml(value, 0);
  }
}

int s21_is_less_mant(s21_big_decimal value_1, s21_big_decimal value_2) {
  int error = 0;
  int bit_value1 = 0;
  int bit_value2 = 0;

  for (int i = LAST_BIT5; i != -1; i--) {
    bit_value1 = s21_get_bit_bdcml(value_1, i);
    bit_value2 = s21_get_bit_bdcml(value_2, i);
    if (bit_value1 > bit_value2) {
      error = 0;
      break;
    } else if (bit_value1 < bit_value2) {
      error = 1;
      break;
    }
  }

  return error;
}

int s21_is_only_zero(s21_big_decimal value, int i) {
  int is_all_zero = 1;
  while (i >= 0) {
    if (s21_get_bit_bdcml(value, i)) {
      is_all_zero = 0;
      break;
    }
    i--;
  }
  return is_all_zero;
}

void s21_clear_bdcml(s21_big_decimal *value) {
  for (int i = 0; i <= 6; i++) {
    value->bits[i] = 0;
  }
}

s21_big_decimal int_div_big(s21_big_decimal value_1, s21_big_decimal value_2,
                            s21_big_decimal *result) {
  s21_clear_bdcml(result);
  int i = LAST_BIT5;
  while (!s21_get_bit_bdcml(value_1, i) && i > 0) {
    i--;
  }
  s21_big_decimal tmp = {{s21_get_bit_bdcml(value_1, i), 0, 0, 0, 0, 0, 0}};

  while (i > 0) {
    while (s21_is_less_mant(tmp, value_2) && i-- > 0) {
      s21_lshift_bdcml(&tmp);
      s21_set_bit_bdcml(&tmp, 0, s21_get_bit_bdcml(value_1, i));
      s21_lshift_bdcml(result);
    }

    if (i != -1) {
      s21_sub_bdcml(tmp, value_2, &tmp);
      s21_set_bit_bdcml(result, 0, 1);
      if (s21_is_zero_bdcml(tmp) && s21_is_only_zero(value_1, i - 1)) {
        for (int j = i - 1; j >= 0; j--) s21_lshift_bdcml(result);
        break;
      }
    }
  }
  return tmp;  // remainder
}

int s21_is_equals_five(s21_big_decimal value) {
  return value.bits[0] == 5 && !value.bits[1] && !value.bits[2] &&
         !value.bits[3] && !value.bits[4] && !value.bits[5];
}

void s21_round_bdcml(s21_big_decimal *value, s21_big_decimal remainder) {
  s21_big_decimal five = {{5, 0, 0, 0, 0, 0, 0}}, one = {{1, 0, 0, 0, 0, 0, 0}};
  if (s21_is_less_mant(five, remainder)) {
    s21_bin_add_bdcml(*value, one, value);
  } else if (s21_is_equals_five(remainder) && s21_get_bit_bdcml(*value, 0)) {
    s21_bin_add_bdcml(*value, one, value);
  }
}

void div_10(s21_big_decimal *value) {
  int exp = s21_get_exp_bdcml(*value), sign = s21_get_sign_bdcml(*value);
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal remainder = int_div_big(*value, ten, value);
  s21_round_bdcml(value, remainder);
  s21_set_exp_bdcml(value, exp - 1);
  s21_set_sign_bdcml(value, sign);
}

void s21_normal_bdcml(s21_big_decimal *value) {
  int exp = s21_get_exp_bdcml(*value);
  int sign = s21_get_sign_bdcml(*value);
  if (exp && !s21_get_bit_bdcml(*value, 0)) {
    s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}}, tmp_res = {0};
    while (s21_is_zero_bdcml(int_div_big(*value, ten, &tmp_res)) && exp > 0) {
      exp--;
      *value = tmp_res;
    }
    s21_set_exp_bdcml(value, exp);
    s21_set_sign_bdcml(value, sign);
  }
}

void my_div(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  s21_big_decimal tmp =
      int_div_big(value_1, value_2, result);  // tmp - остаток от деления нацело
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}};

  if (!s21_is_zero_bdcml(tmp)) {  // если tmp != 0 - дробное деление
    int exp = 0;
    int code = {0}, code1 = code, code2 = code;
    s21_big_decimal tmp_res = *result;

    while (!s21_is_zero_bdcml(tmp) && exp < 56) {
      int counter = 0;
      while (s21_is_less_mant(tmp, value_2) && exp < 56 && !code && !code1) {
        code = s21_bin_mul_bdcml(tmp, ten, &tmp);
        exp++;
        counter++;
        code1 = s21_bin_mul_bdcml(tmp_res, ten, &tmp_res);
      }
      s21_big_decimal r = {0};
      tmp = int_div_big(tmp, value_2, &r);
      code2 = s21_bin_add_bdcml(tmp_res, r, &tmp_res);
      if (code || code1 || code2) {
        exp -= counter;
        break;
      } else
        *result = tmp_res;
    }
    s21_set_exp_bdcml(result, exp);
  }
}

int from_big_decimal_to_decimal(s21_big_decimal value, s21_decimal *result,
                                int exp) {
  int error = 0;
  if (value.bits[3] || value.bits[4] || value.bits[5]) {
    if (!exp) {
      while ((value.bits[3] || value.bits[4] || value.bits[5]) &&
             s21_get_exp_bdcml(value)) {
        div_10(&value);
      }
    } else {
      while ((value.bits[3] || value.bits[4] || value.bits[5]) ||
             s21_get_exp_bdcml(value) > exp) {
        div_10(&value);
      }
    }
  }
  if (value.bits[3] || value.bits[4] || value.bits[5]) {
    error = s21_get_sign_bdcml(value) ? 2 : 1;
    s21_clear_bdcml(&value);
  } else if (s21_get_exp_bdcml(value) > 28) {
    while (s21_get_exp_bdcml(value) > 28) {
      div_10(&value);
      if (s21_is_zero_bdcml(value)) {
        error = 3;
        s21_clear_bdcml(&value);
        break;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    result->bits[i] = value.bits[i];
  }
  result->bits[3] = value.bits[6];
  return error;
}
