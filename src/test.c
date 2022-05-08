#include <check.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


START_TEST(test_1) {
  char str[N] = "(103-3)mod(5+4)";
  float standart = 1.000000;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

START_TEST(test_2) {
  char str[N] = "42+4-11*sin(3-1)";
  float standart = 35.997726;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

START_TEST(test_3) {
  char str[N] = "5mod3*21-ln(10)";
  float standart = 39.697414;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

START_TEST(test_4) {
  char str[N] = "sqrt(121)*sin(9-5)";
  float standart = -8.324827;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

START_TEST(test_5) {
  char str[N] = "12*(tan(3))/13+13";
  float standart = 12.868419;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

START_TEST(test_6) {
  char str[N] = "sqrt(256)+cos(7)*log(4)";
  float standart = 16.453894;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

START_TEST(test_7) {
  char str[N] = "13/(-2)/(-1)*(-2+12)/3";
  float standart = 21.666666;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

START_TEST(test_8) {
  char str[N] = "asin(0.5)+acos(0.5)+atan(0.5)+2^2";
  float standart = 6.034444;
  float res = 0;
  res = parse(str);
  ck_assert_float_eq(res, standart);
}
END_TEST

int main(void) {
  Suite* s1 = suite_create("Core");
  TCase* tc1_1 = tcase_create("calc_val");
  SRunner* sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);
  tcase_add_test(tc1_1, test_7);
  tcase_add_test(tc1_1, test_8);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
