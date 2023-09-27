/*
The strchr() function shall locate the first occurrence of c (converted to a
char) in the string pointed to by s. The terminating NUL character is considered
to be part of the string.

Return value: Upon completion, strchr() shall return a pointer to the byte, or a
null pointer if the byte was not found.
*/

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (; *str != c && *str != '\0'; str++)
    ;

  return ((*str == '\0' && *str != c) ? S21_NULL : (char *)str);
}