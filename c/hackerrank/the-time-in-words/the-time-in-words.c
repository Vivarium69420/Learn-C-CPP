/* ========= The Time in Words =========
 * Link: https://www.hackerrank.com/challenges/the-time-in-words/problem
 * Difficulty: Medium
 *
 * # Intuition
 * - Create a dictionary to match the time to a word (I hate doing this
 * manually)
 * - Simply break down the minutes into tens and ones, then match with
 * dictionary. The minutes determination have few important edge cases such as:
 *   - < 20: The counting is special
 *   - == 15 || == 30: Special half and quarter mark
 *   - == 1: minute (singular)
 *   - > 1: minutes (plural)
 * - Concatenate strings need to be carefull to make sure enough memory space.
 * Also check:
 *   - String initially empty, we avoid adding space, if not result into " ..."
 *   - The added string should not be empty.
 * - DO NOT FORGET TO ALLOCATE RETURN VALUES.
 *
 * # Complexity
 * - Time: O(1). There is not any multiple for loops, just one for finding
 * values.
 * - Space: O(1). There are not much growth in the size of input, only a single
 * time stampt.
 *
 * # Comment
 * - This was tested by SonatGames as an code challenge, with two other
 *   question in 50 MINUTES, IT IS NOT POSSIBLE.
 * - This was mine first problem in hackerrank
 * */

#include "the-time-in-words.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_MINUTES 60
#define BYTES_ALLOCATION 200

typedef struct {
  int time;
  char *word;
} TimeInWords_t;

TimeInWords_t time_in_words[] = {
    {1, "one"},        {2, "two"},       {3, "three"},     {4, "four"},
    {5, "five"},       {6, "six"},       {7, "seven"},     {8, "eight"},
    {9, "nine"},       {10, "ten"},      {11, "eleven"},   {12, "twelve"},
    {13, "thirteen"},  {14, "fourteen"}, {15, "quarter"},  {16, "sixteen"},
    {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"},
    {30, "half"}};

char *getTimeInWord(int time) {
  char *ret_val = (char *)malloc(BYTES_ALLOCATION);
  for (int i = 0; i < sizeof(time_in_words) / sizeof(time_in_words[0]); i++) {
    if (time_in_words[i].time == time) {
      ret_val = time_in_words[i].word;
      break;
    }
  }
  return ret_val;
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

char *getMinutes(int minutes) {
  char *ret_val = (char *)malloc(BYTES_ALLOCATION);
  if (!ret_val) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  char *tens = getTimeInWord((minutes / 10) * 10);
  concatenate(ret_val, tens);
  char *ones = getTimeInWord(minutes % 10);
  concatenate(ret_val, ones);
  return ret_val;
}

char *getMinutesWithCheck(int minutes) {
  char *ret_val = (char *)malloc(BYTES_ALLOCATION);
  if (!ret_val) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  ret_val[0] = '\0'; // Initialize as empty string
  //
  char *ret_minutes;
  if (minutes < 20 || minutes == 30) {
    ret_minutes = getTimeInWord(minutes);
  } else {
    ret_minutes = getMinutes(minutes);
  }
  concatenate(ret_val, ret_minutes);
  if (minutes != 15 && minutes != 30) {
    if (minutes == 1) {
      concatenate(ret_val, "minute");
    } else {
      concatenate(ret_val, "minutes");
    }
  }
  return ret_val;
}

char *timeInWords(int h, int m) {
  char *ret_val;
  char *o_clock = "o' clock"; // minutes = 0
  char *past = "past";        // 1 <= minutes <= 30
  char *to = "to";            // minutes > 30
  char *hour;
  char *minutes;
  int remaining_time;

  ret_val = (char *)malloc(BYTES_ALLOCATION);

  if (ret_val == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  ret_val[0] = '\0'; // Ensure the memory is an empty string

  if (m == 0) {
    hour = getTimeInWord(h);
    concatenate(ret_val, hour);
    concatenate(ret_val, o_clock);
  } else if (1 <= m && m <= 30) {
    hour = getTimeInWord(h);
    minutes = getMinutesWithCheck(m);
    concatenate(ret_val, minutes);
    concatenate(ret_val, past);
    concatenate(ret_val, hour);
  } else {
    remaining_time = TOTAL_MINUTES - m;
    hour = getTimeInWord(h + 1);
    minutes = getMinutesWithCheck(remaining_time);
    concatenate(ret_val, minutes);
    concatenate(ret_val, to);
    concatenate(ret_val, hour);
  }
  return ret_val;
}
