#ifndef S21_DECIMAL
#define S21_DECIMAL
#include <stdio.h>
#define UINT_MAX 4294967295
typedef struct {
  unsigned int bits[4];
  // bits[0] - мантиса
  // bits[1] - мантиса
  // bits[2] - мантиса
  // bits[3] - знаковый бит и степень
} s21_decimal;

typedef union {
  int uin_t;
  float floa_t;
} s21_float_bits;

typedef enum {
  unknown,
  plus_plus,
  minus_minus,
  plus_minus,
  minus_plus
} variable_sign;

typedef enum { LESS, GREATER, EQUAL } compare_code;
typedef enum { OK, ERROR } another_code;

void printBinary(s21_decimal dcml);
int check_negative_bit(s21_decimal value);
int s21_shift_scale_str(char *buffer, const int num);
void s21_toggle_bit(s21_decimal *value, const int num);
int check_sign_values(s21_decimal *value_1, s21_decimal *value_2);

//----------------------------//
int s21_count_filled_bit(int *value);
int get_bit(unsigned int value, int BitNumber);
void set_0_bit(unsigned int *value, int BitNumber);
void count10_to_bin(int *count_10, int *count_10_bit);
void write_float_decimal_exp_more(int *result, s21_decimal *dst, int index,
                                  int bit);
void add_div_10(int *result_arr, int *exp_1, int *count_bit);
void set_1_bit(unsigned int *value, int BitNumber);
void fill_arr(int *value_1_arr, s21_decimal value_1, int *value_2_arr,
              s21_decimal value_2);

void init(int *result);
//----------------------add----------------------//
int comparing_numbers(int sign_indx, s21_decimal *value_1,
                      s21_decimal *value_2);
int add_less_1010(int *arr_help, int *arr_10);
int add_main(s21_decimal value_1, int exp_1, s21_decimal value_2, int exp_2,
             s21_decimal *result);
void s21_mul_1010(int *arr_help, int *arr_help_copy, int *arr_10);
void add_similar_sign(int *result_arr, int *value_1_arr, int *value_2_arr,
                      int *index, int *count_bit);
void add_difference_sign(int *result_arr, int *value_1_arr, int *value_2_arr,
                         int *index, int *count_bit, int greater);
void s21_set_sign_add(int sign, s21_decimal *result, int greater,
                      int *result_arr);
int s21_ret_max_count_bit_and_fill(int *value_1_arr, int *value_2_arr);
//-----------mul-----------------//
int s21_set_exp(s21_decimal *value, int result);

//------------------------------------//
/*Arithmetic
    ВОЗВРАЩАЮТ КОДЫ ОШИБОК:
    0 - OK
    1 - число слишком велико или равно бесконечности
    2 - число слишком мало или равно отрицательной бесконечности
    3 - деление на 0
    Уточнение про числа, не вмещающиеся в мантиссу:

    При получении чисел, не вмещающихся в мантиссу при арифметических операциях,
   использовать банковское округление (например,
   79,228,162,514,264,337,593,543,950,335 - 0.6 =
   79,228,162,514,264,337,593,543,950,334)
*/
int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // +
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // -
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // *
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // /

/*Comparisons
    ВОЗВРАЩАЮТ КОДЫ ОШИБОК:
    0 - FALSE
    1 - TRUE
*/
int s21_is_less(s21_decimal, s21_decimal);              // <
int s21_is_less_or_equal(s21_decimal, s21_decimal);     // <=
int s21_is_greater(s21_decimal, s21_decimal);           // >
int s21_is_greater_or_equal(s21_decimal, s21_decimal);  // >=
int s21_is_equal(s21_decimal, s21_decimal);             // ==
int s21_is_not_equal(s21_decimal, s21_decimal);         // !=

/*Convert
    ВОЗВРАЩАЮТ КОДЫ ОШИБОК:
    0 - OK
    1 - ошибка конвертации

    Уточнения:
    Уточнение про преобразование числа типа float:

    Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение, равное
   0 Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
   или равны бесконечности, вернуть ошибку При обработке числа с типом float
   преобразовывать все содержащиеся в нём значимые десятичные цифры. Если таких
   цифр больше 7, то значение числа округляется к ближайшему, у которого не
   больше 7 значимых цифр.

    Уточнение про преобразование из числа типа decimal в тип int:

    Если в числе типа decimal есть дробная часть, то её следует отбросить
   (например, 0.9 преобразуется 0)
*/

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
/*Others
    ВОЗВРАЩАЮТ КОДЫ ОШИБОК:
    0 - OK
    1 - ошибка вычисления
*/
int s21_floor(s21_decimal value,
              s21_decimal *result);  // Округляет указанное Decimal число до
                                     // ближайшего целого числа в сторону
                                     // отрицательной бесконечности.
int s21_round(
    s21_decimal value,
    s21_decimal *result);  // Округляет Decimal до ближайшего целого числа.
int s21_truncate(s21_decimal value,
                 s21_decimal *result);  // Возвращает целые цифры указанного
                                        // Decimal числа; любые дробные цифры
                                        // отбрасываются, включая конечные нули.
int s21_negate(s21_decimal value,
               s21_decimal *result);  // Возвращает результат умножения
                                      // указанного Decimal на -1.

// HELP FUNCTIONS

int s21_mult_by_10(s21_decimal *dest);
int s21_div_by_10(s21_decimal *dest);
char s21_is_zero(const s21_decimal *num1);
unsigned int s21_get_sign(const s21_decimal *dec);
unsigned int s21_get_exp(const s21_decimal *dec);
unsigned int s21_get_bit(const s21_decimal *dec, int bit);
void decimal_copy(const s21_decimal *src, s21_decimal *dst);
int normalization(const s21_decimal *number1, const s21_decimal *number2,
                  s21_decimal *new_num1, s21_decimal *new_num2);
char s21_compare(const s21_decimal *dec1, const s21_decimal *dec2);
void s21_decimal_to_zero(s21_decimal *dst);
void s21_set_decimal_to_zero(s21_decimal *dec);
int get_decimal(int i, s21_decimal *value);
void set_exp(int exp, s21_decimal *dest);
void set_sign(int sign, s21_decimal *dest);
int sum_mantissa(s21_decimal *dec1, s21_decimal *dec2, s21_decimal *res);
void set_decimal(int i, int x, s21_decimal *value);
int dec_div_10(s21_decimal *src);
void shift_left(s21_decimal *dec);
void s21_set_bit(s21_decimal *value, int i, int x);
#endif
