#include <stdio.h>

void bubble_sort(int *arr, int size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    int swapped = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = 1;
      }
    }
    if (swapped == 0)
      break;
  }
}

void merge(int *nums1, int m, int *nums2, int n) {
  for (int i = 0; i < n; i++) {
    nums1[m + i] = nums2[i];
  }
  bubble_sort(nums1, m + n);
}

int main() {
  int nums1[] = {1, 2, 3, 0, 0, 0};
  int nums2[] = {2, 5, 6};
  int m = 3;
  int n = 3;

  merge(nums1, m, nums2, n);
  // Print the sorted array in nums1
  for (int i = 0; i < m + n; i++) {
    printf("var = %d\n", nums1[i]);
  }
  return 1;
}
