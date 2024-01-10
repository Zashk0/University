#include <iostream>

// Recursive function to convert a character string of digits to a natural number
unsigned int stringToNatural(const char* str) {
    // Base case: If the current character is the null terminator, return 0.
    if (*str == '\0') {
        return 0;
    }

    // Convert the current character to a digit and add it to the result.
    unsigned int digit = *str - '0';

    // Recursively process the remaining characters and calculate the result.
    unsigned int result = digit + 10 * stringToNatural(str + 1);

    return result;
}

int main() {
    char inputString[100];

    std::cout << "Enter a string of digits: ";
    std::cin >> inputString;

    unsigned int naturalNumber = stringToNatural(inputString);

    std::cout << "Corresponding natural number: " << naturalNumber << std::endl;

    return 0;
}
