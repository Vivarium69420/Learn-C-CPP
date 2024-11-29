#include "the-time-in-words.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void assert_timeInWords(int h, int m, const char* expected,
                        const char* testcase) {
  char* result = timeInWords(h, m);
  CU_ASSERT_STRING_EQUAL(result, expected);
  if (strcmp(result, expected) != 0) {
    printf(
        "\n===================================================================="
        "==========\n");
    printf("%s - Expected: '%s', but got: '%s'", testcase, expected, result);
  }
}

void test_timeInWords() {
  assert_timeInWords(5, 0, "five o' clock", "TC_01");
  assert_timeInWords(5, 1, "one minute past five", "TC_02");
  assert_timeInWords(5, 10, "ten minutes past five", "TC_03");
  assert_timeInWords(5, 15, "quarter past five", "TC_04");
  assert_timeInWords(5, 30, "half past five", "TC_05");
  assert_timeInWords(5, 40, "twenty minutes to six", "TC_06");
  assert_timeInWords(5, 45, "quarter to six", "TC_07");
  assert_timeInWords(5, 47, "thirteen minutes to six", "TC_08");
  assert_timeInWords(5, 28, "twenty eight minutes past five", "TC_09");
  assert_timeInWords(12, 0, "twelve o' clock", "TC_10");
  assert_timeInWords(12, 59, "one minute to one", "TC_11");
  printf(
      "\n===================================================================="
      "==========\n");
}

int main() {
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("the-time-in-words-test", NULL, NULL);
  CU_add_test(suite, "test_timeInWords", test_timeInWords);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();

  return 0;
}