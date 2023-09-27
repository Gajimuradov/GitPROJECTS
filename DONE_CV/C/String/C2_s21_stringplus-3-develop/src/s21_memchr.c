/*
The memchr() function shall locate the first occurrence of c (converted to an
unsigned char) in the initial n bytes (each interpreted as unsigned char)
pointed to by s.

Implementations shall behave as if they read the memory byte by byte from the
beginning of the bytes pointed to by s and stop at the first occurrence of c (if
it is found in the initial n bytes).

Return value: The memchr() function shall return a pointer to the located byte,
or a null pointer if the byte is not found.
*/

#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *str_ptr = (void *)str;
  for (s21_size_t i = 1;
       *str_ptr != (unsigned char)c && *str_ptr != '\0' && i < n;
       i++, str_ptr++)
    ;
  return (*str_ptr != (unsigned char)c || n == 0) ? S21_NULL : (void *)str_ptr;
}