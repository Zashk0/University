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
