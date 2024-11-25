#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
  string paragraph;
  string newString;

  cout << "Enter the first word (EOF to stop): ";
  while (cin >> newString) {
    if (newString == "stop") {
      break;
    }
    paragraph += " " + newString;
    cout << "Enter the next word: ";
  }
  cout << "The paragraph is: " << paragraph;

  return 0;
}
