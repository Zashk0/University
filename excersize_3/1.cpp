#include <iostream>

using namespace std;

int main() {

  int int_var;
  char char_var;
  bool bool_var;
  float float_var;
  double double_var;

  cout << "Enter an integer: ";
  cin >> int_var;

  cout << "Enter a character: ";
  cin >> char_var;

  cout << "Enter a boolean value ( 1 is true or 0 is false): ";
  cin >> bool_var;

  cout << "Enter a floating-point number: ";
  cin >> float_var;

  cout << "Enter a double-precision floating-point number: ";
  cin >> double_var;

  cout << "The integer value is: " << int_var << endl;
  cout << "The character value is: " << char_var << endl;
  cout << "The boolean value is: " << bool_var << endl;
  cout << "The floating-point number is: " << float_var << endl;
  cout << "The double-precision floating-point number is: " << double_var << endl;

  return 0;
}
