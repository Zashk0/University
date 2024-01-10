#include <iostream>
using namespace std;

int main(){
    double x,y,price;
    cout<<"Enter the weight of the sweets: ";
    cin >> x;
    cout<<"Enter a diffrent weight of the sweets: ";
    cin >>y;
    cout<<"Enter the price of the sweets: ";
    cin >> price;
    x = x*price;
    y = y*price;
    cout << "Price of the first bach: " << x<<endl;
    cout << "Price of the first bach: " << y<<endl;

}