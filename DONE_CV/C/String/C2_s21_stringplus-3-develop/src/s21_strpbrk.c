/*
The strpbrk() function shall locate the first occurrence in the string pointed
to by s1 of any byte from the string pointed to by s2.

Return value: Upon successful completion, strpbrk() shall return a pointer to
the byte or a null pointer if no byte from s2 occurs in s1.

*/

#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  for (char *back_ptr = (char *)str2; *str1 != *back_ptr && *str1 != '\0';
       str1++) {
    for (back_ptr = (char *)str2; *str1 != *back_ptr && *back_ptr != '\0';
         back_ptr++)
      ;
    if (*str1 == *back_ptr) str1--;
  }

  return (*str1 == '\0') ? S21_NULL : (char *)str1;
}