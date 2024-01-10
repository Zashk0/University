// 1
#include <stdio.h>
#include <string.h>
int isPalindrome(char str[], int length)
{
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {

        if (str[i] != str[j])
        {
            return 0; // Not a palindrome
        }
    }

    return 1;
}

int main()
{
    char input[20];

    printf("Enter a string (length not greater than 19): ");
    scanf("%s", input);

    int length = strlen(input);
    if (length <= 19)
    {
        if (isPalindrome(input, length))
        {
            printf("The string is a palindrome.\n");
        }
        else
        {
            printf("The string is not a palindrome.\n");
        }
    }
    else
    {
        printf("Length exceeds 19 characters. Please enter a shorter string.\n");
    }

    return 0;
}
// 2
#include <iostream>
#include <cstring>

int main()
{
    const int SIZE = 10;
    const int LEN = 10;

    char string[SIZE][LEN];

    int n;
    std::cout << "Enter the number of string (n > 1): ";
    std::cin >> n;

    if (n <= 1 || n > SIZE)
    {
        std::cerr << "Invalid input!Should be greater than 1 and less than or equal to " << SIZE << ".\n";
        return 1;
    }

    std::cout << "Enter " << n << " string:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> string[i];

        if (std::strlen(string[i]) > 9)
        {
            std::cerr << "Invalid input!.\n";
            return 1;
        }
    }

    bool isDecreasing = true;
    for (int i = 1; i < n; ++i)
    {

        if (std::strcmp(string[i], string[i - 1]) > 0)
        {
            isDecreasing = false;
            break;
        }
    }

    if (isDecreasing)
    {
        std::cout << "The sequence is monotonical.\n";
    }
    else
    {
        std::cout << "The sequence is not monotonical.\n";
    }

    return 0;
} // 3
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 10;

bool symmetry_checker(char matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int size;

    cout << "Enter the size of the square matrix: ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        cerr << "Invalid matrix size. Exiting program...\n";
        return 1;
    }

    char matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Row " << i + 1 << ": ";
        cin >> matrix[i];

        if (strlen(matrix[i]) > 9) {
            cerr << "String length should not be greater than 9. Exiting program...\n";
            return 1;
        }
    }

    if (symmetry_checker(matrix, size)) {
        cout << "The matrix is symmetrical about its main diagonal.\n";
    } else {
        cout << "The matrix is not symmetrical about its main diagonal.\n";
    }

    return 0;
}

// 4
#include<iostream>
#include<cstring> 
#include<stdlib.h> 

using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    char** strArray = new char*[n];

    cout << "Enter " << n << " numbers as strings (each > 999):" << endl;
    const int bufferSize = 100;
    for (int i = 0; i < n; ++i) {
        strArray[i] = new char[bufferSize];
        cin >> strArray[i];
    }

    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int num = atoi(strArray[i]);
        if (num > 999) {
            sum += num;
            ++count;
        }
    }

    if (count > 0) {
        double mean = static_cast<double>(sum) / count;
        cout << "Arithmetic mean: " << mean << endl;
    } else {
        cout << "No valid numbers greater than 999 entered." << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] strArray[i];
    }
    delete[] strArray;

    return 0;
}

// 5
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20
#define MAX_WORD_LENGTH 6

int isWordAboveSecondaryDiagonal(char matrix[MAX_SIZE][MAX_SIZE][MAX_WORD_LENGTH + 1], int n, const char *word)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i + j < n && strcmp(matrix[i][j], word) == 0)
            {
                return 1; 
            }
        }
    }

    return 0; 
}
void printMatrix(char matrix[MAX_SIZE][MAX_SIZE][MAX_WORD_LENGTH + 1], int n)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    char matrix[MAX_SIZE][MAX_SIZE][MAX_WORD_LENGTH + 1]; // 3D array for strings
    printf("Enter the size of the square matrix (1 < n < 20): ");
    scanf("%d", &n);
    printf("Enter the words for the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter word for matrix[%d][%d]: ", i, j);
            scanf("%s", matrix[i][j]);
        }
    }

    printMatrix(matrix, n);

    char word[MAX_WORD_LENGTH + 1];
    printf("Enter the word to check: ");
    scanf("%s", word);
    if (isWordAboveSecondaryDiagonal(matrix, n, word))
    {
        printf("The word '%s' is present above or on the secondary diagonal.\n", word);
    }
    else
    {
        printf("The word '%s' is not present above or on the secondary diagonal.\n", word);
    }

    return 0;
}
// 6
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20
#define MAX_WORD_LENGTH 6


int isWordAboveSecondaryDiagonal(char matrix[MAX_SIZE][MAX_SIZE][MAX_WORD_LENGTH + 1], int n, const char *word)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            
            if (i + j < n && strcmp(matrix[i][j], word) == 0)
            {
                return 1; 
            }
        }
    }

    return 0; 
}

void printMatrix(char matrix[MAX_SIZE][MAX_SIZE][MAX_WORD_LENGTH + 1], int n)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    char matrix[MAX_SIZE][MAX_SIZE][MAX_WORD_LENGTH + 1]; 

    printf("Enter the size of the square matrix (1 < n < 20): ");
    scanf("%d", &n);

    printf("Enter the words for the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter word for matrix[%d][%d]: ", i, j);
            scanf("%s", matrix[i][j]);
        }
    }

    printMatrix(matrix, n);

    char word[MAX_WORD_LENGTH + 1];
    printf("Enter the word to check: ");
    scanf("%s", word);

    if (isWordAboveSecondaryDiagonal(matrix, n, word))
    {
        printf("The word '%s' is present above or on the secondary diagonal.\n", word);
    }
    else
    {
        printf("The word '%s' is not present above or on the secondary diagonal.\n", word);
    }

    return 0;
}
