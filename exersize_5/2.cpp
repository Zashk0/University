
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int romanToInt(std::string s) {
    std::unordered_map<char, int> translations = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int number = 0;
    s = s + ' ';
    for (int i = 0; i < s.size() - 1; i++) {
        if (translations[s[i]] < translations[s[i+1]]) {
            number -= translations[s[i]];
        } else {
            number += translations[s[i]];
        }
    }
    return number;
}
 
int main() {
    string roman;
    cin >>roman;
    std::cout << romanToInt(roman) << std::endl;
    return 0;
}