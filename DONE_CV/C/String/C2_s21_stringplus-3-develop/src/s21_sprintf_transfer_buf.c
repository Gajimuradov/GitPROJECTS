#include "s21_sprintf.h"

char *s21_transfer_buf(va_list ap, pars_format *form) {
  char *buf = S21_NULL;
  switch (form->specifier) {
    case 'c':
      buf = processing_char(ap, form);
      form->precision = -1;
      break;
    case 'd':
      buf = proc_signed_int(ap, *form);
      break;
    case 'f':
      buf = processing_float(ap, form);
      break;
    case 's':
      buf = processing_str(ap, form);
      break;
    case 'u':
      buf = proc_unsign_int(ap, *form);
      break;
  }
  return buf;
}

char *processing_char(va_list ap, pars_format *form) {
  int buf_size = 1;
  char sym;
  if (form->length == 'l') {
    wchar_t w_sym = va_arg(ap, unsigned int);
    sym = (char)w_sym;
  } else {
    sym = va_arg(ap, int);
  }
  if (form->width) buf_size = form->width;
  char *buf = calloc(buf_size + 1, sizeof(char));
  for (int i = 0; i < buf_size; i++) {
    if (form->flag_minus) {
      if (i >= 1) {
        buf[i] = ' ';
      } else {
        buf[i] = sym;
      }
    } else {
      if (i < (buf_size - 1)) {
        buf[i] = ' ';
      } else {
        buf[i] = sym;
      }
    }
  }
  return buf;
}

char *processing_str(va_list ap, pars_format *form) {
  char *str = S21_NULL;
  char *b_free = S21_NULL;
  if (form->length == 'l') {
    wchar_t *w_str = va_arg(ap, wchar_t *);
    if (w_str == NULL) {
      str = NULL_STR;
    } else {
      str = rec_wstr(w_str);
      b_free = str;
    }
  } else {
    str = va_arg(ap, char *);
    if (str == NULL) {
      str = NULL_STR;
    }
  }
  int len_str = s21_strlen(str);
  int size_buf = calculation_size_str(form, len_str);
  int space = size_buf - len_str;
  if (form->precision > -1 && form->precision <= len_str) {
    space = size_buf - form->precision;
  }
  char *buf = calloc(size_buf + 1, sizeof(char));
  for (int i = 0; i < size_buf; i++) {
    if (form->flag_minus) {
      if (i >= (size_buf - space)) {
        buf[i] = ' ';
      } else {
        buf[i] = *str;
        str++;
      }
    } else {
      if (i < space) {
        buf[i] = ' ';
      } else {
        buf[i] = *str;
        str++;
      }
    }
  }
  free(b_free);
  return buf;
}

char *rec_wstr(const wchar_t *w_str) {
  char *str_rec = S21_NULL;
  int len_wstr = 0;
  while (*w_str) {
    len_wstr++;
    w_str++;
  }
  str_rec = calloc((len_wstr + 1) + 1, sizeof(char));
  for (int i = 0; i < len_wstr + 1; i++) {
    str_rec[i] = (char)w_str[i];
  }
  return str_rec;
}

int calculation_size_str(pars_format *form, int strlen) {
  int size_buf = 0;
  if (form->precision > -1 && form->precision <= strlen) {
    size_buf = form->precision;
  } else {
    size_buf = strlen;
  }
  if (form->width > size_buf) {
    size_buf = form->width;
  }
  return size_buf;
}

char *processing_float(va_list ap, pars_format *form) {
  char *buf = S21_NULL;
  long double number = va_arg(ap, double);
  buf = calloc(
      calculation_size_double(form, length_double(number, form->precision)) + 1,
      sizeof(char));
  doubl_trans_str(number, buf, *form);
  return buf;
}

int length_double(double number, int precision) {
  int length = 0;
  length += int_len(floor(number)) + 1;
  if (precision > 0) {
    length += 2 * precision;
  } else if (precision == -1) {
    length += 2 * 6;
  }
  return length;
}

int calculation_size_double(pars_format *form, int str_length) {
  int buf = 0;
  if (form->width >= str_length) {
    buf = form->width + 1;
  } else {
    buf = str_length;
  }
  return buf;
}

char *doubl_trans_str(long double number, char *buf, pars_format form) {
  int index = 0;
  int sign = 1;
  if (isnan(number)) {
    buf[0] = 'n';
    buf[1] = 'a';
    buf[2] = 'n';
    index = 3;
  }

  if (number < 0) {
    sign = -1;
    number = number * (-1);
  }

  if (form.precision == -1) form.precision = 6;
  if (number == 0) {
    for (int i = 0; i < form.precision; i++) {
      buf[index++] = '0';
    }
    if (form.precision > 0) buf[index++] = '.';
    buf[index++] = '0';
  }

  int minus = 0;
  if (form.precision != -1) {
    if (number < 1 && number > 0) {
      minus = 1;
      number += 1;
    }
    number = ceil(number * pow(10, form.precision) - 0.5);
  }
  long long int number_one = (long long int)number;

  int rem = 0;
  while (number_one > 0) {
    rem = number_one % 10;
    if ((index == form.precision) && (form.precision != 0)) {
      buf[index++] = '.';
    }
    if ((index == form.precision + 1) && minus) {
      buf[index++] = '0';
    } else {
      buf[index++] = rem + '0';
    }
    number_one = number_one / 10;
  }

  if (sign == -1) {
    buf[index++] = '-';
  } else if (form.flag_plus) {
    buf[index++] = '+';
  } else if (form.flag_space) {
    buf[index++] = ' ';
  }
  if (!form.flag_minus) {
    while (index < form.width) {
      buf[index++] = ' ';
    }
    buf[index] = '\0';
    invert_str(buf, index);
  } else {
    invert_str(buf, index);
    while (index < form.width) {
      buf[index++] = ' ';
    }
    buf[index] = '\0';
  }
  return buf;
}

int int_len(long int num) {
  int res = 0;
  if (num < 0) num *= -1;
  while (num > 0) {
    res++;
    num = num / 10;
  }
  return res;
}

char *proc_unsign_int(va_list ap, pars_format form) {
  unsigned long int num = va_arg(ap, unsigned long int);
  char *buf = S21_NULL;

  buf = calloc(find_buf_size_int(form, unsign_len_int(num)) + 10, sizeof(char));
  if (form.length == -1) {
    unsigned int new_num = (unsigned int)num;
    unsign_long_itoa(new_num, buf, 10, form);
  } else if (form.length == 'h') {
    unsigned short int new_num = (unsigned short int)num;
    unsign_long_itoa(new_num, buf, 10, form);
  } else {
    unsigned long int new_num = num;
    unsign_long_itoa(new_num, buf, 10, form);
  }

  return buf;
}

int find_buf_size_int(pars_format form, int strlen) {
  int buf_size = 0;
  if (form.precision >= form.width && form.precision >= strlen) {
    buf_size = form.precision + 1;
  } else if (form.width >= form.precision && form.width >= strlen) {
    buf_size = form.width + 1;
  } else
    buf_size = strlen;
  return buf_size;
}

int unsign_len_int(unsigned long int number) {
  int result = 0;
  while (number > 0) {
    result++;
    number = number / 10;
  }
  return result;
}

char *unsign_long_itoa(unsigned long int number, char *buf, int basis,
                       pars_format form) {
  int index = 0;
  if (number == 0) {
    buf[index] = '0';
    index++;
    buf[index] = '\0';
  }
  int remainder = 0;
  while (number != 0) {
    remainder = number % basis;
    buf[index++] = remainder + '0';
    number = number / basis;
  }
  while (index < form.precision) {
    buf[index++] = '0';
  }
  if (!form.flag_minus) {
    while (index < form.width) {
      buf[index++] = ' ';
    }
    buf[index] = '\0';
    invert_str(buf, index);
  } else {
    invert_str(buf, index);
    while (index < form.width) {
      buf[index++] = ' ';
    }
    buf[index] = '\0';
  }
  return buf;
}

void invert_str(char *str, int len) {
  int start = 0;
  int end = len - 1;
  while (start < end) {
    swap_chars(str + start, str + end);
    start++;
    end--;
  }
}

void swap_chars(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

char *proc_signed_int(va_list ap, pars_format form) {
  long int num = va_arg(ap, long int);
  char *buf = S21_NULL;
  buf = calloc(find_buf_size_int(form, int_len(num)) + 10, sizeof(char));
  if (form.length == -1) {
    int new_num = (int)num;
    long_itoa(new_num, buf, 10, form);
  } else if (form.length == 'h') {
    short int new_num = (short int)num;
    long_itoa(new_num, buf, 10, form);
  } else {
    long int new_num = num;
    long_itoa(new_num, buf, 10, form);
  }
  return buf;
}

char long_itoa(long int num, char *buf, int basis, pars_format form) {
  int index = 0;
  int sign = 1;
  if (num == 0 && form.precision != 0) {
    buf[index] = '0';
    index++;
    buf[index] = '\0';
  }
  if (num < 0) {
    sign = -1;
    num = num * (-1);
  }
  int remined;
  while (num != 0) {
    remined = num % basis;
    buf[index++] = remined + '0';
    num = num / basis;
  }
  while (index < form.precision) {
    buf[index++] = '0';
  }
  if (sign == -1) {
    buf[index++] = '-';
  } else if (form.flag_plus) {
    buf[index++] = '+';

  } else if (form.flag_space) {
    buf[index++] = ' ';
  }
  if (!form.flag_minus) {
    while (index < form.width) {
      buf[index++] = ' ';
    }
    buf[index] = '\0';
    invert_str(buf, index);
  } else {
    invert_str(buf, index);
    while (index < form.width) {
      buf[index++] = ' ';
    }
    buf[index] = '\0';
  }
  return *buf;
}
