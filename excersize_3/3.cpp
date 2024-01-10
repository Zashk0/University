#include <iostream>

using namespace std;

int main() {
  // Declare two integer variables
  int a, b;

  // Prompt the user to enter two integer values
  cout << "Enter two integer values: ";
  cin >> a >> b;

  // Print the initial values of the variables
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  // Perform ALL abbreviated mathematical operations on the variables
  cout << "a += b: ";
  a += b;
  cout << a << endl;

  cout << "a -= b: ";
  a -= b;
  cout << a << endl;

  cout << "a = b: ";
  a= b;
  cout << a << endl;

  cout << "a /= b: ";
  a /= b;
  cout << a << endl;

  cout << "a %= b: ";
  a %= b;
  cout << a << endl;

  cout << "a <<= b: ";
  a <<= b;
  cout << a << endl;

  cout << "a >>= b: ";
  a >>= b;
  cout << a << endl;

  cout << "a &= b: ";
  a &= b;
  cout << a << endl;

  cout << "a |= b: ";
  a |= b;
  cout << a << endl;

  cout << "a ^= b: ";
  a ^= b;
  cout << a << endl;

  return 0;
}