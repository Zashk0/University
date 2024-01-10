#include <iostream>

using namespace std;

int main()
{
    long long int x;
    cout << "Enter your number that is no longer than 19 numbers:";
    cin >> x;
    unsigned long long int number_of_digits = 0;

    do
    {
        ++number_of_digits;
        x /= 10;
    } while (x);

    cout << number_of_digits;
    return 0;
}