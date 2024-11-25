/*
 * Assume we want to print a month when the number of days in the month and the
 * first week day in the month (0 to 6 for Sunday through Saturday) is give
 * */

#include <iomanip>
#include <iostream>
#include <ostream>

using namespace std;

int main(int argc, char *argv[]) {
  int startDay;
  int daysInMonth;
  int col = 1;

  // Validation of number of day in the month
  do {
    cout << "Enter the number of days in the month (28, 29, 30, or 31): ";
    cin >> daysInMonth;
  } while (daysInMonth < 28 || daysInMonth > 31);

  // Validation of start day
  do {
    cout << "Enter the start date of the month (0 - 6): ";
    cin >> startDay;
  } while (startDay < 0 || startDay > 6);

  // Print titiles
  cout << endl;
  cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
  cout << "--- --- --- --- --- --- ---" << endl;

  // Print spaces before start date
  for (int space = 0; space < startDay; space++) {
    cout << "   ";
    col++;
  }

  for (int day = 1; day <= daysInMonth; day++) {
    cout << setw(3) << day << " ";
    col++;

    if (col > 7) {
      cout << endl;
      col = 1;
    }
  }

  // Print the calender
  return 0;
}
