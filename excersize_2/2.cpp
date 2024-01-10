#include <iostream>
using namespace std;

int main(){
    int number;

    cout << "Enter a three-digit number:";
    cin >> number;

    int hundredsDigit = number / 100;
    int tensDigit = ( number%100)/10;
    int unitsDigit= number %10;

    cout << "Hundreds digit: " << hundredsDigit << endl;
    cout << "Tens digit: " << tensDigit << endl;
    cout << "Units digit: " << unitsDigit << endl;

  return 0;
}