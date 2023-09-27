#include "s21_sprintf.h"

char *s21_parser(char *str, pars_format *form) {
  form->percent = 0;
  int work = 1;
  char *point = pars_flags(str, form);
  if (form->error || form->percent) {
    work = 0;
  }
  if (work) {
    if (*point == '.') {
      point++;
      point = pars_precision(point, form);
    } else {
      point = pars_width(point, form);
      if (!form->error && *point == '.') {
        point++;
        point = pars_precision(point, form);
      }
    }
    if (form->error) {
      work = 0;
    }
  }
  if (work) {
    point = pars_length(point, form);
    if (form->error) work = 0;
  }
  if (work) {
    point = pars_specifier(point, form);
    if (form->error) work = 0;
  }
  if (!work && !form->percent) point = S21_NULL;
  return point;
}

char *pars_flags(char *str, pars_format *form) {
  int work = 1;
  char *point = str;
  if (*point == '%') {
    work = 0;
    form->percent = 1;
  }
  while (work) {
    switch (*point) {
      case '-':
        form->flag_minus = 1;
        break;
      case '+':
        form->flag_plus = 1;
        break;
      case ' ':
        form->flag_space = 1;
        break;
      case '\0':
        work = 0;
        form->error = 1;
        break;
      default:
        work = 0;
        break;
    }
    if (work) point++;
  }
  return point;
}

char *pars_width(char *str, pars_format *form) {
  int work = 1;
  int count = 0;
  char *point = str;
  int mass_num[100] = {0};
  int width = 0;
  while (work) {
    if (*point >= 48 && *point <= 57) {
      mass_num[count] = *point - 48;
      count++;
      point++;
    } else {
      work = 0;
      if (*point == '\0' ||
          (*point != '.' && *point != 'c' && *point != 'd' && *point != 'f' &&
           *point != 's' && *point != 'u' && *point != 'h' && *point != 'l')) {
        form->error = 1;
      }
    }
  }
  int const_count = count;
  for (int i = 0; i < const_count; i++, count--) {
    width += ((int)mass_num[i] * pow(10, count - 1));
  }
  form->width = width;
  return point;
}

char *pars_precision(char *str, pars_format *form) {
  int work = 1;
  int count = 0;
  char *point = str;
  int mass_num[100] = {0};
  int precision = 0;

  while (work) {
    if (*point >= 48 && *point <= 57) {
      mass_num[count] = *point - 48;
      count++;
      point++;
    } else {
      work = 0;
      if (*point == '\0' ||
          (*point != '.' && *point != 'c' && *point != 'd' && *point != 'f' &&
           *point != 's' && *point != 'u' && *point != 'h' && *point != 'l'))
        form->error = 1;
    }
  }
  int const_count = count;
  for (int i = 0; i < const_count; i++, count--) {
    precision += ((int)mass_num[i] * pow(10, count - 1));
  }
  if (const_count) {
    form->precision = precision;
  } else {
    form->precision = 0;
  }
  return point;
}

char *pars_length(char *str, pars_format *form) {
  int work = 1;
  char *point = str;
  switch (*point) {
    case 'h':
      form->length = 'h';
      break;
    case 'l':
      form->length = 'l';
      break;
    default:
      work = 0;
      break;
  }
  if (work) point++;
  if (*point == '\0' || (*point != '.' && *point != 'c' && *point != 'd' &&
                         *point != 'f' && *point != 's' && *point != 'u'))
    form->error = 1;
  return point;
}

char *pars_specifier(char *str, pars_format *form) {
  int work = 1;
  char *point = str;
  switch (*point) {
    case 'c':
      form->specifier = 'c';
      break;
    case 'd':
      form->specifier = 'd';
      break;
    case 'f':
      form->specifier = 'f';
      break;
    case 's':
      form->specifier = 's';
      break;
    case 'u':
      form->specifier = 'u';
      break;
    default:
      work = 0;
      form->error = 1;
      break;
  }
  if (work) point++;
  return point;
}
