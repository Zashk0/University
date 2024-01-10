// 1
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

  cout << "Enter a boolean value ( 1is true or 0 is false): ";
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
//2
#include <iostream>

using namespace std;

int main() {

  int a, b;

  cout << "Enter two integer values with space in between: ";
  cin >> a >> b;

  cout << "a + b = " << a + b << endl;
  cout << "a - b = " << a - b << endl;
  cout << "a * b = " << a * b << endl;
  cout << "a / b = " << a / b << endl;
  cout << "a % b = " << a % b << endl;

  return 0;
}
//3
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
//4
#include <iostream>

using namespace std;

int main()
{

    int a, b;

    cout << "Enter two integer values divided by space:";
    cin >> a >> b;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
