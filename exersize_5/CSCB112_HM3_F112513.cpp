//1
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
//2

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int romanToInt(std::string s) {
    std::unordered_map<char, int> translations = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int number = 0;
    s = s + ' ';
    for (int i = 0; i < s.size() - 1; i++) {
        if (translations[s[i]] < translations[s[i+1]]) {
            number -= translations[s[i]];
        } else {
            number += translations[s[i]];
        }
    }
    return number;
}
 
int main() {
    string roman;
    cin >>roman;
    std::cout << romanToInt(roman) << std::endl;
    return 0;
}
//3
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

//4
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string result = "";
    int i;
    int randomInteger;
    cout << "Enter a random integer: ";
    cin >> randomInteger;

    while (randomInteger > 0)
    {
        int digit = randomInteger % 10;
        result += to_string(digit);
        randomInteger /= 10;
    }
    for (i = result.length() - 1; i >= 0; i--)
    {
        cout << result[i]<<endl;
    }

    return 0;
}
