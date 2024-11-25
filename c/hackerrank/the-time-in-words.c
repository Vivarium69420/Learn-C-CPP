#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int time;
  char *word;
} TimeInWords_t;

TimeInWords_t time_in_words[] = {{1, "one"},   {2, "two"},      {3, "three"},
                                 {4, "four"},  {5, "five"},     {6, "six"},
                                 {7, "seven"}, {8, "eight"},    {9, "nine"},
                                 {10, "ten"},  {15, "quarter"}, {20, "twenty"}};

char *getTimeInWord(int time) {
  char *ret_val;
  for (int i = 0; i < sizeof(time_in_words) / sizeof(time_in_words[0]); i++) {
    if (time_in_words[i].time == time) {
      ret_val = time_in_words[i].word;
      break;
    }
  }
  return ret_val;
}

void concatenate(char *str, char *str_cat) {
  strncat(str, str_cat, strlen(str_cat));
}

char *timeInWords(int h, int m) {
  char *ret_val = "";
  char *o_clock = "o'clock";  // minutes = 0
  char *past = "past";        // 1 <= minutes <= 30
  char *to = "to";            // minutes > 30
  char *hour = getTimeInWord(h);
  char *minutes;

  // Allocate memory for ret_val to hold the hour
  ret_val = (char *)malloc(strlen(hour) + 1);  // +1 for the null-terminator
  if (ret_val == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  ret_val[0] = '\0';  // Ensure the memory is an empty string

  if (m == 0) {
    // strcat(ret_val, hour);
    concatenate(ret_val, hour);
    printf("var = %s\n", ret_val);
  }

  return ret_val;
}

int main(void) {
  char *result;
  result = timeInWords(5, 0);

  return 0;
}
