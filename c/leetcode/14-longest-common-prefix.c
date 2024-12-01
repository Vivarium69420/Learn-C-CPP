/* ========= Longest Common Prefix =========
 * Link: https://leetcode.com/problems/longest-common-prefix/
 * Difficulty: Easy
 *
 * # Intuition
 * - Find the string with the longest length so we can properly iterate
 * through individual string
 * - Fixed the character index, and iterate through all the string inside the
 * array
 * - Choose the first string as the key, check for each character, if any of the
 * latter string does not comply to this, return immediately
 *
 * # Comment
 * - REMEMBER TO TERMINATE A STRING WITH A NULL TERMINATOR AT THE LAST INDEX
 * */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PREFIX_LENGTH 256

size_t longestCharInCharArr(char **arr, size_t len) {
  size_t longestCharLen = 0;
  for (size_t i = 0; i < len; i++) {
    size_t currCharLen = strlen(arr[i]);
    longestCharLen =
        (currCharLen > longestCharLen) ? currCharLen : longestCharLen;
  }
  return longestCharLen;
}

char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize == 0) {
    return "";
  }
  size_t longestCharLen = longestCharInCharArr(strs, strsSize);
  size_t retValIdx = 0;
  // static char retVal[MAX_PREFIX_LENGTH] = {0};
  // memset(retVal, 0, MAX_PREFIX_LENGTH);
  char *retVal = (char *)malloc(
      (longestCharLen + 1) *
      sizeof(char)); // Allocate memory for the longest prefix + null terminator
  if (!retVal) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < longestCharLen; i++) {
    char currChar = strs[0][i]; // Using the first word as the key
    for (size_t j = 1; j < strsSize; j++) {
      if (strs[j][i] != currChar) { // If the next index is differt return
                                    // current longest prefix
        retVal[retValIdx] = '\0';   // Null terminate the string
        return retVal;
      }
    }
    retVal[retValIdx++] = currChar;
  }
  retVal[retValIdx] = '\0'; // Null terminate the string
  return retVal;
}

int main(void) {
  char *strs[] = {"flower", "flow", "flight"};
  char *strs2[] = {"dog", "racecar", "car"};
  size_t len = sizeof(strs) / sizeof(strs[0]);
  size_t longestChar = longestCharInCharArr(strs, len);
  char *result = longestCommonPrefix(strs, len);
  printf("Longest common prefix: %s\n", result);

  len = sizeof(strs2) / sizeof(strs2[0]);
  longestChar = longestCharInCharArr(strs2, len);
  result = longestCommonPrefix(strs2, len);
  printf("Longest common prefix: %s\n", result);

  return EXIT_SUCCESS;
}
