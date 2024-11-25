/*
 * Extracts and prints the left-most digit of any nonnegative integer
 * 247 -> 2
 * 7562 -> 7
 * */

#include <iostream>

using namespace std;

int main() {
  int num;
  int leftMostDigit;

  cout << "Enter a non-negative integer: ";
  cin >> num;

  do {
    leftMostDigit = num;
    num /= 10;
  } while (num > 0);

  cout << "The left-most digit is " << leftMostDigit << endl;

  return 0;
}
