#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *p_strstr = S21_NULL;
  unsigned char flag = 0;

  if (*needle == '\0') {
    return (char *)haystack;
  }

  for (; *haystack != '\0' && flag != 1; haystack++) {
    if (*haystack == *needle) {
      const char *temp_haystack =
          haystack;  // Фиксируем указатель на первом вхождении подстроки
      const char *temp_needle = needle;  // Фиксируем подстроку для правильного
                                         // условия сравнения со строкой
      flag = 1;

      while (*temp_needle != '\0' && *temp_haystack != '\0' &&
             *temp_needle == *temp_haystack) {
        temp_needle++;
        temp_haystack++;
      }

      if (*temp_needle == '\0') {
        p_strstr = haystack;
      } else {
        flag = 0;
      }
    }
  }

  if (flag == 0) {
    p_strstr = S21_NULL;
  }

  return (char *)p_strstr;
}
