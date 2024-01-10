#include <iostream>
#include <math.h>   
#define _USE_MATH_DEFINES   
# define M_PI           3.14159265358979323846
using namespace std;

double degree_to_rad(double degrees) {
  return degrees * M_PI / 180.0;
}
double rad_to_degrees(double rad) {
  return rad * 180.0 / M_PI;
}

int main(){
    double degree, rad;
    cout << "Enter degrees:";
    cin >> degree;
    rad = degree_to_rad(degree);
    cout<< "Radians" << rad<< endl;
    cout << "Enter Radians:";
    cin >> rad;

    degree = rad_to_degrees(rad);
    cout << "Degrees: " << degree << endl;

  return 0;
}