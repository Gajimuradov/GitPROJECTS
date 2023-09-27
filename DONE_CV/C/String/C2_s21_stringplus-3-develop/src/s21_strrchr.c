
/*
The strrchr() function shall locate the last occurrence of c (converted to a
char) in the string pointed to by s. The terminating NUL character is considered
to be part of the string.

Return value: Upon successful completion, strrchr() shall return a pointer to
the byte or a null pointer if c does not occur in the string.

*/

#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *end_pointer = (char *)str + s21_strlen(str);
  for (; *end_pointer != c && end_pointer != str; end_pointer--)
    ;

  return ((end_pointer == str && *end_pointer != c) ? S21_NULL
                                                    : (char *)end_pointer);
}