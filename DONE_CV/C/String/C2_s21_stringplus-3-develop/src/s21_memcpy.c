#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
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
