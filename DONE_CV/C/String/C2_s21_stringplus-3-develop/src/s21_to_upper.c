#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  int len = s21_strlen(str);
  char *p_str = (char *)malloc((len + 1) * sizeof(char));
  if (p_str == S21_NULL) {
    return S21_NULL;
  }

  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      p_str[i] = str[i] - 32;  // Преобразование символа в верхний регистр
    } else {
      p_str[i] = str[i];  // Копирование символа без изменений
    }
  }
  p_str[len] = '\0';  // Добавление завершающего нулевого символа

  return p_str;  // Возвращение указателя на начало преобразованной строки
}
