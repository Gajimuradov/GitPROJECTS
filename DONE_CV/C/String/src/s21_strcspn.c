#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  long long current = -1;
  for (s21_size_t i = 0; i <= str1_len; i++) {
    for (s21_size_t j = 0; j <= str2_len; j++) {
      if (str1[i] == str2[j]) {
        current = i;
        break;
      }
    }
    if (current > -1) break;
  }
  return current;
}