#include <stdio.h>
typedef struct {
  char a; // 1 byte
  int b;  // 4 bytes
  char c; // 1 byte
} mystr;

typedef union {
  char a; // 1 byte
  int b;  // 4 bytes
  char c; // 1 byte
} myuni;

int main(void) {
  printf("%lu\n", sizeof(mystr));
  printf("%lu\n", sizeof(myuni));
  return 0;
}
