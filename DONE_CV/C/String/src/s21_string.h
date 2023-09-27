#ifndef S21_STRING  // S21_STRING
#define S21_STRING  // S21_STRING

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define S21_NULL ((void *)0)
#define NULL_STR "(null)"
typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
// используется для поиска первого вхождения определенного символа
// 'с'(беззнаковый тип) в первых n байтах блока памяти, на который указывает
// аргумент str.

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
// Сравнивает первые n байтов str1 и str2.

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
// Копирует n символов из src в dest.

void *s21_memset(void *str, int c, s21_size_t n);
// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.

char *s21_strncat(char *dest, const char *src, s21_size_t n);
// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

char *s21_strchr(const char *str, int c);
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
// Сравнивает не более первых n байтов str1 и str2.

char *s21_strncpy(char *dest, const char *src, s21_size_t n);
// Копирует до n символов из строки, на которую указывает src, в dest.

s21_size_t s21_strcspn(const char *str1, const char *str2);
// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.

char *s21_strerror(int errnum);
// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.

s21_size_t s21_strlen(const char *str);
// Вычисляет длину строки str, не включая завершающий нулевой символ.

char *s21_strpbrk(const char *str1, const char *str2);
// Если один из символов str2 найден str1, функция возвращает указатель на
// первое вхождение этого символа. Если ни одного символа из str2 не найдено в
// str1, функция возвращает NULL.

char *s21_strrchr(const char *str, int c);
// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.

char *s21_strstr(const char *haystack, const char *needle);
// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.

char *s21_strtok(char *str, const char *delim);
// Разбивает строку str на ряд токенов, разделенных delim.

int s21_sprintf(char *buf, const char *format, ...);
// Функция sprintf() идентична printf(), за исключением того, что вывод
// производится в массив, указанный аргументом buf. Возвращаемая величина равна
// количеству символов, действительно занесенных в массив.

void *s21_to_upper(const char *str);
// Возвращает копию строки (str)(a-z), преобразованной в верхний регистр. В
// случае какой-либо ошибки следует вернуть значение NULL

void *s21_to_lower(const char *str);
// void *to_lower(const char *str), Возвращает копию строки (str)(A-Z),
// преобразованной в нижний регистр. В случае какой-либо ошибки следует вернуть
// значение NULL

void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

#endif  // S21_STRING
