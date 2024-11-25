#include <string.h>

typedef struct {
  char *key;
  int value;
} Roman;

Roman roman[] = {{"I", 1},   {"V", 5},   {"X", 10},  {"L", 50},
                 {"C", 100}, {"D", 500}, {"M", 1000}};

int getValue(char c) {
  int retVal;
  for (int i = 0; i < sizeof(roman) / sizeof(roman[0]); i++) {
    if (roman[i].key[0] == c) {
      retVal = roman[i].value;
      break;
    }
  }
  return retVal;
}

int romanToInt(char *s) {
  size_t length = strlen(s);
  size_t count = length - 1;
  int total = 0;
  int prev_value = 0;

  for (size_t i = 0; i < length; i++) {
    int current = getValue(s[count]);
    if (current < prev_value)
      total -= current;
    else
      total += current;
    prev_value = current;
    count--;
  }
  return total;
}
