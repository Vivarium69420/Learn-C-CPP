#include "encryption.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void assert_encryption(char* s, const char* expected, const char* testcase) {
  char* result = encryption(s);
  CU_ASSERT_STRING_EQUAL(result, expected);
  if (strcmp(result, expected) != 0) {
    printf(
        "\n===================================================================="
        "==========\n");
    printf("%s - Expected: '%s', but got: '%s'", testcase, expected, result);
  }
}

void test_encryption() {
  assert_encryption("haveaniceday", "hae and via ecy", "TC_01");
  assert_encryption("feedthedog", "fto ehg ee dd", "TC_02");
  assert_encryption("chillout", "clu hlt io", "TC_03");
  assert_encryption(
      "ifmanwasmeanttostayonthegroundgodwouldhavegivenusroots",
      "imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau", "TC_04");
  assert_encryption(
      "bgwdyygtmwhtwhusfedckrgybozfjaukgsngqvzftiypqukxypbkghjiwkphkjtsdizueaz",
      "bwdfqujs ghcjvkid wtkazxwi dwrufykz yhgktppu yuygibhe gsbsykka tfonpgjz "
      "mezgqht",
      "TC_05");
  assert_encryption("iffactsdontfittotheorychangethefacts",
                    "isieae fdtonf fotrga anoyec cttctt tfhhhs", "TC_06");
  assert_encryption(
      "wclwfoznbmyycxvaxagjhtexdkwjqhlojykopldsxesbbnezqmixfpujbssrbfhlgubvfhpf"
      "liimvmnny",
      "wmgjpnull cyjqlejgi lyhhdzbui wctlsqsbm fxeoxmsvv ovxjeirfm zadysxbhn "
      "nxkkbffpn bawobphfy",
      "TC_07");
  printf(
      "\n===================================================================="
      "==========\n");
}

int main() {
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("encryption-test", NULL, NULL);
  CU_add_test(suite, "test_encryption", test_encryption);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();

  return 0;
}