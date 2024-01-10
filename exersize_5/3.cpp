#include <iostream>

using namespace std;

#define MIN 1.0
#define MAX 100.0

int main() {
  // Get the real number from the user
  double number;
  cout << "Enter a real number: ";
  cin >> number;

  // Check if the real number belongs to the interval [MIN, MAX]
  if (number >= MIN && number <= MAX) {
    cout << "The real number belongs to the interval [MIN, MAX]" << endl;
  } else {
    cout << "The real number does not belong to the interval [MIN, MAX]" << endl;
  }

  return 0;
}
