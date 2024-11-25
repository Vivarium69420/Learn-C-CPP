#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
  int num1;
  int num2;
  int sum;

  cout << "Enter the first number: ";
  cin >> num1;
  
  cout << "Enter the second number: ";
  cin >> num2;

  sum = num1 + num2;

  cout << "The sum is: " << sum;

  return 0;
}
