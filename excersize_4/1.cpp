#include <iostream>

using namespace std;
int main(){
    int x;
    cout<<"Enter a 2 digit number: ";
    cin >> x;

    int first_digit = x%10;
    int second_digit = x/10;
    int sum = first_digit +second_digit;
    int product = first_digit*second_digit;
    cout << "The sum of the digits is "<< sum<<endl;
    cout << "The product of the digits is "<< product<<endl;
    
}