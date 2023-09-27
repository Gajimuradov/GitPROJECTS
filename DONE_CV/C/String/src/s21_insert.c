#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int err = 0;
  char *new_str = S21_NULL;
  if (src && str && start_index <= (s21_strlen(src)) && src != str) {
    new_str =
        (char *)calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    s21_size_t i = 0;
    for (; i < start_index; i++) {
      new_str[i] = src[i];
    }
    s21_size_t end = i;
    for (s21_size_t j = 0; j < s21_strlen(str); j++, i++) {
      new_str[i] = str[j];
    }
    for (; end < s21_strlen(src); end++, i++) {
      new_str[i] = src[end];
    }
    new_str[s21_strlen(new_str)] = '\0';
  } else {
    err = 1;
  }
  return err ? S21_NULL : new_str;
}
