#include "s21_string.h"

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  if (n == 0) return 0;
  char* first = (char*)str1;
  char* second = (char*)str2;
  int result = 0;
  int flag = 1;
  do {
    if (*first != *second) {
      result = (*first - *(second));
      flag = 0;
    }
    if (*first == 0) {
      flag = 0;
    }
    first++;
    second++;
  } while (--n != 0 && flag);
  return result;
}
