#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  char *tmp_str = str;
  char *tmp_format = (char *)format;
  while (*tmp_format != '\0') {
    if (*tmp_format == '%') {
      pars_format form = {0, 0, 0, -1, -1, -1, -1, 0, 0};
      tmp_format = s21_parser(tmp_format + 1, &form);
      if (form.percent) {
        *tmp_str = '%';
        tmp_str++;
        tmp_format++;
      } else {
        char *buf = s21_transfer_buf(ap, &form);
        int length_buf = s21_strlen(buf);
        for (int i = 0; i < length_buf; i++) {
          *tmp_str = buf[i];
          tmp_str++;
        }
        free(buf);
      }
    } else {
      *tmp_str = *tmp_format;
      tmp_format++;
      tmp_str++;
    }
    if (*tmp_format == '\0') *tmp_str = *tmp_format;
  }
  va_end(ap);
  int len = (int)s21_strlen(str);
  return len;
}
