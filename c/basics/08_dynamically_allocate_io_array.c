#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int size;
  printf("Please enter the size of array: ");
  scanf("%d", &size);
  int *arr = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    printf("Please enter a number: ");
    scanf("%d", arr + i);
  }
  for (int i = 0; i < size; i++) {
    printf("You have entered: %d\n", *(arr + i));
  }
  return 1;
}
