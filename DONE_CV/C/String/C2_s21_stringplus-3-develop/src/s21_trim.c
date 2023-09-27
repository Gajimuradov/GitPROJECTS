#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_string = S21_NULL;
  if (src) {
    if (trim_chars && s21_strlen(trim_chars)) {
      s21_size_t src_len = s21_strlen(src);
      const char *src_end = src + src_len;
      while (src == s21_strpbrk(src, trim_chars)) {
        ++src;
      }
      if (src != src_end) {
        --src_end;
        while (src_end == s21_strpbrk(src_end, trim_chars)) {
          --src_end;
        }
        ++src_end;
      } else {  // так же надо выделить память под null иначе сега
        new_string = S21_NULL;
      }
      new_string = calloc(src_end - src + 1, sizeof(char));
      char *temp_str = new_string;
      while (src != src_end) {
        *(temp_str++) = *(src++);
      }
      *temp_str = '\0';
    } else {
      new_string = s21_trim(src, " \t\n");
    }
  }
  return new_string;
}
