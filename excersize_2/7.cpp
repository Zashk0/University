#include <iostream>
using namespace std;

int main(){
    float cel,far;
    cout << "Enter celsius: ";
    cin >> cel;
    far = cel * 9/5 +32;
    cout << cel << " celsius Is equat to "<<far<< " farenheit"<<endl;
    cout << "Enter farenheit";
    cin >> far;
    cel = (far-32)*5/9;
    cout << cel << " celsius Is equat to "<<far<< " farenheit"<<endl;
    return 0;
}