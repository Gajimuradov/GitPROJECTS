#include "s21_string.h"

// реализовал немного иначе, чем s21_to_upper, но принцип тот же
void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  int len = s21_strlen(str);
  char *p_str = (char *)malloc((len + 1) * sizeof(char));
  if (p_str == S21_NULL) {
    return S21_NULL;
  }

  char *result = p_str;  // Сохраняем указатель на начало выделенной памяти

  while (*str != '\0') {
    if (*str >= 'A' && *str <= 'Z') {
      *p_str = *str + 32;  // Преобразование символа в верхний регистр
    } else {
      *p_str = *str;  // Копирование символа без изменений
    }
    str++;
    p_str++;
  }
  *p_str = '\0';  // Добавление завершающего нулевого символа

  return result;  // Возвращение указателя на начало преобразованной строки
}
