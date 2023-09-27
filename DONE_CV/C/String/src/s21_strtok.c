#include "s21_string.h"

int delim_check(char c, const char *delim) {
  int flag_return = 0;
  const char *temp_delim = delim;
  while (*temp_delim != '\0') {
    if (*temp_delim == c) {
      flag_return = 1;
      break;
    }
    ++temp_delim;
  }
  return flag_return;
}

char *s21_strtok(char *str, const char *delim) {
  static char *p_str = S21_NULL;
  if (str == S21_NULL && p_str == S21_NULL) {
    return S21_NULL;
  }
  static int f_last = 0;
  if (str != S21_NULL) {
    p_str = str;
    f_last = 0;
  }
  while (delim_check(*p_str, delim)) {
    ++p_str;
  }

  if (*p_str == '\0') f_last = 1;
  char *start_token = p_str;
  const char *p_delim = delim;
  int found_delim = 0;
  while (*p_str != '\0') {
    while (*p_delim != '\0') {
      if (*p_delim == *p_str) {
        found_delim = 1;
        break;
      }
      ++p_delim;
    }
    if (found_delim) {
      break;
    }
    p_delim = delim;
    ++p_str;
  }
  if (found_delim) {
    *p_str = '\0';
    ++p_str;
  } else if (f_last) {
    start_token = S21_NULL;
  } else {
    f_last = 1;
  }
  return start_token;
}
