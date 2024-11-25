#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int sum = 0;
  int num;
  ifstream infile;

  infile.open("numbers.dat");

  while (infile >> num) {
    sum += num;
  }

  cout << "The sum is: " << sum;
  infile.close();

  return 0;
}
