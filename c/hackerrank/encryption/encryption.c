/* ========= Encryption =========
 * Link: https://www.hackerrank.com/challenges/encryption/problem
 *
 * # Intuition
 * - Remove spaces from the string
 * - Find the number of rows and columns. Special case where the number of
 *   rows * columns < strlen(s) then rows++ (requirement)
 * - Create a 2D array and copy the substrings into the array
 * - Iterate through the rows and columns to create the encrypted string. Avoids
 *   invalid index by checking the length of the string.
 * - Concatenate the strings with a space in between.
 *
 * # Complexity
 * - Time: O(n^2): There are two for loops, one for copying the substrings into
 *   the array and one for creating the encrypted string.
 * - Space: O(n): The space complexity is O(n) because we are creating a 2D
 *   array to store the substrings.
 *
 * # Comment
 * - This was tested by SonatGames as an code challenge
 * */

#include "encryption.h"

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeSpaces(char *s) {
  char *ret_val = (char *)malloc(
      strlen(s) + 1);  // Allocate memory with extra byte for null terminator
  size_t index = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (*(s + i) != ' ') {
      ret_val[index] = s[i];
      index++;
    }
  }
  ret_val[index] = '\0';  // Null-terminate the string
  return ret_val;
}

void concatenate(char *str, char *str_cat) {
  char *space = " ";
  if (strlen(str_cat) > 0) {
    if (strlen(str) > 0) {  // avoid creating empty at the beginning
      strncat(str, space, 1);
    }
    strncat(str, str_cat, strlen(str_cat));
  }
}

char *encryption(char *s) {
  s = removeSpaces(s);
  int rows = floor(sqrt(strlen(s)));
  int columns = ceil(sqrt(strlen(s)));

  if (rows * columns < strlen(s)) {
    rows++;
  }

  // Create an empty 2D array
  char **arr = (char **)malloc(rows * sizeof(char *));
  for (int i = 0; i < rows; i++) {
    arr[i] = (char *)malloc(columns * sizeof(char));
  }

  // Copy substrings into the array
  for (int i = 0; i < rows; i++) {
    strncpy(*(arr + i), s + i * columns, columns);
  }

  char *ret_val = (char *)malloc((rows * columns));
  if (ret_val == NULL) {
    return NULL;
  }
  ret_val[0] = '\0';

  char *temp = (char *)malloc(columns + 1);
  if (temp == NULL) {
    return NULL;
  }
  for (int col = 0; col < columns; col++) {
    memset(temp, 0, rows + 1);  // Clear the temp string
    for (int row = 0; row < rows; row++) {
      // Ensure the index is within bounds
      // row * columns = starting index of the current row in the original
      // string, then add col to get the exact index based on the current row
      if (row * columns + col < strlen(s)) {
        strncpy(temp + row, &arr[row][col], 1);
      }
    }
    concatenate(ret_val, temp);
  }

  return ret_val;
};