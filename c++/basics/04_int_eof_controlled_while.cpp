#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
  int sum = 0;
  int num;

  cout << "Enter the first integer (EOF to stop): ";
  while (cin >> num) {
    sum += num;
    cout << "Enter the next integer: ";
  }
  cout << "The sum is: " << sum;

  return 0;
}
