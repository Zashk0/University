#include <iostream>
#include <cmath>   
#define _USE_MATH_DEFINES   

using namespace std;

double calculate_circle(int radius, double pi) {
    return pi*(radius*radius);
}

int main(){
    double pi = atan(1) * 4;
    int r_1, r_2,s_3;
    cout << "enter radius for the smaller circle: ";
    cin >> r_1;
    cout << "enter radius for the bigger circle: ";
    cin >> r_2;
    r_1 = calculate_circle(r_1,pi);
    r_2 = calculate_circle(r_2,pi);
    s_3 = r_2 - r_1;
    cout << "Surface area of small circle: "<< r_1<<endl;
    cout << "Surface area of bigger circle: "<< r_2<<endl;
    cout << "Surface area of outer circle: "<< s_3<<endl;

  return 0;
}