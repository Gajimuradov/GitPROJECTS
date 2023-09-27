#include <check.h>
#include <stdlib.h>

#include "s21_decimal.h"
#define INT_MAX 2147483647
#define COUNT_FUNC 15

START_TEST(add_test_1) {
  s21_decimal expected = {{21, 0, 0, 0}};
  s21_decimal value_1 = {{7, 0, 0, 0}};
  s21_decimal value_2 = {{14, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_2) {
  s21_decimal expected = {{7, 0, 0, 0}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_3) {
  s21_decimal expected = {{21, 0, 0, 0x80000000}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(-14, &value_2);
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_4) {
  s21_decimal expected = {{7, 0, 0, 0}};
  expected.bits[3] = 1 << 31;
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(7, &value_1);
  s21_from_int_to_decimal(-14, &value_2);
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_5) {
  s21_decimal expected = {{1234235, 0, 0, 0}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(0, &value_1);
  s21_from_int_to_decimal(1234235, &value_2);
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_6) {
  s21_decimal expected = {{0xFFFFFFFC, 0x1, 0x0, 0x0}};
  s21_decimal value_1 = {{4294967294, 0, 0, 0}};
  s21_decimal value_2 = {{4294967294, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal expected = {{0xFFFFFFFC, 0x1, 0x0, 0x0}};
  s21_decimal value_1 = {{4294967294, 0, 0, 0}};
  s21_decimal value_2 = {{4294967294, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_8) {
  s21_decimal expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal value_2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(add_test_9) {
  s21_decimal expected = {{0x7B17B1E7, 0xFA9FC8E1, 0x000059DA, 0x00010000}};
  s21_decimal value_1 = {{0x5316B465, 0x8584BAD5, 0x000059AB, 0x00010000}};
  s21_decimal value_2 = {{0x37334C8D, 0xBEE91B01, 0x00000004, 0x00000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST
START_TEST(add_test_10) {
  s21_decimal expected = {
      {0x00000401, 0x00000000, 0x00000000, 0x00010000}};  // 102.5
  s21_decimal value_1 = {
      {0x00000019, 0x00000000, 0x00000000, 0x00010000}};  // 2.5
  s21_decimal value_2 = {
      {0x00000064, 0x00000000, 0x00000000, 0x00000000}};  // 100
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST
START_TEST(add_test_11) {
  s21_decimal expected = {
      {0x00004F29, 0x00000000, 0x00000000, 0x00020000}};  // 202.65
  s21_decimal value_1 = {
      {0x00000183, 0x00000000, 0x00000000, 0x00020000}};  // 3.87
  s21_decimal value_2 = {
      {0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};  // 198.78
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST
START_TEST(add_test_12) {
  s21_decimal expected = {
      {0x0669F309, 0x00052ABA, 0x00000000, 0x00070000}};  // 145435334.3443721
  s21_decimal value_1 = {
      {0x14490831, 0x00048E23, 0x00000000, 0x00070000}};  // 128218122.2172721
  s21_decimal value_2 = {
      {0x164214B7, 0x00000028, 0x00000000, 0x00040000}};  // 17217212.1271
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST
START_TEST(add_test_13) {
  s21_decimal expected = {
      {0x00000023, 0x00000000, 0x00000000, 0x00010000}};  // 3.5
  s21_decimal value_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
  s21_decimal value_2 = {
      {0x00000019, 0x00000000, 0x00000000, 0x00010000}};  // 2.5
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST
START_TEST(add_test_14) {
  s21_decimal expected = {
      {0xAE7C05F9, 0x00000B1C, 0x00000000, 0x00070000}};  // 1221781.4353401
  s21_decimal value_1 = {
      {0x77D5E3AA, 0x0000011C, 0x00000000, 0x00060000}};  // 1221781.218218
  s21_decimal value_2 = {
      {0x00212155, 0x00000000, 0x00000000, 0x00070000}};  // 0.2171221
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST
START_TEST(test_add) {
  static s21_decimal num1[] = {
      {{0x00000001, 0x00000000, 0x00000000,
        0x001C0000}},  // 0.0000000000000000000000000001
      {{0x000F4240, 0x00000000, 0x00000000,
        0x001C0000}},  // 0.0000000000000000000001000000
      {{0x80000000, 0x80000000, 0x80000000,
        0x00000000}},  // 39614081266355540835774234624
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x00000000}},  // 79228162514264337593543950335
      {{0x1422CF6C, 0x000001FC, 0x00000000, 0x80030000}},  // -2182181212.012
      {{0x2564B1EA, 0x3927F1F3, 0x041C50D7,
        0x000B0000}},  // 12721717217217217.21821901290
      {{0x0001869F, 0x00000000, 0x00000000, 0x00050000}},  // 0.99999
      {{0x0098967E, 0x00000000, 0x00000000, 0x80060000}},  // -9.999998
      {{0x000000CF, 0x00000000, 0x00000000, 0x00010000}},  // 20.7
      {{0x000035A3, 0x00000000, 0x00000000,
        0x00170000}}  // 0.00000000000000000013731
  };
  static s21_decimal num2[] = {
      {{0x00000001, 0x00000000, 0x00000000,
        0x001C0000}},  // 0.0000000000000000000000000001
      {{0x000186A0, 0x00000000, 0x00000000,
        0x00140000}},  // 0.00000000000000100000
      {{0x00000001, 0x00000000, 0x00000000,
        0x001C0000}},  // 0.0000000000000000000000000001
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0.0000000000
      {{0xF96C01C5, 0x0007B6B6, 0x00000000, 0x800B0000}},  //-21712.21821882821
      {{0x00033F4A, 0x00000000, 0x00000000, 0x000C0000}},  // 0.000000212810
      {{0x00000001, 0x00000000, 0x00000000, 0x00050000}},  // 0.00001
      {{0x00000002, 0x00000000, 0x00000000, 0x80060000}},  //-0.000002
      {{0x00003F86, 0x00000000, 0x00000000,
        0x00160000}},  // 0.0000000000000000016262
      {{0x0001F8A8, 0x00000000, 0x00000000, 0x00030000}}  // 129.192
  };

  static s21_decimal res[] = {
      // 0
      {{0x00000002, 0x00000000, 0x00000000,
        0x001C0000}},  // 0.0000000000000000000000000002
      {{0x4E81E240, 0x00000918, 0x00000000,
        0x001C0000}},  // 0.0000000000000010000001000000
      {{0x80000000, 0x80000000, 0x80000000,
        0x00000000}},  // 39614081266355540835774234624
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x00000000}},  // 79228162514264337593543950335
      {{0x3015EDC5, 0xD46A37C7, 0x0000000B,
        0x800B0000}},  //-2182202924.23021882821
      {{0x75F2326E, 0x3B8F737F, 0x291B2868,
        0x000C0000}},  // 12721717217217217.218219225710
      {{0x000186A0, 0x00000000, 0x00000000, 0x00050000}},  // 1.00000
      {{0x00989680, 0x00000000, 0x00000000, 0x80060000}},  //-10.000000
      {{0x03603F86, 0x7E1382FF, 0x00002BD5,
        0x00160000}},  // 20.7000000000000000016262
      {{0x828035A3, 0x3C3F28D0, 0x000AAFBF,
        0x00170000}}  // 129.19200000000000000013731
  };

  for (size_t i = 0; i < sizeof(num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp = {{0, 0, 0, 0}};
    int ret = s21_add(num1[i], num2[i], &tmp);
    ck_assert_int_eq(tmp.bits[0], res[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], res[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], res[i].bits[2]);
    ck_assert_int_eq(tmp.bits[3], res[i].bits[3]);
    ck_assert_int_eq(ret, 0);
    printf("add test %ld completed\n", i);
  }
}
END_TEST

START_TEST(test_add_fail) {
  s21_decimal arr1[] = {
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}},

  };
  s21_decimal arr2[] = {
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}},

  };
  for (size_t i = 0; i < sizeof(arr2) / sizeof(s21_decimal); ++i) {
    s21_decimal expected;
    int expected_return = s21_add(arr1[i], arr2[i], &expected);
    ck_assert_int_eq(expected_return, 1);
  }
}
END_TEST

Suite *s21_add_test(void) {
  Suite *s = suite_create("add_test");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, add_test_1);
  tcase_add_test(tc_core, add_test_2);
  tcase_add_test(tc_core, add_test_3);
  tcase_add_test(tc_core, add_test_4);
  tcase_add_test(tc_core, add_test_5);
  tcase_add_test(tc_core, add_test_6);
  tcase_add_test(tc_core, add_test_7);
  tcase_add_test(tc_core, add_test_8);
  tcase_add_test(tc_core, add_test_9);
  tcase_add_test(tc_core, add_test_10);
  tcase_add_test(tc_core, add_test_11);
  tcase_add_test(tc_core, add_test_12);
  tcase_add_test(tc_core, add_test_13);
  tcase_add_test(tc_core, add_test_14);
  tcase_add_test(tc_core, test_add);
  tcase_add_test(tc_core, test_add_fail);
  suite_add_tcase(s, tc_core);

  return s;
}
//-------------------------end_add_test-----------------------//

//-------------------------sub_test-----------------------//

START_TEST(sub_test_1) {
  s21_decimal expected = {{7, 0, 0, 0}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(-14, &value_2);
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(sub_test_2) {
  s21_decimal expected = {{21, 0, 0, 2147483648}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(sub_test_3) {
  s21_decimal expected = {{21, 0, 0, 0}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(7, &value_1);
  s21_from_int_to_decimal(-14, &value_2);
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(sub_test_4) {
  s21_decimal expected = {{7, 0, 0, 0}};
  expected.bits[3] = 1 << 31;
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(sub_test_5) {
  s21_decimal expected = {{14, 0, 0, 0}};
  expected.bits[3] = 1 << 31;
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(0, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(test_sub_success) {
  s21_decimal arr1[] = {{{0x0BC54765, 0x00005AF3, 0x00000000, 0x00150000}},
                        {{0x0BC54765, 0x00005AF3, 0x00000000, 0x80150000}},
                        {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
                        {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
                        {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
                        {{0x075B9B99, 0x00000000, 0x00000000, 0x80000000}},
                        {{0x00000005, 0x00000000, 0x00000000, 0x800F0000}},
                        {{0x00000005, 0x00000000, 0x00000000, 0x000F0000}},
                        {{0x000A392F, 0x00000000, 0x00000000, 0x00030000}},
                        {{0x000A2D77, 0x00000000, 0x00000000, 0x80030000}},
                        {{0x000A2D77, 0x00000000, 0x00000000, 0x80030000}}};
  s21_decimal arr2[] = {{{0x7DEE8001, 0xE103C8A7, 0x00000004, 0x00040000}},
                        {{0x7DEE8001, 0xE103C8A7, 0x00000004, 0x80040000}},
                        {{0xED97E141, 0x000008FA, 0x00000000, 0x00040000}},
                        {{0x00000008, 0x00000000, 0x00000000, 0x00000000}},
                        {{0x00000053, 0x00000000, 0x00000000, 0x80010000}},
                        {{0x0001869E, 0x00000000, 0x00000000, 0x00000000}},
                        {{0x0001869E, 0x00000000, 0x00000000, 0x00000000}},
                        {{0x0001869E, 0x00000000, 0x00000000, 0x80000000}},
                        {{0x05F5DD17, 0x00000000, 0x00000000, 0x00030000}},
                        {{0x05F5DD17, 0x00000000, 0x00000000, 0x80030000}},
                        {{0x000F4235, 0x00000000, 0x00000000, 0x00000000}}};
  s21_decimal result[] = {{{0x24745A60, 0xA11C636F, 0x1D14B54E, 0x800C0000}},
                          {{0x24745A60, 0xA11C636F, 0x1D14B54E, 0x000C0000}},
                          {{0xED980851, 0x000008FA, 0x00000000, 0x80040000}},
                          {{0x00000007, 0x00000000, 0x00000000, 0x80000000}},
                          {{0x0000005D, 0x00000000, 0x00000000, 0x00010000}},
                          {{0x075D2237, 0x00000000, 0x00000000, 0x80000000}},
                          {{0x19830005, 0x6BC04330, 0x00000005, 0x800F0000}},
                          {{0x19830005, 0x6BC04330, 0x00000005, 0x000F0000}},
                          {{0x05EBA3E8, 0x00000000, 0x00000000, 0x80030000}},
                          {{0x05EBAFA0, 0x00000000, 0x00000000, 0x00030000}},
                          {{0x3BA4CC7F, 0x00000000, 0x00000000, 0x80030000}}};
  for (size_t i = 0; i < sizeof(arr2) / sizeof(s21_decimal); ++i) {
    s21_decimal expected;
    int expected_return = s21_sub(arr1[i], arr2[i], &expected);
    for (int j = 0; j != 4; ++j) {
      ck_assert_int_eq(result[i].bits[j], expected.bits[j]);
    }
    ck_assert_int_eq(expected_return, 0);
    printf("sub test %ld completed\n", i);
  }
}
END_TEST

Suite *s21_sub_test(void) {
  Suite *s = suite_create("sub_test");
  ;
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sub_test_1);
  tcase_add_test(tc_core, sub_test_2);
  tcase_add_test(tc_core, sub_test_3);
  tcase_add_test(tc_core, sub_test_4);
  tcase_add_test(tc_core, sub_test_5);
  tcase_add_test(tc_core, test_sub_success);
  suite_add_tcase(s, tc_core);

  return s;
}

//-----------------------------mul_test--------------------------//

START_TEST(mul_test_1) {
  s21_decimal expected = {{14, 0, 0, 0}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(2, &value_1);
  s21_from_int_to_decimal(7, &value_2);
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(test_mul_2) {
  static s21_decimal num1[] = {
      {{0x2296D8D2, 0x09BF56C2, 0x00000000, 0x00090000}},  // i=1
      {{0x64994FA7, 0x6668CAB7, 0x00000000, 0x80140000}},  // i=2
      {{0x82508A73, 0xFA0363EB, 0x00000000, 0x00080000}},  // i=3
      {{0x8F1422E6, 0x6C0CBEE1, 0x00000000, 0x80080000}},  // i=4
      {{0xDC6B659A, 0x9D6ECD4F, 0x00000000, 0x001A0000}},  // i=5
      {{0xA6EFC349, 0xC5458F4F, 0x00000000, 0x80090000}},  // i=6

      {{0x686358F9, 0x49ED6B7B, 0x00000000, 0x000A0000}},  // i=8
      {{0xB4797D5A, 0x5E83A909, 0x00000000, 0x00080000}},  // i=9
      {{0x919EC265, 0x000824B7, 0x00000000, 0x000C0000}},  // i=11
      {{0x00000000, 0x00000000, 0x00000001,
        0x000C0000}},  // 4 num: 18446744.073709551616//14
      {{0xFFFFFFFF, 0xFFFFFFFF, 0x00000000,
        0x800E0000}},  // 5 num: -184467.44073709551615//15
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x000E0000}},  // 6 num: 792281625142643.37593543950335//16
      {{0x10B69765, 0xD35FC2AA, 0x00000000,
        0x80000000}},  // 8 num: -15231106500470937445//17
      {{0x3D63F4EA, 0x48D80BF2, 0x1AB5388A,
        0x00120000}},  // 9 num: 8265692832.127901040256480490//18
      {{0x761189C7, 0x40B595A1, 0x00000000,
        0x80010000}},  // 11 num: -466279750991515079.1//19
      {{0x51922653, 0xA48EE14C, 0xB3EE966B,
        0x801A0000}},  // 12 num: -556.86251443720757965835347539//20
      {{0x0E865C49, 0x00000000, 0x00000000,
        0x80130000}},  // 13 num: -2.43686473E-11//21
      {{0x747E9848, 0xB5B98F6A, 0x4BAAAFC9,
        0x000B0000}},  // 15 num: 234177232609600831.96531087432//23
      {{0x3E744595, 0x00000000, 0x00000000,
        0x00000000}},  // 16 num: 1047807381//24
      {{0xC9F85BF2, 0xF842BE2B, 0x00000000,
        0x00120000}},  // 92 num: 17.889069765150399474//78
      {{0xD0424042, 0x3B2A8A5A, 0x46EA43A1,
        0x00110000}},  // 93 num: 219471587020.27498290988335170//79
  };
  static s21_decimal num2[] = {
      {{0x934017E2, 0xFD5E83B0, 0x00000000, 0x00130000}},  // 1
      {{0x944C3513, 0xC80B61CF, 0x00000000, 0x00070000}},  // 2
      {{0x2B68FF20, 0x6CA9F127, 0x00000000, 0x000C0000}},  // 3
      {{0xD9D543ED, 0xD186532C, 0x00000000, 0x000F0000}},  // 4
      {{0xCBE49CCE, 0xF9378D4F, 0x00000000, 0x80060000}},  // 5
      {{0xAA917E4C, 0x15684E8F, 0x00000000, 0x800D0000}},  // 6

      {{0xD539B200, 0xE86F5F0A, 0x00000000, 0x800C0000}},  // 8
      {{0xC6969B62, 0xB4619C83, 0x00000000, 0x000B0000}},  // 9
      {{0x6652AAA9, 0x00011DB1, 0x00000000, 0x80100000}},  // 11
      {{0x00000000, 0x00000000, 0x00000001,
        0x800E0000}},  // 4 num: -184467.44073709551616//14
      {{0xFFFFFFFF, 0xFFFFFFFF, 0x00000000,
        0x00070000}},  // 5 num: 1844674407370.9551615//15
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x80170000}},  // 6 num: -792281.62514264337593543950335//16
      {{0xC30D4632, 0x8D349C98, 0x00000000,
        0x80130000}},  // 8 num: -1.0174929638058182194//17
      {{0x1A508A19, 0x83168F0E, 0x4BC91053,
        0x800B0000}},  // 9 num: -234544469247327992.09880717849//18
      {{0x6CEB6ABF, 0xB07E3FB2, 0x00000000,
        0x001B0000}},  // 11 num: 1.2717672433304955583E-8//19
      {{0x0F0FF29F, 0x535D7C02, 0x73AA0A2B,
        0x00170000}},  // 12 num: 357963.41541671087555279319711//20
      {{0x3F76C1D7, 0x00000000, 0x00000000,
        0x80090000}},  // 13 num: -1.064747479//21
      {{0x5A90CC18, 0x3AC80DB9, 0x0252A135,
        0x80120000}},  // 15 num: -718863219.767918188542610456//23
      {{0x8DECD279, 0x00000000, 0x00000000,
        0x001B0000}},  // 16 num: 2.381107833E-18//24
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x000E0000}},  // 92 num: 792281625142643.37593543950335//78
      {{0x666A6F93, 0x00000000, 0x00000000,
        0x000A0000}},  // 93 num: 0.1718251411//79
  };

  static s21_decimal res[] = {
      {{0x5532E6FB, 0xF6A62202, 0x296F42C4, 0x00130000}},  // i=1
      {{0xDFC5C0F6, 0x544F79AA, 0x225ED9E8, 0x80110000}},  // i=2
      {{0x692116A1, 0xD6C1CBF7, 0x2D944F01, 0x000A0000}},  // i=3
      {{0x63B0BB99, 0x09F02946, 0x25FB6B60, 0x800D0000}},  // i=4
      {{0xAEC5242A, 0x92E830FC, 0x41D346BE, 0x80160000}},  // i=5
      {{0x13BEFE41, 0xCD6D490A, 0x46DA022C, 0x000D0000}},  // i=6

      {{0xBCD5FD07, 0xF480D7E8, 0x1CD42E63, 0x800C0000}},  // i=8
      {{0x88B20BEF, 0x8DF636B3, 0x1C9A52A6, 0x00090000}},  // i=9
      {{0x01B98A44, 0x936049E7, 0xE8A6E687, 0x801B0000}},  // 11
      {{0x5AB9A207, 0x5EF6EADF, 0x6DF37F67,
        0x80100000}},  // 4 err: 0 res: -3402823669209.3846346337460743//14
      {{0x7ED2A338, 0x5EF6EADE, 0x6DF37F67,
        0x800B0000}},  // 5 err: 0 res: -340282366920938463.42648111928//15
      {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5,
        0x80080000}},  // 6 err: 0 res: -627710173538668076383.57894230//16
      {{0x6A7CCF18, 0x2067A9D8, 0x32134487,
        0x00090000}},  // 8 err: 0 res: 15497543695206238156.001955608//17
      {{0x8D144CB4, 0xDDE18D4C, 0x3EA452C8,
        0x80010000}},  // 9 err: 0 res: -1938672538272881901047200478.8//18
      {{0xF1F481E9, 0x1BD107B7, 0xBF9BC0E8,
        0x80130000}},  // 11 err: 0 res: -5929993135.3930903516785967593//19
      {{0x87ACC18B, 0xCC54C70A, 0x4068B89E,
        0x80140000}},  // 12 err: 0 res: -199336407.58548029423204745611//20
      {{0xFF108A4F, 0x0399CDA3, 0x00000000,
        0x001C0000}},  // 13 err: 0 res: 2.59464557793151567E-11//21
      {{0xDBC24E17, 0xE81DD4D7, 0x3664DFCA,
        0x80020000}},  // 15 err: 0 res: -168341399430078380635147668.71//23
      {{0x1C651D6D, 0x229FD0DC, 0x00000000,
        0x001B0000}},  // 16 err: 0 res: 2.494942362374315373E-9//24
      {{0x1CA62646, 0xF8CA1746, 0x2DCBC7DF,
        0x000C0000}},  // 92 err: 0 res: 14173181265823484.168305518150//78
      {{0xE8D9BDE2, 0xEF8A59F9, 0x79D9970C,
        0x00120000}},  // 93 err: 0 res: 37710736407.199677499290795490//79
  };

  for (size_t i = 0; i < sizeof(num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp = {{0, 0, 0, 0}};
    int ret = s21_mul(num1[i], num2[i], &tmp);
    ck_assert_int_eq(tmp.bits[0], res[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], res[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], res[i].bits[2]);
    ck_assert_int_eq(tmp.bits[3], res[i].bits[3]);
    ck_assert_int_eq(ret, 0);
    printf("mul test %ld completed\n", i);
  }
}
END_TEST

START_TEST(test_mul_success) {
  s21_decimal arr1[] = {
      {{0x000A2D77, 0x00000000, 0x00000000, 0x80030000}},
      {{0x000A2D77, 0x00000000, 0x00000000, 0x00030000}},
      {{0x00004A38, 0x00000000, 0x00000000, 0x00000000}},

  };
  s21_decimal arr2[] = {
      {{0x00000045, 0x00000000, 0x00000000, 0x00000000}},
      {{0x005EE4FB, 0x00000000, 0x00000000, 0x80030000}},
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
  };
  s21_decimal result[] = {
      {{0x02BE4113, 0x00000000, 0x00000000, 0x80030000}},
      {{0xCC2A8FAD, 0x000003C5, 0x00000000, 0x80060000}},
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
  };

  for (size_t i = 0; i < sizeof(arr2) / sizeof(s21_decimal); ++i) {
    s21_decimal expected;
    int expected_return = s21_mul(arr1[i], arr2[i], &expected);
    for (int j = 0; j != 4; ++j) {
      ck_assert_int_eq(result[i].bits[j], expected.bits[j]);
    }
    ck_assert_int_eq(expected_return, 0);
    printf("s_21_mul test %ld completed\n", i);
  }
}
END_TEST

Suite *s21_mul_test(void) {
  Suite *s = suite_create("mul_test");
  ;
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, mul_test_1);
  tcase_add_test(tc_core, test_mul_2);
  tcase_add_test(tc_core, test_mul_success);
  suite_add_tcase(s, tc_core);
  return s;
}

//----------------------------s21_div----------------------------------//

START_TEST(div_test_1) {
  s21_decimal expected = {{2, 0, 0, 0}};
  s21_decimal value_1, value_2;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(7, &value_2);
  int error = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(div_test_2) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{70, 0, 0, 0}};
  s21_set_exp(&value_1, 1);
  s21_set_exp(&value_2, 2);
  int error = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, expected), 1);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(div_test_4) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  set_1_bit(&value_1.bits[3], 31);
  s21_decimal value_2 = {{8, 0, 0, 0}};
  set_1_bit(&value_2.bits[3], 31);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{125, 0, 0, 0}};
  s21_set_exp(&check, 2);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_test_5) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  set_1_bit(&value_1.bits[3], 31);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(div_test_6) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_exp(&value_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1000u, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *s21_div_test(void) {
  Suite *s = suite_create("div_test");
  ;
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, div_test_1);
  tcase_add_test(tc_core, div_test_2);
  tcase_add_test(tc_core, div_test_4);
  tcase_add_test(tc_core, div_test_5);
  tcase_add_test(tc_core, div_test_6);
  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------end div----------------------------//

//--------------------start comparation----------------------------//
START_TEST(test_compassion_less_1) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(324, &value_1);
  s21_from_int_to_decimal(324, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_less_2) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(12332, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_less_3) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(12332, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_less_4) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_less_5) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_less_6) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(7, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_less_7) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_less_8) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(-7, &value_2);
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *s21_less_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("less");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_compassion_less_1);
  tcase_add_test(tc_core, test_compassion_less_2);
  tcase_add_test(tc_core, test_compassion_less_3);
  tcase_add_test(tc_core, test_compassion_less_4);
  tcase_add_test(tc_core, test_compassion_less_5);
  tcase_add_test(tc_core, test_compassion_less_6);
  tcase_add_test(tc_core, test_compassion_less_7);
  tcase_add_test(tc_core, test_compassion_less_8);
  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------end comparation--------------------------//

START_TEST(s21_is_less_or_equal_1) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(324, &value_1);
  s21_from_int_to_decimal(324, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_2) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(12332, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_3) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(12332, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_4) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_5) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_6) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(7, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_7) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_8) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(-14, &value_2);
  int result = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *s21_less_or_equal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("less_or_equal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_is_less_or_equal_1);
  tcase_add_test(tc_core, s21_is_less_or_equal_2);
  tcase_add_test(tc_core, s21_is_less_or_equal_3);
  tcase_add_test(tc_core, s21_is_less_or_equal_4);
  tcase_add_test(tc_core, s21_is_less_or_equal_5);
  tcase_add_test(tc_core, s21_is_less_or_equal_6);
  tcase_add_test(tc_core, s21_is_less_or_equal_7);
  tcase_add_test(tc_core, s21_is_less_or_equal_8);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_compassion_greater_1) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(324, &value_1);
  s21_from_int_to_decimal(324, &value_2);
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_greater_2) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(12332, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_greater_3) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(12332, &value_2);
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_greater_4) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_greater_5) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_greater_6) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(7, &value_2);
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_greater_7) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *s21_greater_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("greater");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_compassion_greater_1);
  tcase_add_test(tc_core, test_compassion_greater_2);
  tcase_add_test(tc_core, test_compassion_greater_3);
  tcase_add_test(tc_core, test_compassion_greater_4);
  tcase_add_test(tc_core, test_compassion_greater_5);
  tcase_add_test(tc_core, test_compassion_greater_6);
  tcase_add_test(tc_core, test_compassion_greater_7);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_compassion_greater_or_equal_1) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(324, &value_1);
  s21_from_int_to_decimal(324, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_greater_or_equal_2) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(12332, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_greater_or_equal_3) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(12332, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_greater_or_equal_4) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_greater_or_equal_5) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(-12332, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_greater_or_equal_6) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(7, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_greater_or_equal_7) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_greater_or_equal_8) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(-7, &value_2);
  int result = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *s21_greater_or_equal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("greater_or_equal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_compassion_greater_or_equal_1);
  tcase_add_test(tc_core, test_compassion_greater_or_equal_2);
  tcase_add_test(tc_core, test_compassion_greater_or_equal_3);
  tcase_add_test(tc_core, test_compassion_greater_or_equal_4);
  tcase_add_test(tc_core, test_compassion_greater_or_equal_5);
  tcase_add_test(tc_core, test_compassion_greater_or_equal_6);
  tcase_add_test(tc_core, test_compassion_greater_or_equal_7);
  tcase_add_test(tc_core, test_compassion_greater_or_equal_8);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_compassion_is_equal_1) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(324, &value_1);
  s21_from_int_to_decimal(324, &value_2);
  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_is_equal_2) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(12332, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_is_equal_3) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_is_equal_4) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(-14, &value_2);
  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_is_equal_5) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(5, &value_1);
  s21_from_int_to_decimal(-5, &value_2);
  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_is_equal_6) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(0, &value_1);
  s21_from_int_to_decimal(0, &value_2);
  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_is_equal_7) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *s21_is_equal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("is_equal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_compassion_is_equal_1);
  tcase_add_test(tc_core, test_compassion_is_equal_2);
  tcase_add_test(tc_core, test_compassion_is_equal_3);
  tcase_add_test(tc_core, test_compassion_is_equal_4);
  tcase_add_test(tc_core, test_compassion_is_equal_5);
  tcase_add_test(tc_core, test_compassion_is_equal_6);
  tcase_add_test(tc_core, test_compassion_is_equal_7);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_compassion_is_not_equal_1) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(324, &value_1);
  s21_from_int_to_decimal(324, &value_2);
  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_is_not_equal_2) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(12332, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_is_not_equal_3) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(14, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_is_not_equal_4) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-14, &value_1);
  s21_from_int_to_decimal(-14, &value_2);
  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_is_not_equal_5) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(5, &value_1);
  s21_from_int_to_decimal(-5, &value_2);
  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_compassion_is_not_equal_6) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(0, &value_1);
  s21_from_int_to_decimal(0, &value_2);
  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_compassion_is_not_equal_7) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(-7, &value_1);
  s21_from_int_to_decimal(14, &value_2);
  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_floor) {
  static s21_decimal arr[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00020000}},  // 0.00
      {{0x075BCD15, 0x00000000, 0x00000000,
        0x00120000}},  // 0.000000000123456789
      {{0x075BCD15, 0x00000000, 0x00000000,
        0x80120000}},  // -0.000000000123456789
      {{0xCF5C048C, 0x004D2BEF, 0x00000000, 0x00070000}},  // 2172188218.2812812
      {{0xFEADBDA2, 0x000001FB, 0x00000000, 0x80060000}},  // -2181821.218210
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x001C0000}}  // 7.9228162514264337593543950335
  };
  static s21_decimal result[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // -1
      {{0x8178F63A, 0x00000000, 0x00000000, 0x00000000}},  // 2172188218
      {{0x214ABE, 0x00000000, 0x00000000, 0x80000000}},    //-2181822
      {{0x00000007, 0x00000000, 0x00000000, 0x00000000}},  // 7
  };
  for (size_t i = 0; i < sizeof(arr) / sizeof(s21_decimal); ++i) {
    s21_decimal value = arr[i];
    s21_decimal tmp;
    int ret = s21_floor(value, &tmp);
    ck_assert_int_eq(result[i].bits[0], tmp.bits[0]);
    ck_assert_int_eq(result[i].bits[1], tmp.bits[1]);
    ck_assert_int_eq(result[i].bits[2], tmp.bits[2]);
    ck_assert_int_eq(result[i].bits[3], tmp.bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(test_truncate) {
  static s21_decimal arr[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00020000}},  // 0.00
      {{0x075BCD15, 0x00000000, 0x00000000,
        0x00120000}},  // 0.000000000123456789
      {{0xCF5C048C, 0x004D2BEF, 0x00000000, 0x00070000}},  // 2172188218.2812812
      {{0xFEADBDA2, 0x000001FB, 0x00000000, 0x80060000}},  // -2181821.218210
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x001C0000}}  // 7.9228162514264337593543950335
  };
  static s21_decimal result[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x8178F63A, 0x00000000, 0x00000000, 0x00000000}},  // 2172188218
      {{0x00214ABD, 0x00000000, 0x00000000, 0x80000000}},  //-2181821
      {{0x00000007, 0x00000000, 0x00000000, 0x00000000}}   // 7
  };
  for (size_t i = 0; i < sizeof(arr) / sizeof(s21_decimal); ++i) {
    s21_decimal value = arr[i];
    s21_decimal tmp;
    int ret = s21_truncate(value, &tmp);
    ck_assert_int_eq(result[i].bits[0], tmp.bits[0]);
    ck_assert_int_eq(result[i].bits[1], tmp.bits[1]);
    ck_assert_int_eq(result[i].bits[2], tmp.bits[2]);
    ck_assert_int_eq(result[i].bits[3], tmp.bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST
START_TEST(test_round) {
  static s21_decimal arr[] = {
      {{0x1FC40A5F, 0xA98FD4BE, 0x00000000,
        0x00020000}},  // 122182182271212611.51
      {{0x1FC40A5D, 0xA98FD4BE, 0x00000000,
        0x00020000}},  // 122182182271212611.49
      {{0x1FC40A5F, 0xA98FD4BE, 0x00000000,
        0x80020000}},  // -122182182271212611.51
      {{0x1FC40A5D, 0xA98FD4BE, 0x00000000,
        0x80020000}},  // -122182182271212611.49
      {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00060000}},  // 4294.967295
      {{0xFFFFFFFF, 0xFFFFFFFF, 0x00000000,
        0x00050000}},  // 184467440737095.51615
  };
  static s21_decimal result[] = {
      {{0x24285C44, 0x01B2140C, 0x00000000, 0x00000000}},  // 122182182271212612
      {{0x24285C43, 0x01B2140C, 0x00000000, 0x00000000}},  // 122182182271212611
      {{0x24285C44, 0x01B2140C, 0x00000000, 0x80000000}},
      //-122182182271212612
      {{0x24285C43, 0x01B2140C, 0x00000000, 0x80000000}},
      //-122182182271212611
      {{0x000010C7, 0x00000000, 0x00000000, 0x00000000}},  // 4295
      {{0xAC471B48, 0x0000A7C5, 0x00000000, 0x00000000}},  // 184467440737096
  };
  for (size_t i = 0; i < sizeof(arr) / sizeof(s21_decimal); ++i) {
    s21_decimal value = arr[i];
    s21_decimal tmp;
    int ret = s21_round(value, &tmp);
    ck_assert_int_eq(result[i].bits[0], tmp.bits[0]);
    ck_assert_int_eq(result[i].bits[1], tmp.bits[1]);
    ck_assert_int_eq(result[i].bits[2], tmp.bits[2]);
    ck_assert_int_eq(result[i].bits[3], tmp.bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST
Suite *s21_another_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("another");

  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_truncate);
  tcase_add_test(tc_core, test_floor);
  tcase_add_test(tc_core, test_round);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(s21_negate_1) {
  int a = 15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(-15, res_a);
}
END_TEST

START_TEST(s21_negate_2) {
  float a = 10.12345;
  float res_a = 0;
  s21_decimal src = {0};
  s21_decimal res = {0};
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  char str_orig[100];
  char str_dec[100];
  snprintf(str_orig, sizeof(str_orig), "%.5f", -a);
  snprintf(str_dec, sizeof(str_dec), "%.5f", res_a);
  ck_assert_str_eq(str_orig, str_dec);
}
END_TEST

START_TEST(s21_negate_3) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src = {0};
  s21_decimal res = {0};
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  char str_orig[100];
  char str_dec[100];
  snprintf(str_orig, sizeof(str_orig), "%.0f", -a);
  snprintf(str_dec, sizeof(str_dec), "%.0f", res_a);
  ck_assert_str_eq(str_orig, str_dec);
}
END_TEST

START_TEST(s21_negate_4) {
  float a = -10.1234e5;
  float res_a = 0;
  s21_decimal src = {0};
  s21_decimal res = {0};
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  char str_orig[100];
  char str_dec[100];
  snprintf(str_orig, sizeof(str_orig), "%.0f", -a);
  snprintf(str_dec, sizeof(str_dec), "%.0f", res_a);
  ck_assert_str_eq(str_orig, str_dec);
}
END_TEST

START_TEST(s21_negate_5) {
  int a = -15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(15, res_a);
}
END_TEST

START_TEST(s21_test_negate_0) {  // 0 * -1 = 0
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  // int equal = s21_is_equal(b, etalon);
  int negate = s21_negate(b, &etalon);
  ck_assert_int_eq(negate, 0);
}
END_TEST

START_TEST(s21_test_negate_1) {  // 1 * -1 = -1
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_2) {  // -1 * -1 = 1
  s21_decimal a = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{1, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_3) {  // 100 * -1 = -100
  s21_decimal a = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_4) {  //
  s21_decimal a = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{100, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_5) {  //
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{UINT_MAX, 0, 0, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_6) {  //
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal etalon = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_negate_7) {  //
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal etalon = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_8) {  //
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(INT_MAX)}};
  s21_decimal etalon = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_2) {
  s21_decimal val = {{0, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_3) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

Suite *s21_negate_test(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_negate");
  tc = tcase_create("case_negate");
  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);

  tcase_add_test(tc, s21_test_negate_0);
  tcase_add_test(tc, s21_test_negate_1);
  tcase_add_test(tc, s21_test_negate_2);
  tcase_add_test(tc, s21_test_negate_3);
  tcase_add_test(tc, s21_test_negate_4);
  tcase_add_test(tc, s21_test_negate_5);
  tcase_add_test(tc, s21_test_negate_6);
  tcase_add_test(tc, s21_test_negate_7);
  tcase_add_test(tc, s21_test_negate_8);

  tcase_add_test(tc, negate_0);
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_is_equal_not_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("is_not_equal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_compassion_is_not_equal_1);
  tcase_add_test(tc_core, test_compassion_is_not_equal_2);
  tcase_add_test(tc_core, test_compassion_is_not_equal_3);
  tcase_add_test(tc_core, test_compassion_is_not_equal_4);
  tcase_add_test(tc_core, test_compassion_is_not_equal_5);
  tcase_add_test(tc_core, test_compassion_is_not_equal_6);
  tcase_add_test(tc_core, test_compassion_is_not_equal_7);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_int_to_decimal) {
  static int src[] = {0,     -1,     1,        -2,         2,
                      32767, -32767, -9999999, 2147483647, -2147483648};
  static s21_decimal res[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000002, 0x00000000, 0x00000000, 0x80000000}},  //-2
      {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 2
      {{0x00007FFF, 0x00000000, 0x00000000, 0x00000000}},  // 32767
      {{0x00007FFF, 0x00000000, 0x00000000, 0x80000000}},  //-32767
      {{0x0098967F, 0x00000000, 0x00000000, 0x80000000}},  //-9999999
      {{0x7FFFFFFF, 0x00000000, 0x00000000, 0x00000000}},  // 2147483647
      {{0x80000000, 0x00000000, 0x00000000, 0x80000000}}   //-2147483648
  };
  for (size_t i = 0; i < sizeof(res) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_from_int_to_decimal(src[i], &tmp);
    ck_assert_int_eq(tmp.bits[0], res[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], res[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], res[i].bits[2]);
    ck_assert_int_eq(tmp.bits[3], res[i].bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(test_decimal_to_int_success) {
  static int res[] = {0,        -1,         1,           -2,  2, 32767, -32767,
                      -9999999, 2147483647, -2147483647, 123, 1, -15};
  static s21_decimal src[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000002, 0x00000000, 0x00000000, 0x80000000}},  //-2
      {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 2
      {{0x00007FFF, 0x00000000, 0x00000000, 0x00000000}},  // 32767
      {{0x00007FFF, 0x00000000, 0x00000000, 0x80000000}},  //-32767
      {{0x0098967F, 0x00000000, 0x00000000, 0x80000000}},  //-9999999
      {{0x7FFFFFFF, 0x00000000, 0x00000000, 0x00000000}},  // 2147483647
      {{0x7FFFFFFF, 0x00000000, 0x00000000, 0x80000000}},  //-2147483647
      {{0x0001E078, 0x00000000, 0x00000000, 0x00030000}},  // 123.000
      {{0x00000457, 0x00000000, 0x00000000, 0x00030000}},  // 1.111
      {{0x0000060F, 0x00000000, 0x00000000, 0x80020000}}   //-15.51
  };
  for (size_t i = 0; i < sizeof(src) / sizeof(s21_decimal); ++i) {
    int tmp;
    int ret = s21_from_decimal_to_int(src[i], &tmp);
    ck_assert_int_eq(tmp, res[i]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(test_decimal_to_int_fail) {
  static s21_decimal src[] = {
      {{0x00002F59, 0x0CA55839, 0x00000000, 0x00000000}},  // 911231501448785753
      {{0x000004C2, 0x01518D64, 0x00000000, 0x80000000}},  // -95012527787738306
      {{0xFFFFFFFF, 0x000003E7, 0x00000000, 0x00030000}},  // 4294967295.999
      {{0x00000000, 0x00000001, 0x00000000, 0x00000000}},  // 4294967296
      {{0x00000000, 0x00000001, 0x00000000, 0x80000000}},  // -4294967296
  };
  for (size_t i = 0; i < sizeof(src) / sizeof(s21_decimal); ++i) {
    int tmp;
    int ret = s21_from_decimal_to_int(src[i], &tmp);
    ck_assert_int_eq(ret, 1);
  }
}
END_TEST

START_TEST(test_float_to_decimal_fail) {
  static float src_err[] = {0.f,  // nan(""),
                            0.f,  //-nan(""),
                            -INFINITY, INFINITY};
  src_err[0] = nan("");
  src_err[1] = -nan("");

  for (size_t i = 0; i < sizeof(src_err) / sizeof(float); ++i) {
    s21_decimal tmp;
    s21_decimal_to_zero(&tmp);
    int ret = s21_from_float_to_decimal(src_err[i], &tmp);
    ck_assert_int_eq(ret, 1);
  }
}
END_TEST

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147680256;
  src.bits[0] = 18122;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 0XFFFFFF;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

// START_TEST(s21_from_decimal_to_float_4) {
//   s21_decimal src;
//   int result = 0;
//   float number = 0.0;
//   long int c = 2147745792;
//   src.bits[0] = 23450987;
//   src.bits[1] = 0;
//   src.bits[2] = 0;
//   src.bits[3] = c;
//   result = s21_from_decimal_to_float(src, &number);
//   ck_assert_float_eq(number, -2345.0987);
//   ck_assert_int_eq(result, 0);
// }
// END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  src.bits[0] = c;
  src.bits[1] = c;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_6) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  dec.bits[0] = 18122;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  // делаем правильную степень десятки
  // в нашем случае 10^3 значит пишем 3 двоично, то есть 11
  s21_set_bit(&(dec), 17 + 95, 1);
  s21_set_bit(&(dec), 18 + 95, 1);
  // ставим знак
  float d = -18.122;
  s21_set_bit(&(dec), 127, 1);
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, d);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_7) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  dec.bits[0] = 1812;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = c;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_8) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;

  dec.bits[0] = 0XFFFFFF;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

// START_TEST(s21_from_decimal_to_float_9) {
//   s21_decimal dec;
//   int result = 0;
//   float number = 0.0;
//   long int c = 2147745792;
//   dec.bits[0] = 23450987;
//   dec.bits[1] = 0;
//   dec.bits[2] = 0;
//   dec.bits[3] = c;
//   result = s21_from_decimal_to_float(dec, &number);
//   ck_assert_float_eq(number, -2345.0987);
//   ck_assert_int_eq(result, 0);
// }
// END_TEST

START_TEST(s21_from_decimal_to_float_10) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  dec.bits[0] = c;
  dec.bits[1] = c;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest1) {
  // 6997
  s21_decimal src1;

  float src2 = 0;
  float *srcp = &src2;
  // s21_decimal src1 = 2546.5;

  src1.bits[0] = 0b00000000000000000110001101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 2546.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest2) {
  // 7016
  s21_decimal src1;

  float src2 = 0;
  float *srcp = &src2;
  // s21_decimal src1 = -0.46453;

  src1.bits[0] = 0b00000000000000001011010101110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -0.46453);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest3) {
  // 7035
  s21_decimal src1;

  float src2 = 0;
  float *srcp = &src2;
  // s21_decimal src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 3.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest4) {
  // 7054
  s21_decimal src1;

  float src2 = 0;
  float *srcp = &src2;
  // s21_decimal src1 = 4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 4.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest5) {
  // 7073
  s21_decimal src1;

  float src2 = 0;
  float *srcp = &src2;
  // s21_decimal src1 = -4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -4.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest6) {
  // 7092
  s21_decimal src1;

  float src2 = 0;
  float *srcp = &src2;
  // s21_decimal src1 = -5.49265;

  src1.bits[0] = 0b00000000000010000110000110010001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -5.49265);
  snprintf(result, sizeof(result), "%.6f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest7) {
  // 7111
  s21_decimal src1 = {0};
  // s21_decimal_to_zero(&src1);

  float src2 = 0;
  float *srcp = &src2;
  // s21_decimal src1 = 2.5086531268974139743;

  src1.bits[0] = 0b01100101111011101101100101011111;
  src1.bits[1] = 0b01011100001001010100001101000110;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 2.50865312689741);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

Suite *suite_from_decimal_to_float(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_float");
  tc = tcase_create("case_from_decimal_to_float");

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_5);
  tcase_add_test(tc, s21_from_decimal_to_float_6);
  tcase_add_test(tc, s21_from_decimal_to_float_7);
  tcase_add_test(tc, s21_from_decimal_to_float_8);
  tcase_add_test(tc, s21_from_decimal_to_float_10);
  tcase_add_test(tc, s21_from_decimal_to_floatTest1);
  tcase_add_test(tc, s21_from_decimal_to_floatTest2);
  tcase_add_test(tc, s21_from_decimal_to_floatTest3);
  tcase_add_test(tc, s21_from_decimal_to_floatTest4);
  tcase_add_test(tc, s21_from_decimal_to_floatTest5);
  tcase_add_test(tc, s21_from_decimal_to_floatTest6);
  tcase_add_test(tc, s21_from_decimal_to_floatTest7);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);

  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 3);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 127.1234);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_4) {
//   s21_decimal val;
//   float fl1 = 22.14836E+03;
//   float fl2 = -2.1474836E+09;
//   float fl1_res = 0;
//   float fl2_res = 0;

//   s21_from_float_to_decimal(fl1, &val);
//   s21_from_decimal_to_float(val, &fl1_res);
//   ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

//   s21_from_float_to_decimal(fl2, &val);
//   s21_from_decimal_to_float(val, &fl2_res);
//   ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_6) {
//   s21_decimal val;
//   float fl1 = -333.2222;
//   float fl2 = -2.1474836E+20;
//   float fl1_res = 0;
//   float fl2_res = 0;

//   s21_from_float_to_decimal(fl1, &val);
//   s21_from_decimal_to_float(val, &fl1_res);
//   ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

//   s21_from_float_to_decimal(fl2, &val);
//   s21_from_decimal_to_float(val, &fl2_res);
//   ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_7) {
//   s21_decimal val;
//   float a = 1.0 / 0.0;
//   s21_from_float_to_decimal(a, &val);
//   ck_assert_int_eq(val.bits[0], 0);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_10) {
//   s21_decimal val;
//   float a = 1e-30;
//   s21_from_float_to_decimal(a, &val);
//   ck_assert_int_eq(val.bits[0], 0);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_11) {
  s21_decimal dec;
  float tmp = 0;
  float tmp1 = 0.03;
  s21_from_float_to_decimal(tmp1, &dec);
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_12) {
  s21_decimal dec;
  s21_from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_13) {
//   s21_decimal dec;
//   s21_from_float_to_decimal(-2.1474836E+09, &dec);
//   float tmp = 0;
//   s21_from_decimal_to_float(dec, &tmp);
//   ck_assert_float_eq_tol(tmp, -2.1474836E+09, 1e-06);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_14) {
  s21_decimal dec;
  s21_from_float_to_decimal(22.14836E+03, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_15) {
//   s21_decimal dec;
//   s21_from_float_to_decimal(1.02E+08, &dec);
//   float tmp = 0;
//   s21_from_decimal_to_float(dec, &tmp);
//   ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_16) {
  s21_decimal dec;
  s21_from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_17) {
  s21_decimal dec;
  float a = 1.0 / 0.0;
  int ret = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_float_to_decimal");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, s21_from_float_to_decimal_1);

  tcase_add_test(tc, s21_from_float_to_decimal_11);
  tcase_add_test(tc, s21_from_float_to_decimal_12);

  tcase_add_test(tc, s21_from_float_to_decimal_14);

  tcase_add_test(tc, s21_from_float_to_decimal_16);
  tcase_add_test(tc, s21_from_float_to_decimal_17);

  suite_add_tcase(s, tc);
  return s;
}

END_TEST
Suite *conversions_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("conversions");

  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_int_to_decimal);
  tcase_add_test(tc_core, test_decimal_to_int_success);
  tcase_add_test(tc_core, test_decimal_to_int_fail);
  // tcase_add_test(tc_core, test_float_to_decimal_success);
  tcase_add_test(tc_core, test_float_to_decimal_fail);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  typedef Suite *(*func)(void);
  func funcs[COUNT_FUNC] = {&s21_add_test,
                            &s21_sub_test,
                            &s21_mul_test,
                            &s21_div_test,
                            &s21_less_test,
                            &s21_less_or_equal_test,
                            &s21_greater_test,
                            &s21_greater_or_equal_test,
                            &s21_is_equal_test,
                            &s21_is_equal_not_test,
                            &s21_another_test,
                            &s21_negate_test,
                            &conversions_suite,
                            &suite_from_decimal_to_float,
                            &suite_from_float_to_decimal};

  for (int i = 0; i < COUNT_FUNC; i++) {
    s = funcs[i]();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_NORMAL);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
