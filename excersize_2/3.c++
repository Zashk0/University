#include <iostream>
#include <math.h>

using namespace std;
float root_mean_square(float a,float b, float c){
    return sqrt((a*a+b*b+c*c)/3);
}
int main(){
    float a,b,c;
    cout << "Enter three real numbers";
    cin >> a>>b>>c;
    float rms = root_mean_square(a,b,c);
    cout << "The root mean square is: " << rms << endl;

  return 0;
}