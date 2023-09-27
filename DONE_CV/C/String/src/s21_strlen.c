#include "s21_string.h"

s21_size_t s21_strlen(const char *str1) {
  s21_size_t i = 0;
  for (i = 0; str1[i] != '\0'; i++)
    ;
  return i;
}
