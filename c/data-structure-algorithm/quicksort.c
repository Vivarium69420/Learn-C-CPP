#include <stdio.h>

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *A, int lo, int hi) {
  int i = lo;
  int pivot = A[hi];

  for (int j = lo; j <= hi - 1; j++) {
    if (A[j] <= pivot) {
      swap(&A[i], &A[j]);
      i++;
    }
  }

  swap(&A[i], &A[hi]);
  return i;
}

void quick_sort(int *A, int lo, int hi) {
  if (lo >= hi || lo < 0) // Two ends meets
    return;

  int p = partition(A, lo, hi);
  quick_sort(A, lo, p - 1);
  quick_sort(A, p + 1, hi);
}

int main(void) {
  int A[] = {1, 9, 5, 4, 3, 4};
  int size = sizeof(A) / sizeof(A[0]);
  quick_sort(A, 0, size - 1);

  for (int i = 0; i < size; i++) {
    printf("var = %d\n", A[i]);
  }
  return 0;
}
