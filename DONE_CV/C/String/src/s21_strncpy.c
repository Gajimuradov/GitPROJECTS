#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (n != 0) {
    char *d = dest;
    const char *s = src;
    do {
      n--;
      *d++ = *s++;

      if (*s == '\0' && n > 0) {
        *d++ = *s++;
        break;
      }

    } while (n);
  }

  return dest;
}
