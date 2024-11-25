#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int *nums, int numsSize) {
  // Sort the array
  qsort(nums, numsSize, sizeof(int), compare);

  // Check for duplicates in the sorted array
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1]) {
      return true;
    }
  }

  return false;
}

int main(void) {
  int nums[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,
                16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
                32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 4};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  printf("var = %d\n", containsDuplicate(nums, numsSize));
}