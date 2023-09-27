#pragma once
#include "s21_decimal.h"
#define EXP_MAX 28
#define EXP_START 16
#define EXP_END 23

#define LAST_BIT0 31
#define LAST_BIT1 63
#define LAST_BIT2 95
#define LAST_BIT3 127
#define LAST_BIT4 159
#define LAST_BIT5 191

typedef struct {
  int bits[7];
} s21_big_decimal;

s21_big_decimal from_decimal_to_big_decimal(s21_decimal value);
int s21_get_bit_bdcml(s21_big_decimal value, int position);
int s21_get_sign_bdcml(s21_big_decimal value);
int s21_get_exp_bdcml(s21_big_decimal value);
void s21_set_sign_bdcml(s21_big_decimal *value, int sign);
void s21_set_bit_bdcml(s21_big_decimal *value, int position, int bit);
void s21_set_exp_bdcml(s21_big_decimal *value, int exponent);
int s21_is_zero_bdcml(s21_big_decimal value);
int s21_lshift_bdcml(s21_big_decimal *value);
void s21_shift_bdcml(s21_big_decimal *value);
s21_big_decimal s21_bin_xor(s21_big_decimal value_1, s21_big_decimal value_2);
s21_big_decimal s21_bin_xor_all(s21_big_decimal value_1,
                                s21_big_decimal value_2);
s21_big_decimal s21_bin_and(s21_big_decimal value_1, s21_big_decimal value_2);
s21_big_decimal s21_bin_and_all(s21_big_decimal value_1,
                                s21_big_decimal value_2);
s21_big_decimal binaryNotBig(s21_big_decimal value);
int s21_bin_add_bdcml(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result);
void s21_sub_bdcml(s21_big_decimal value_1, s21_big_decimal value_2,
                   s21_big_decimal *result);
int s21_bin_mul_bdcml(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result);
void s21_set_sign_and_exp_bdcml(s21_big_decimal *value);
int s21_is_less_mant(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_only_zero(s21_big_decimal value, int i);
void s21_clear_bdcml(s21_big_decimal *value);
s21_big_decimal int_div_big(s21_big_decimal value_1, s21_big_decimal value_2,
                            s21_big_decimal *result);
int s21_is_equals_five(s21_big_decimal value);
void s21_round_bdcml(s21_big_decimal *value, s21_big_decimal remainder);
void div_10(s21_big_decimal *value);
void s21_normal_bdcml(s21_big_decimal *value);
void my_div(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
int from_big_decimal_to_decimal(s21_big_decimal value, s21_decimal *result,
                                int exp);