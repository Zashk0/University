#include <iostream>

using namespace std;

int main() {
  string name, surname;
  float weight;

  cout << "Enter your name: ";
  cin >> name;

  cout << "Enter your surname: ";
  cin >> surname;

  cout << "Enter your weight: ";
  cin >> weight;

  cout << "\nYour name is: " << name << endl;
  cout << "Your surname is: " << surname << endl;
  cout << "Your weight is: " << weight << " kg" << endl;

  return 0;
}
