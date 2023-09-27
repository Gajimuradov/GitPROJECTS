#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <stdarg.h>

#include "s21_string.h"

typedef struct format {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int width;
  int precision;
  char length;
  char specifier;
  int error;
  int percent;
} pars_format;

int s21_sprintf(char *str, const char *format, ...);

char *s21_parser(char *str, pars_format *form);
char *pars_flags(char *str, pars_format *form);
char *pars_width(char *str, pars_format *form);
char *pars_precision(char *str, pars_format *form);
char *pars_length(char *str, pars_format *form);
char *pars_specifier(char *str, pars_format *form);

char *s21_transfer_buf(va_list ap, pars_format *form);
char *processing_char(va_list ap, pars_format *form);
char *proc_signed_int(va_list ap, pars_format form);
char *processing_float(va_list ap, pars_format *form);
char *processing_str(va_list ap, pars_format *form);
char *proc_unsign_int(va_list ap, pars_format form);

char *rec_wstr(const wchar_t *w_str);
int calculation_size_str(pars_format *form, int strlen);

int calculation_size_double(pars_format *form, int str_length);
char *doubl_trans_str(long double number, char *buf, pars_format form);

int length_double(double number, int precision);
int int_len(long int num);

int find_buf_size_int(pars_format form, int strlen);
int unsign_len_int(unsigned long int number);
char *unsign_long_itoa(unsigned long int number, char *buf, int basis,
                       pars_format form);
void invert_str(char *str, int len);
void swap_chars(char *a, char *b);
char long_itoa(long int num, char *buf, int basis, pars_format form);

#endif