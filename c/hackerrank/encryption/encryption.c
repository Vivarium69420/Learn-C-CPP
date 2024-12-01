/* ========= Encryption =========
 * Link: https://www.hackerrank.com/challenges/encryption/problem
 * Difficulty: Medium
 *
 * # Intuition
 * - Remove spaces from the string
 * - Find the number of rows and columns. Special case where the number of
 *   rows * columns < len then rows++ (requirement)
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

void printMallocError() { printf("Memory allocation failed!\n"); }

char *removeSpaces(char *s) {
  size_t len = strlen(s);
  char *retVal = (char *)malloc(
      len + 1); // Allocate memory with extra byte for null terminator
  size_t index = 0;
  for (int i = 0; i < len; i++) {
    if (*(s + i) != ' ') {
      retVal[index] = s[i];
      index++;
    }
  }
  retVal[index] = '\0'; // Null-terminate the string
  return retVal;
}

void concatenate(char *str, char *str_cat) {
  char *space = " ";
  if (strlen(str_cat) > 0) {
    if (strlen(str) > 0) { // avoid creating empty at the beginning
      strncat(str, space, 1);
    }
    strncat(str, str_cat, strlen(str_cat));
  }
}

char *encryption(char *s) {
  char *noSpaces = removeSpaces(s);

  if (!noSpaces) {
    free(noSpaces);
    printMallocError();
    return NULL;
  }
  size_t len = strlen(noSpaces);
  int rows = floor(sqrt(len));
  int columns = ceil(sqrt(len));

  if (rows * columns < len) {
    rows++;
  }

  char *retVal = (char *)malloc((columns * rows + rows) * sizeof(char));
  if (!retVal) {
    free(retVal);
    printMallocError();
    return NULL;
  }

  retVal[0] = '\0';

  char *temp = (char *)malloc((columns * sizeof(char)) + 1);
  if (!temp) {
    free(temp);
    printMallocError();
    return NULL;
  }

  // Create an empty 2D array
  char **arr = (char **)malloc(rows * sizeof(char *));
  if (!arr) {
    free(noSpaces);
    printMallocError();
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    arr[i] = (char *)malloc((columns * sizeof(char)) + 1);
    if (!arr[i]) {
      for (int j = 0; j < i; i++) {
        free(arr[j]); // if at any index failed, free them
      }
      free(arr);
      free(noSpaces);
      printMallocError();
      return NULL;
    }
  }

  // Copy substrings into the array
  for (int i = 0; i < rows; i++) {
    strncpy(*(arr + i), s + i * columns, columns);
  }

  int pos = 0;
  for (int col = 0; col < columns; col++) {
    for (int row = 0; row < rows; row++) {
      if (arr[row][col] != '\0') {
        retVal[pos++] = arr[row][col];
      }
    }
    retVal[pos++] = ' ';
  }
  retVal[pos - 1] = '\0'; // Replace the last space with null-terminator

  // Free all dynamically allocated memory
  free(temp);
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
  free(noSpaces);

  return retVal;
};
