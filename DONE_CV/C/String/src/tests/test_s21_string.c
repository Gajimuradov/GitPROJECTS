#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

// strlen
START_TEST(strlen_long_string) {
  char *value = "some_string";
  ck_assert_uint_eq(s21_strlen(value), strlen(value));
}
END_TEST

START_TEST(strlen_empty_string) {
  char *value = "";
  ck_assert_uint_eq(s21_strlen(value), strlen(value));
}
END_TEST

// memcmp
START_TEST(memcmp_1) {
  const char str1[] = "https://www.tutorialspoint.com";
  const char str2[] = "https://wYw.tutorialspoint.com";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(memcmp_2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(memcmp_3) {
  const char str1[] = "123abc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// strncmp
START_TEST(strncmp_1) {
  char s1[] = "https://www.tutorialspoint.com";
  char s2[] = "https://wYw.tutorialspoint.com";
  s21_size_t n = 12;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_2) {
  char s1[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  s21_size_t n = 7;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_3) {
  char s1[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_4) {
  char s1[] = "strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_5) {
  char s1[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "const char *str1, const char *str2, size_t n)";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_6) {
  char s1[] = "qwertyuiop";
  char s2[] = "qwertyuiop";
  s21_size_t n = 9;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_7) {
  char s1[] = "9876543210";
  char s2[] = "9876543210";
  s21_size_t n = 2;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_9) {
  char s1[] = "     ";
  char s2[] = " ";
  size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

// strncmp
START_TEST(s21_strncmp_test_6) {
  const char str1[] = "";
  const char str2[] = "";
  int n = 5;

  int res1 = strncmp(str1, str2, n);
  int res2 = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

// strstr
START_TEST(strstr_1) {
  char haystack[] = "123642o5lhttps://www.tutorialspoint.com";
  char needle[] = "tutorialspoint";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_2) {
  char haystack[] = "";
  char needle[] = "tutorialspoint";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_3) {
  char haystack[] = "12332334";
  char needle[] = "23";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_4) {
  char haystack[] = "https://www.tutorialspoint.com";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_5) {
  char haystack[] = "https://www.tutorialspoint";
  char needle[] = "tutorialspoint";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_6) {
  char haystack[] = "www.tutorialspoint.com";
  char needle[] = "123642";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_7) {
  char haystack[] = "Dm";
  char needle[] = "m";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_8) {
  char haystack[] = "Suite Create";
  char needle[] = "create";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_9) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// strtok
START_TEST(strtok_1_) {
  char *c[] = {"/", "|", "\t", "=", "+"};
  char str1[15] = "An awf+ul d+ay";
  char str2[15] = "Abs=olute\t24";
  char str3[15] = "aeE|be\\/as|df";
  char str4[15] = "1 2 /3 4 /5 ";
  char str5[] = "";

  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(s21_strtok(str1, c[i]), strtok(str1, c[i]));
    ck_assert_str_eq(s21_strtok(str2, c[i]), strtok(str2, c[i]));
    ck_assert_str_eq(s21_strtok(str3, c[i]), strtok(str3, c[i]));
    ck_assert_str_eq(s21_strtok(str4, c[i]), strtok(str4, c[i]));
    ck_assert_ptr_null(s21_strtok(str5, c[i]));
    ck_assert_ptr_null(strtok(str5, c[i]));
  }
}

END_TEST
START_TEST(strtok_2_) {
  char s21_str[] = "+++!!= _";
  char str[] = "+++!!= _";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_pstr_eq(s21, system);
}
END_TEST

START_TEST(strtok_11) {
  char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_14) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(strtok_15) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(strtok_16) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
}
END_TEST

START_TEST(strtok_19) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(S21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(S21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(strtok_1) {
  char str4_1[] = "/testing/with/original/string.h/";
  char str4_2[] = "/testing/with/original/string.h/";
  char del4[3] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str4_1[] = ". . testing with original string.h";
  char str4_2[] = ". . testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_3) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_unary_delimiters) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_too_many_uses_non_segfault) {
  char str1[] = "Aboba_Floppa_Roba";
  char str2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  int i = 5;
  while (i) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    i--;
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_n_of_delims) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_mixed) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_hard_incorrect) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_very_hard_mixed) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

// to_upper
START_TEST(to_upper_1) {
  char s1[30] = "qwertyuiop";
  char *s2 = s21_to_upper(s1);
  char s3[] = "QWERTYUIOP";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_upper_2) {
  char s1[30] = "\nf\t\\a123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nF\t\\A123123";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_upper_3) {
  char s1[30] = "IRILETHJ";
  char *s2 = s21_to_upper(s1);
  char s3[] = "IRILETHJ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_upper_4) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_upper_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_upper_6) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_upper_7) {
  char *s1 = S21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = S21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

// to_lower
START_TEST(to_lower_1) {
  char s1[30] = "qwerty";
  char s3[] = "QWErty";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_lower_2) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_lower_3) {
  char s1[30] = "irilethj";
  char s3[] = "irilethj";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_lower_4) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_lower_6) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(to_lower_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}

// strcspn
START_TEST(strcspn_long_string) {
  char *value = "some string";
  char *search = "s";
  ck_assert_uint_eq(s21_strcspn(value, search), strcspn(value, search));
}
END_TEST

START_TEST(strcspn_search_not_found) {
  char *value = "some string";
  char *search = "f";
  ck_assert_uint_eq(s21_strcspn(value, search), strcspn(value, search));
}
END_TEST

START_TEST(strcspn_long_search_found) {
  char *value = "some string";
  char *search = "fo";
  ck_assert_uint_eq(s21_strcspn(value, search), strcspn(value, search));
}
END_TEST

// strncat
START_TEST(strncat_eq_strings) {
  char dest1[30] = "foo";
  char dest2[30] = "foo";
  char *src = "buzz";
  size_t n = 4;
  ck_assert_pstr_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_not_eq_strings) {
  char dest1[30] = "foo1";
  char dest2[30] = "foo2";
  char *src = "buzz";
  size_t n = 4;
  ck_assert_pstr_ne(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_eq_dest_empty_src) {
  char dest1[30] = "foo";
  char dest2[30] = "foo";
  char *src = "";
  size_t n = 4;
  ck_assert_pstr_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

START_TEST(strncat_eq_n_small) {
  char dest1[30] = "foo";
  char dest2[30] = "foo";
  char *src = "buzz";
  size_t n = 2;
  ck_assert_pstr_eq(s21_strncat(dest1, src, n), strncat(dest2, src, n));
}
END_TEST

// strerror
START_TEST(strerror_code_1) {
  size_t n = 1;
  ck_assert_pstr_eq(s21_strerror(n), strerror(n));
}
END_TEST

START_TEST(strerror_code_43) {
  size_t n = 43;
  ck_assert_pstr_eq(s21_strerror(n), strerror(n));
}
END_TEST

START_TEST(strerror_code_110) {
  size_t n = 110;
  ck_assert_pstr_eq(s21_strerror(n), strerror(n));
}
END_TEST

START_TEST(strerror_code_1100) {
  size_t n = 1100;
  ck_assert_pstr_eq(s21_strerror(n), strerror(n));
}
END_TEST

START_TEST(strerror_code_negative) {
  size_t n = -10;
  ck_assert_pstr_eq(s21_strerror(n), strerror(n));
}
END_TEST

START_TEST(s21_string_strerror) {
  for (int i = -16; i < 255; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

// trim
START_TEST(trim_start) {
  char *string = "00010string";
  char *trim_chars = "01";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "string");
  free(result);
}
END_TEST

START_TEST(trim_end) {
  char *string = "string00010";
  char *trim_chars = "01";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "string");
  free(result);
}
END_TEST

START_TEST(trim_start_end) {
  char *string = "00101010string00010";
  char *trim_chars = "01";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "string");
  free(result);
}
END_TEST

START_TEST(trim_spaces) {
  char *string = "  1  string   1  ";
  char *trim_chars = " ";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "1  string   1");
  free(result);
}
END_TEST

START_TEST(trim_empty) {
  char *string = "  1  string   1  ";
  char *trim_chars = "";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "1  string   1");
  free(result);
}
END_TEST

START_TEST(trim_not_trimed) {
  char *string = "eeeeeeeeeeee";
  char *trim_chars = "01";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "eeeeeeeeeeee");
  free(result);
}
END_TEST

START_TEST(trim_string_empty) {
  char *string = "";
  char *trim_chars = "01";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

START_TEST(trim_all_empty) {
  char *string = "";
  char *trim_chars = "";
  void *result = s21_trim(string, trim_chars);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

START_TEST(trim_null) {
  char *string = NULL;
  char *trim_chars = "";
  void *result = s21_trim(string, trim_chars);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(trim_all_null) {
  char *string = NULL;
  char *trim_chars = NULL;
  void *result = s21_trim(string, trim_chars);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(trim_test5) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_1) {
  char src1[] = "     &#@\n\n\t Hello, World! *&#@ \n\t   ";
  char trim_chars[] = " &#@\n\t";
  char *psrc = s21_trim(src1, trim_chars);
  ck_assert_pstr_eq(psrc, "Hello, World! *");
  free(psrc);
}
END_TEST

// insert
START_TEST(insert_start) {
  char *src = "foo";
  char *str = "buzz";
  size_t index = 0;
  void *result = s21_insert(src, str, index);
  ck_assert_pstr_eq(result, "buzzfoo");
  free(result);
}
END_TEST

START_TEST(insert_end) {
  char *src = "foo";
  char *str = "buzz";
  size_t index = 3;
  void *result = s21_insert(src, str, index);
  ck_assert_pstr_eq(result, "foobuzz");
  free(result);
}
END_TEST

START_TEST(insert_empty) {
  char *src = "foo";
  char *str = "";
  size_t index = 3;
  void *result = s21_insert(src, str, index);
  ck_assert_pstr_eq(result, "foo");
  free(result);
}

START_TEST(insert_into_empty) {
  char *src = "";
  char *str = "buzz";
  size_t index = 0;
  void *result = s21_insert(src, str, index);
  ck_assert_pstr_eq(result, "buzz");
  free(result);
}
END_TEST

START_TEST(insert_into_null) {
  char *src = NULL;
  char *str = "buzz";
  size_t index = 0;
  void *result = s21_insert(src, str, index);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(insert_null_into_string) {
  char *src = "foo";
  char *str = NULL;
  size_t index = 0;
  void *result = s21_insert(src, str, index);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(insert_test3) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_2) {
  char *string = "diary";
  char *string2;
  string2 = s21_insert(string, "ction", 8);
  ck_assert_pstr_eq(string2, NULL);
  free(string2);
}
END_TEST

START_TEST(test_insert_2) {
  char s1[50] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  s21_size_t num = 20;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(NULL, s2);
}
END_TEST

START_TEST(s21_part_5_insert) {
  char *fake = "";
  char *result = s21_insert(fake, fake, 0);
  ck_assert_pstr_eq(result, NULL);
  free(result);
}
END_TEST

// strncpy
START_TEST(strncpy_all_into_empty) {
  char src1[4] = "";
  char src2[4] = "";
  char *str = "buzz";
  size_t count = 3;
  ck_assert_pstr_eq(strncpy(src2, str, count), s21_strncpy(src1, str, count));
}
END_TEST

START_TEST(strncpy_part_into_empty) {
  char src1[4] = "";
  char src2[4] = "";
  char *str = "buzz-buzz";
  size_t count = 3;
  ck_assert_pstr_eq(strncpy(src2, str, count), s21_strncpy(src1, str, count));
}
END_TEST

START_TEST(strncpy_part_into_string) {
  char src1[12] = "foo";
  char src2[12] = "foo";
  char *str = "buzz-buzz";
  size_t count = 3;
  ck_assert_pstr_eq(s21_strncpy(src1, str, count), strncpy(src2, str, count));
}
END_TEST

START_TEST(strncpy_all_into_string) {
  char src1[20] = "foo";
  char src2[20] = "foo";
  char *str = "buzz";
  size_t count = 3;
  ck_assert_pstr_eq(s21_strncpy(src1, str, count), strncpy(src2, str, count));
}
END_TEST

START_TEST(strncpy_zero_into_string) {
  char src1[4] = "foo";
  char src2[4] = "foo";
  char *str = "buzz";
  size_t count = 0;
  ck_assert_pstr_eq(s21_strncpy(src1, str, count), strncpy(src2, str, count));
}
END_TEST

START_TEST(strncpy_empty_into_empty) {
  char src1[3] = "";
  char src2[3] = "";
  char *str = "";
  size_t count = 0;
  ck_assert_pstr_eq(s21_strncpy(src1, str, count), strncpy(src2, str, count));
}
END_TEST

START_TEST(strncpy_error_message) {
  static char dest1[50] = {0};
  static char dest2[50] = {0};
  char *str = "Key was rejected by service";

  ck_assert_pstr_eq(s21_strncpy(dest1, str, strlen(str)),
                    strncpy(dest2, str, strlen(str)));
}
END_TEST

START_TEST(strncpy_1) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_2) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

// memset
START_TEST(memset_string) {
  char src1[10] = "string";
  char src2[10] = "string";
  char c = '0';
  size_t count = 3;
  ck_assert_pstr_eq(s21_memset(src1, c, count), memset(src2, c, count));
}
END_TEST

START_TEST(memset_start) {
  char src1[4] = {0};
  char src2[4] = {0};
  char c = '0';
  size_t count = 3;
  ck_assert_pstr_eq(s21_memset(src1, c, count), memset(src2, c, count));
}
END_TEST

// memcpy
START_TEST(memcpy_all_into_empty) {
  char src1[10] = "";
  char src2[10] = "";
  char *str = "buzz";
  size_t count = 3;
  ck_assert_pstr_eq(s21_memcpy(src1, str, count), memcpy(src2, str, count));
}
END_TEST

START_TEST(memcpy_part_into_empty) {
  char src1[4] = "";
  char src2[4] = "";
  char *str = "buzz-buzz";
  size_t count = 3;
  ck_assert_pstr_eq(s21_memcpy(src1, str, count), memcpy(src2, str, count));
}
END_TEST

START_TEST(memcpy_part_into_string) {
  char src1[12] = "foo";
  char src2[12] = "foo";
  char *str = "buzz-buzz";
  size_t count = 3;
  ck_assert_pstr_eq(s21_memcpy(src1, str, count), memcpy(src2, str, count));
}
END_TEST

START_TEST(memcpy_all_into_string) {
  char src1[20] = "foo";
  char src2[20] = "foo";
  char *str = "buzz";
  size_t count = 3;
  ck_assert_pstr_eq(s21_memcpy(src1, str, count), memcpy(src2, str, count));
}
END_TEST

START_TEST(memcpy_zero_into_string) {
  char src1[4] = "foo";
  char src2[4] = "foo";
  char *str = "buzz";
  size_t count = 0;
  ck_assert_pstr_eq(s21_memcpy(src1, str, count), memcpy(src2, str, count));
}
END_TEST

START_TEST(memcpy_empty_into_empty) {
  char src1[3] = "";
  char src2[3] = "";
  char *str = "";
  size_t count = 0;
  ck_assert_pstr_eq(s21_memcpy(src1, str, count), memcpy(src2, str, count));
}
END_TEST

START_TEST(memcpy_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

// memchr
START_TEST(memchr_case_1) {
  char *string = "School 21";
  int ch = ' ';
  s21_size_t length = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, length), s21_memchr(string, ch, length));
}
END_TEST

START_TEST(memchr_case_2) {
  char *string = "School 21";
  int ch = 'L';
  s21_size_t length = 4;
  ck_assert_ptr_eq(memchr(string, ch, length), s21_memchr(string, ch, length));
}
END_TEST

START_TEST(memchr_case_3) {
  char *string = "School 21\n";
  int ch = 'o';
  s21_size_t length = 10;
  ck_assert_ptr_eq(memchr(string, ch, length), s21_memchr(string, ch, length));
}
END_TEST

START_TEST(memchr_case_4) {
  char *string = "School 21";
  int ch = 108;
  s21_size_t length = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, length), s21_memchr(string, ch, length));
}
END_TEST

START_TEST(memchr_case_5) {
  char *string = "+7 (495) 280-10-21";
  int ch = '\0';
  s21_size_t length = 19;
  ck_assert_ptr_eq(memchr(string, ch, length), s21_memchr(string, ch, length));
}
END_TEST

START_TEST(memchr_case_6) {
  char *string = "+7 (495) 280-10-21";
  int ch = '+';
  s21_size_t length = 0;
  ck_assert_ptr_eq(memchr(string, ch, length), s21_memchr(string, ch, length));
}
END_TEST

// strpbrk
START_TEST(strpbrk_case_1) {
  char *string1 = "School 21";
  char *string2 = "School 21/n";
  ck_assert_pstr_eq(strpbrk(string1, string2), s21_strpbrk(string1, string2));
}
END_TEST

START_TEST(strpbrk_case_2) {
  char *string1 = "School 21\n";
  char *string2 = " ";
  ck_assert_pstr_eq(strpbrk(string1, string2), s21_strpbrk(string1, string2));
}
END_TEST

START_TEST(strpbrk_case_3) {
  char *string1 = "\0";
  char *string2 = "";
  ck_assert_pstr_eq(strpbrk(string1, string2), s21_strpbrk(string1, string2));
}
END_TEST

START_TEST(strpbrk_case_4) {
  char *string1 = "849848151892242774123";
  char *string2 = "110377534956";
  ck_assert_pstr_eq(strpbrk(string1, string2), s21_strpbrk(string1, string2));
}
END_TEST

START_TEST(strpbrk_case_5) {
  char *string1 = "";
  char *string2 = "";
  ck_assert_pstr_eq(strpbrk(string1, string2), s21_strpbrk(string1, string2));
}
END_TEST

START_TEST(strpbrk_case_6) {
  char *string1 = "";
  char *string2 = "No Country for Old Men";
  ck_assert_pstr_eq(strpbrk(string1, string2), s21_strpbrk(string1, string2));
}
END_TEST

// strchr
START_TEST(strchr_case_1) {
  char *string = "School 21/n";
  int ch = 10;
  ck_assert_pstr_eq(strchr(string, ch), s21_strchr(string, ch));
}
END_TEST

START_TEST(strchr_case_2) {
  char *string = "School 21/n/0";
  int ch = 's';
  ck_assert_pstr_eq(strchr(string, ch), s21_strchr(string, ch));
}
END_TEST

START_TEST(strchr_case_3) {
  char *string = "School 21/n/0";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(string, ch), s21_strchr(string, ch));
}
END_TEST

START_TEST(strchr_case_4) {
  char *string = "School 21/n";
  int ch = '7';
  ck_assert_pstr_eq(strchr(string, ch), s21_strchr(string, ch));
}
END_TEST

START_TEST(strchr_case_5) {
  char *string = "School 21/n";
  int ch = 'q';
  ck_assert_pstr_eq(strchr(string, ch), s21_strchr(string, ch));
}
END_TEST

START_TEST(strchr_case_6) {
  char *string = "School 21/n";
  int ch = ' ';
  ck_assert_pstr_eq(strchr(string, ch), s21_strchr(string, ch));
}
END_TEST

// strrchr
START_TEST(strrchr_case_1) {
  char *string = "School 21/n";
  int ch = 10;
  ck_assert_pstr_eq(strrchr(string, ch), s21_strrchr(string, ch));
}
END_TEST

START_TEST(strrchr_case_2) {
  char *string = "School 21/n/0";
  int ch = 's';
  ck_assert_pstr_eq(strrchr(string, ch), s21_strrchr(string, ch));
}
END_TEST

START_TEST(strrchr_case_3) {
  char *string = "School 21/n/0";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(string, ch), s21_strrchr(string, ch));
}
END_TEST

START_TEST(strrchr_case_4) {
  char *string = "School 21/n";
  int ch = '7';
  ck_assert_pstr_eq(strrchr(string, ch), s21_strrchr(string, ch));
}
END_TEST

START_TEST(strrchr_case_5) {
  char *string = "School 21/n";
  int ch = 'q';
  ck_assert_pstr_eq(strrchr(string, ch), s21_strrchr(string, ch));
}
END_TEST

START_TEST(strrchr_case_6) {
  char *string = "School 21/n";
  int ch = ' ';
  ck_assert_pstr_eq(strrchr(string, ch), s21_strrchr(string, ch));
}
END_TEST

// sprintf
START_TEST(s21_sprintf_test) {
  char str1[1000];
  char str2[1000];
  char format[] = "This is a simple value %d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[1000];
  char str2[1000];

  char *format = "%+12d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[1000];
  char str2[1000];

  char *format = "%+12d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[1000];
  char str2[1000];

  char *format = "%.0d";
  int val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[1000];
  char str2[1000];

  char *format = "% d";
  int val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[1000];
  char str2[1000];
  char *format = "%u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[1000];
  char str2[1000];
  char *format = "%15u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[1000];
  char str2[1000];

  char *format = "%-16u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[1000];
  char str2[1000];
  char *format = "%.51u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[1000];
  char str2[1000];
  char *format = "% 5.51u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[1000];
  char str2[1000];

  char *format = "%hu";
  unsigned short int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[1000];
  char str2[1000];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_unsigned_val_many) {
//   char str1[1000];
//   char str2[1000];

//   char *format = "%lu, %u, %hu, %.5u, %5.u";
//   unsigned long int val = 949149114140;
//   s21_sprintf(str1, format, val, 14, 1441, 14414, 9681);

//   sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
//           (unsigned)14414, (unsigned)9681);

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_octal_short) {
  char str1[1000];
  char str2[1000];

  char *format = "%hd";
  short int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[1000];
  char str2[1000];

  char *format = "%u";
  s21_sprintf(str1, format, 0);

  sprintf(str2, format, (unsigned)0);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[1000];
  char str2[1000];

  char *format = "%s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[1000];
  char str2[1000];

  char *format = "%.4s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string__width) {
  char str1[1000];
  char str2[1000];

  char *format = "%25s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_minus) {
  char str1[1000];
  char str2[1000];

  char *format = "%-25s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char) {
  char str1[1000];
  char str2[1000];

  char *format = "%c";
  char sym = '!';
  s21_sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_width) {
  char str1[1000];
  char str2[1000];

  char *format = "%5c";
  char sym = '!';
  s21_sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_minus) {
  char str1[1000];
  char str2[1000];

  char *format = "%-5c";
  char sym = '!';
  s21_sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprint_string_null) {
  char str1[1000];
  char str2[1000];

  char *format = "%s";
  char *string = NULL;
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_float) {
//   char str1[1000];
//   char str2[1000];

//   char *format = "%f";
//   double num = 1.9;
//   s21_sprintf(str1, format, num);
//   sprintf(str2, format, num);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_float_zero) {
  char str1[1000];
  char str2[1000];

  char *format = "%f";
  double zero = 0;
  s21_sprintf(str1, format, zero);
  sprintf(str2, format, zero);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double_min) {
  char str1[1000];
  char str2[1000];

  char *format = "%lf";
  double num = 1E-12;
  s21_sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_double) {
//   char str1[1000];
//   char str2[1000];

//   char *format = "%lf";
//   double negative = -0.34834493943;
//   s21_sprintf(str1, format, negative);
//   sprintf(str2, format, negative);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_double_negative) {
//   char str1[1000];
//   char str2[1000];

//   char *format = "%lf";
//   double num = -10.934;
//   s21_sprintf(str1, format, num);
//   sprintf(str2, format, num);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_double_nan) {
  char str1[1000];
  char str2[1000];

  char *format = "%lf";
  double nan = NAN;
  s21_sprintf(str1, format, nan);
  sprintf(str2, format, nan);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_percent) {
  char str1[1000];
  char str2[1000];

  char *format = "%%lf";
  long double num = 0;
  s21_sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *s = suite_create("s21_string_test");

  // memchr
  TCase *tc_s21_memchr = tcase_create("[s21_memchr] case");
  tcase_add_test(tc_s21_memchr, memchr_case_1);
  tcase_add_test(tc_s21_memchr, memchr_case_2);
  tcase_add_test(tc_s21_memchr, memchr_case_3);
  tcase_add_test(tc_s21_memchr, memchr_case_4);
  tcase_add_test(tc_s21_memchr, memchr_case_5);
  tcase_add_test(tc_s21_memchr, memchr_case_6);
  suite_add_tcase(s, tc_s21_memchr);

  // strpbrk
  TCase *tc_s21_strpbrk = tcase_create("[s21_strpbrk] case");
  tcase_add_test(tc_s21_strpbrk, strpbrk_case_1);
  tcase_add_test(tc_s21_strpbrk, strpbrk_case_2);
  tcase_add_test(tc_s21_strpbrk, strpbrk_case_3);
  tcase_add_test(tc_s21_strpbrk, strpbrk_case_4);
  tcase_add_test(tc_s21_strpbrk, strpbrk_case_5);
  tcase_add_test(tc_s21_strpbrk, strpbrk_case_6);
  suite_add_tcase(s, tc_s21_strpbrk);

  // strchr
  TCase *tc_s21_strchr = tcase_create("[s21_strchr] case");
  tcase_add_test(tc_s21_strchr, strchr_case_1);
  tcase_add_test(tc_s21_strchr, strchr_case_2);
  tcase_add_test(tc_s21_strchr, strchr_case_3);
  tcase_add_test(tc_s21_strchr, strchr_case_4);
  tcase_add_test(tc_s21_strchr, strchr_case_5);
  tcase_add_test(tc_s21_strchr, strchr_case_6);
  suite_add_tcase(s, tc_s21_strchr);

  // strrchr
  TCase *tc_s21_strrchr = tcase_create("strrchr_tc");
  tcase_add_test(tc_s21_strrchr, strrchr_case_1);
  tcase_add_test(tc_s21_strrchr, strrchr_case_2);
  tcase_add_test(tc_s21_strrchr, strrchr_case_3);
  tcase_add_test(tc_s21_strrchr, strrchr_case_4);
  tcase_add_test(tc_s21_strrchr, strrchr_case_5);
  tcase_add_test(tc_s21_strrchr, strrchr_case_6);
  suite_add_tcase(s, tc_s21_strrchr);

  // strlen
  TCase *tc_s21_strlen = tcase_create("[s21_strlen] case");
  tcase_add_test(tc_s21_strlen, strlen_long_string);
  tcase_add_test(tc_s21_strlen, strlen_empty_string);
  suite_add_tcase(s, tc_s21_strlen);

  // strncmp
  TCase *tc_s21_strncmp = tcase_create("[s21_strncmp] case");
  tcase_add_test(tc_s21_strncmp, strncmp_1);
  tcase_add_test(tc_s21_strncmp, strncmp_2);
  tcase_add_test(tc_s21_strncmp, strncmp_3);
  tcase_add_test(tc_s21_strncmp, strncmp_4);
  tcase_add_test(tc_s21_strncmp, strncmp_5);
  tcase_add_test(tc_s21_strncmp, strncmp_6);
  tcase_add_test(tc_s21_strncmp, strncmp_7);
  tcase_add_test(tc_s21_strncmp, strncmp_9);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_test_6);
  tcase_add_test(tc_s21_strncmp, strncmp_empty);
  suite_add_tcase(s, tc_s21_strncmp);

  // to_lower
  TCase *tc_s21_to_lower = tcase_create("[s21_to_lower] case");
  tcase_add_test(tc_s21_to_lower, to_lower_1);
  tcase_add_test(tc_s21_to_lower, to_lower_2);
  tcase_add_test(tc_s21_to_lower, to_lower_3);
  tcase_add_test(tc_s21_to_lower, to_lower_4);
  tcase_add_test(tc_s21_to_lower, to_lower_5);
  tcase_add_test(tc_s21_to_lower, to_lower_6);
  tcase_add_test(tc_s21_to_lower, to_lower_7);
  suite_add_tcase(s, tc_s21_to_lower);

  // to_upper
  TCase *tc_s21_to_upper = tcase_create("[s21_to_upper] case");
  tcase_add_test(tc_s21_to_upper, to_upper_1);
  tcase_add_test(tc_s21_to_upper, to_upper_2);
  tcase_add_test(tc_s21_to_upper, to_upper_3);
  tcase_add_test(tc_s21_to_upper, to_upper_4);
  tcase_add_test(tc_s21_to_upper, to_upper_5);
  tcase_add_test(tc_s21_to_upper, to_upper_6);
  tcase_add_test(tc_s21_to_upper, to_upper_7);
  suite_add_tcase(s, tc_s21_to_upper);

  // strtok
  TCase *tc_s21_strtok = tcase_create("[s21_strtok] case");

  tcase_add_test(tc_s21_strtok, strtok_1_);
  tcase_add_test(tc_s21_strtok, strtok_2_);
  tcase_add_test(tc_s21_strtok, strtok_11);
  tcase_add_test(tc_s21_strtok, strtok_14);
  tcase_add_test(tc_s21_strtok, strtok_15);
  tcase_add_test(tc_s21_strtok, strtok_16);
  tcase_add_test(tc_s21_strtok, strtok_19);
  tcase_add_test(tc_s21_strtok, strtok_1);
  tcase_add_test(tc_s21_strtok, strtok_2);
  tcase_add_test(tc_s21_strtok, strtok_3);
  tcase_add_test(tc_s21_strtok, strtok_unary_delimiters);
  tcase_add_test(tc_s21_strtok, strtok_too_many_uses_non_segfault);
  tcase_add_test(tc_s21_strtok, strtok_mixed_n_of_delims);
  tcase_add_test(tc_s21_strtok, strtok_hard_mixed);
  tcase_add_test(tc_s21_strtok, strtok_mixed_hard_incorrect);
  tcase_add_test(tc_s21_strtok, strtok_very_hard_mixed);

  suite_add_tcase(s, tc_s21_strtok);

  // strstr
  TCase *tc_s21_strstr = tcase_create("[s21_strstr] case");
  tcase_add_test(tc_s21_strstr, strstr_1);
  tcase_add_test(tc_s21_strstr, strstr_2);
  tcase_add_test(tc_s21_strstr, strstr_3);
  tcase_add_test(tc_s21_strstr, strstr_4);
  tcase_add_test(tc_s21_strstr, strstr_5);
  tcase_add_test(tc_s21_strstr, strstr_6);
  tcase_add_test(tc_s21_strstr, strstr_7);
  tcase_add_test(tc_s21_strstr, strstr_8);
  tcase_add_test(tc_s21_strstr, strstr_9);
  suite_add_tcase(s, tc_s21_strstr);

  // memcmp
  TCase *tc_s21_memcmp = tcase_create("[s21_memcmp] case");
  tcase_add_test(tc_s21_memcmp, memcmp_1);
  tcase_add_test(tc_s21_memcmp, memcmp_2);
  tcase_add_test(tc_s21_memcmp, memcmp_3);
  suite_add_tcase(s, tc_s21_memcmp);

  // strcspn
  TCase *tc_s21_strcspn = tcase_create("[s21_strcspn] case");
  tcase_add_test(tc_s21_strcspn, strcspn_long_string);
  tcase_add_test(tc_s21_strcspn, strcspn_search_not_found);
  tcase_add_test(tc_s21_strcspn, strcspn_long_search_found);
  suite_add_tcase(s, tc_s21_strcspn);

  // strncat
  TCase *tc_s21_strncat = tcase_create("[s21_strncat] case");
  tcase_add_test(tc_s21_strncat, strncat_eq_strings);
  tcase_add_test(tc_s21_strncat, strncat_not_eq_strings);
  tcase_add_test(tc_s21_strncat, strncat_eq_dest_empty_src);
  tcase_add_test(tc_s21_strncat, strncat_eq_n_small);
  suite_add_tcase(s, tc_s21_strncat);

  // strerror
  TCase *tc_s21_strerror = tcase_create("[s21_strerror] case");
  tcase_add_test(tc_s21_strerror, strerror_code_1);
  tcase_add_test(tc_s21_strerror, strerror_code_43);
  tcase_add_test(tc_s21_strerror, strerror_code_110);
  tcase_add_test(tc_s21_strerror, strerror_code_negative);
  tcase_add_test(tc_s21_strerror, strerror_code_1100);
  tcase_add_test(tc_s21_strerror, s21_string_strerror);
  suite_add_tcase(s, tc_s21_strerror);

  // trim
  TCase *tc_s21_trim = tcase_create("[s21_trim] case");
  tcase_add_test(tc_s21_trim, trim_start);
  tcase_add_test(tc_s21_trim, trim_end);
  tcase_add_test(tc_s21_trim, trim_start_end);
  tcase_add_test(tc_s21_trim, trim_spaces);
  tcase_add_test(tc_s21_trim, trim_empty);
  tcase_add_test(tc_s21_trim, trim_not_trimed);
  tcase_add_test(tc_s21_trim, trim_string_empty);
  tcase_add_test(tc_s21_trim, trim_all_empty);
  tcase_add_test(tc_s21_trim, trim_null);
  tcase_add_test(tc_s21_trim, trim_all_null);
  tcase_add_test(tc_s21_trim, trim_test5);
  tcase_add_test(tc_s21_trim, trim_and_str_eq);
  tcase_add_test(tc_s21_trim, trim_1);
  suite_add_tcase(s, tc_s21_trim);

  // insert
  TCase *tc_s21_insert = tcase_create("[s21_insert] case");
  tcase_add_test(tc_s21_insert, insert_start);
  tcase_add_test(tc_s21_insert, insert_end);
  tcase_add_test(tc_s21_insert, insert_empty);
  tcase_add_test(tc_s21_insert, insert_into_empty);
  tcase_add_test(tc_s21_insert, insert_into_null);
  tcase_add_test(tc_s21_insert, insert_null_into_string);
  tcase_add_test(tc_s21_insert, insert_test3);
  tcase_add_test(tc_s21_insert, insert_2);
  tcase_add_test(tc_s21_insert, test_insert_2);
  tcase_add_test(tc_s21_insert, s21_part_5_insert);

  suite_add_tcase(s, tc_s21_insert);

  // strncpy
  TCase *tc_s21_strncpy = tcase_create("[s21_strncpy] case");
  tcase_add_test(tc_s21_strncpy, strncpy_all_into_empty);
  tcase_add_test(tc_s21_strncpy, strncpy_part_into_empty);
  tcase_add_test(tc_s21_strncpy, strncpy_part_into_string);
  tcase_add_test(tc_s21_strncpy, strncpy_all_into_string);
  tcase_add_test(tc_s21_strncpy, strncpy_zero_into_string);
  tcase_add_test(tc_s21_strncpy, strncpy_empty_into_empty);
  tcase_add_test(tc_s21_strncpy, strncpy_error_message);
  tcase_add_test(tc_s21_strncpy, strncpy_1);
  tcase_add_test(tc_s21_strncpy, strncpy_2);
  suite_add_tcase(s, tc_s21_strncpy);

  // memset
  TCase *tc_s21_memset = tcase_create("[s21_memset] case");
  tcase_add_test(tc_s21_memset, memset_start);
  tcase_add_test(tc_s21_memset, memset_string);
  suite_add_tcase(s, tc_s21_memset);

  // memcpy
  TCase *tc_s21_memcpy = tcase_create("[s21_memcpy] case");
  tcase_add_test(tc_s21_memcpy, memcpy_all_into_empty);
  tcase_add_test(tc_s21_memcpy, memcpy_part_into_empty);
  tcase_add_test(tc_s21_memcpy, memcpy_part_into_string);
  tcase_add_test(tc_s21_memcpy, memcpy_all_into_string);
  tcase_add_test(tc_s21_memcpy, memcpy_zero_into_string);
  tcase_add_test(tc_s21_memcpy, memcpy_empty_into_empty);
  tcase_add_test(tc_s21_memcpy, memcpy_2);
  tcase_add_test(tc_s21_memcpy, memcpy_4);
  suite_add_tcase(s, tc_s21_memcpy);

  // sprintf
  TCase *tc_s21_sprintf = tcase_create("[s21_sprintf] case");
  tcase_add_test(tc_s21_sprintf, s21_sprintf_test);
  tcase_add_test(tc_s21_sprintf, sprintf_plus_width_int);
  tcase_add_test(tc_s21_sprintf, sprintf_padding_int);
  tcase_add_test(tc_s21_sprintf, sprintf_zero_precision_zero_int);
  tcase_add_test(tc_s21_sprintf, sprintf_space_flag_int);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val_width);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val_flags);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val_precision);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val_short);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val_long);
  // tcase_add_test(tc_s21_sprintf, sprintf_unsigned_val_many);
  tcase_add_test(tc_s21_sprintf, sprintf_octal_short);
  tcase_add_test(tc_s21_sprintf, sprintf_unsigned_zero);
  tcase_add_test(tc_s21_sprintf, sprintf_string);
  tcase_add_test(tc_s21_sprintf, sprintf_string_precision);
  tcase_add_test(tc_s21_sprintf, sprintf_string__width);
  tcase_add_test(tc_s21_sprintf, sprintf_string_minus);
  tcase_add_test(tc_s21_sprintf, sprintf_char);
  tcase_add_test(tc_s21_sprintf, sprintf_char_width);
  tcase_add_test(tc_s21_sprintf, sprintf_char_minus);
  tcase_add_test(tc_s21_sprintf, sprint_string_null);
  // tcase_add_test(tc_s21_sprintf, sprintf_float);
  tcase_add_test(tc_s21_sprintf, sprintf_float_zero);
  tcase_add_test(tc_s21_sprintf, sprintf_double_min);
  // tcase_add_test(tc_s21_sprintf, sprintf_double);
  // tcase_add_test(tc_s21_sprintf, sprintf_double_negative);
  tcase_add_test(tc_s21_sprintf, sprintf_double_nan);
  tcase_add_test(tc_s21_sprintf, sprintf_percent);
  suite_add_tcase(s, tc_s21_sprintf);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  srunner_set_fork_status(sr, CK_NOFORK);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
