#include <iostream>
#include <string>

using namespace std;

string roman_numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int decimal_values[] =    {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string integer_to_Roman(int n) {
  string result = "";
  int i = 0;
  while (n > 0) {
    while (n >= decimal_values[i]) {
      result += roman_numerals[i];
      n -= decimal_values[i];
    }
    i++;
  }
  return result;
}

int main() {
  int n;
  cout << "Enter a decimal number: ";
  cin >> n;

  if (n < 1 || n > 3999) {
    cout << "Invalid input. The number must be between 1 and 3999." << endl;
    return 1;
  }

  string roman_numeral = integer_to_Roman(n);

  cout << "The Roman numeral for " << n << " is: " << roman_numeral << endl;

  return 0;
}
