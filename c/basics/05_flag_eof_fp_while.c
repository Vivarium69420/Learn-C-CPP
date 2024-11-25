#include <stdio.h>

int main(void) {
  int sum = 0;
  int num;
  FILE *fp;

  fp = fopen("numbers.dat", "r");

  while ((fscanf(fp, "%d", &num)) != EOF) {
    sum += num;
  }

  printf("%d\n", sum);

  fclose(fp);

  return 0;
}
