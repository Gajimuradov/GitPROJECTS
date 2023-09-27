#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int mcm = 0;
  char *p1 = (char *)str1;
  char *p2 = (char *)str2;
  for (s21_size_t i = 0; i < n && mcm == 0; i++) {
    if (p1[i] != p2[i]) {
      mcm = p1[i] - p2[i];
    }
  }
  return mcm;
}