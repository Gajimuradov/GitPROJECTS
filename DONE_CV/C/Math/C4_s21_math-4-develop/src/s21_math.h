#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <limits.h>
#include <stdio.h>

#define S21_PI 3.1415926535897932384
#define S21_M_E 2.7182818284590452353602874  // Значение Е 25 после запятой
#define S21_EXP 1e-17
#define S21_MAX_LONG_DOUBLE 1.79769313486231571e+308
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_EPS10 0.0000000001

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_
