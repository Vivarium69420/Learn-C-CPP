#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
  string first;
  string initial;
  string last;
  string space = " ";
  string dot = ".";
  string fullName;

  cout << "Enter the first name: ";
  cin >> first;

  cout << "Enter the initial: ";
  cin >> initial;

  cout << "Enter the last name: ";
  cin >> last;

  fullName = first + space + initial + dot + space + last;

  cout << "The full name is: " << fullName;
  return 0;
}
