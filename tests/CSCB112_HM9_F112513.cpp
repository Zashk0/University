
//1
#include <iostream>

const int MAX_SIZE = 100;

void deleteElement(int arr[], int &size, int position)
{
    if (position < 0 || position >= size)
    {
        std::cout << "Invalid position for deletion." << std::endl;
        return;
    }

    for (int i = position; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    --size;
}

void addElementToEnd(int arr[], int &size, int element)
{
    if (size < MAX_SIZE)
    {
        arr[size] = element;
        ++size;
    }
    else
    {
        std::cout << "Array is full. Cannot add more elements." << std::endl;
    }
}

void addElementAtPosition(int arr[], int &size, int element, int position)
{
    if (size >= MAX_SIZE)
    {
        std::cout << "Array is full. Cannot add more elements." << std::endl;
        return;
    }

    if (position < 0 || position > size)
    {
        std::cout << "Invalid position for insertion." << std::endl;
        return;
    }

    for (int i = size; i > position; --i)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    ++size;
}

void changeValueAtPosition(int arr[], int size, int position, int newValue)
{
    if (position < 0 || position >= size)
    {
        std::cout << "Invalid position for value change." << std::endl;
        return;
    }

    arr[position] = newValue;
}

int main()
{
    int arr[MAX_SIZE];
    int size = 0;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> size;

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    int choice;
    do
    {
        std::cout << "\nChoose an operation:\n";
        std::cout << "1. Delete an element\n";
        std::cout << "2. Add an element to the end\n";
        std::cout << "3. Add an element to a selected position\n";
        std::cout << "4. Change the value of a selected item\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int position;
            std::cout << "Enter the position to delete: ";
            std::cin >> position;
            deleteElement(arr, size, position);
            break;
        }
        case 2:
        {
            int element;
            std::cout << "Enter the element to add to the end: ";
            std::cin >> element;
            addElementToEnd(arr, size, element);
            break;
        }
        case 3:
        {
            int element, position;
            std::cout << "Enter the element to add: ";
            std::cin >> element;
            std::cout << "Enter the position to add at: ";
            std::cin >> position;
            addElementAtPosition(arr, size, element, position);
            break;
        }
        case 4:
        {
            int position, newValue;
            std::cout << "Enter the position to change: ";
            std::cin >> position;
            std::cout << "Enter the new value: ";
            std::cin >> newValue;
            changeValueAtPosition(arr, size, position, newValue);
            break;
        }
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

        std::cout << "Modified Array: ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

    } while (choice != 0);

    return 0;
}
//2
#include <iostream>
#include <string>

const int MAX_STUDENTS = 100; // Maximum number of students in the list

struct Student {
    std::string name;
    int facultyNumber;
};

// Function declarations
void displayStudents(const Student students[], int numStudents);
void addStudent(Student students[], int& numStudents);
void deleteStudent(Student students[], int& numStudents, int facultyNumber);
void changeFacultyNumber(Student students[], int numStudents, int oldFacultyNumber, int newFacultyNumber);
void findStudentByFacultyNumber(const Student students[], int numStudents, int facultyNumber);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Delete Student\n";
        std::cout << "3. Change Faculty Number\n";
        std::cout << "4. Find Student by Faculty Number\n";
        std::cout << "5. Display Students\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2: {
                int facultyNumber;
                std::cout << "Enter Faculty Number to delete: ";
                std::cin >> facultyNumber;
                deleteStudent(students, numStudents, facultyNumber);
                break;
            }
            case 3: {
                int oldFacultyNumber, newFacultyNumber;
                std::cout << "Enter Faculty Number to change: ";
                std::cin >> oldFacultyNumber;
                std::cout << "Enter new Faculty Number: ";
                std::cin >> newFacultyNumber;
                changeFacultyNumber(students, numStudents, oldFacultyNumber, newFacultyNumber);
                break;
            }
            case 4: {
                int facultyNumber;
                std::cout << "Enter Faculty Number to find: ";
                std::cin >> facultyNumber;
                findStudentByFacultyNumber(students, numStudents, facultyNumber);
                break;
            }
            case 5:
                displayStudents(students, numStudents);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

void displayStudents(const Student students[], int numStudents) {
    std::cout << "\nCurrent Students:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Name: " << students[i].name << "\t";
        std::cout << "Faculty Number: " << students[i].facultyNumber << "\n";
    }
}

void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        std::cout << "Enter student name: ";
        std::cin >> students[numStudents].name;
        std::cout << "Enter faculty number: ";
        std::cin >> students[numStudents].facultyNumber;
        numStudents++;
        std::cout << "Student added successfully.\n";
        displayStudents(students, numStudents);
    } else {
        std::cout << "Cannot add more students. Maximum limit reached.\n";
    }
}

void deleteStudent(Student students[], int& numStudents, int facultyNumber) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].facultyNumber == facultyNumber) {
            // Move the last student to the deleted position
            students[i] = students[numStudents - 1];
            numStudents--;
            std::cout << "Student deleted successfully.\n";
            displayStudents(students, numStudents);
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void changeFacultyNumber(Student students[], int numStudents, int oldFacultyNumber, int newFacultyNumber) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].facultyNumber == oldFacultyNumber) {
            students[i].facultyNumber = newFacultyNumber;
            std::cout << "Faculty number changed successfully.\n";
            displayStudents(students, numStudents);
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void findStudentByFacultyNumber(const Student students[], int numStudents, int facultyNumber) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].facultyNumber == facultyNumber) {
            std::cout << "Student found:\n";
            std::cout << "Name: " << students[i].name << "\n";
            std::cout << "Faculty Number: " << students[i].facultyNumber << "\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}
//3
#include <iostream>
#include <cstring>

int calculateCarriages(char trainComposition[], int n, int m) {
   
    if (n < 0 || m < 0 || n >= strlen(trainComposition) || m >= strlen(trainComposition)) {
        std::cerr << "Invalid carriage numbers." << std::endl;
        return -1;
    }

    int startIdx = std::min(n, m);
    int endIdx = std::max(n, m);

    for (int i = startIdx; i <= endIdx; ++i) {
       
        std::cout << "Carriage " << i + 1 << ": " << trainComposition[i] << std::endl;
    }

    return 0; 
}

int main() {

    char trainComposition[] = "LBOPKRKSKPMRKKPP";

    int n, m;
    std::cout << "Enter the starting carriage number (n): ";
    std::cin >> n;
    std::cout << "Enter the ending carriage number (m): ";
    std::cin >> m;

    int result = calculateCarriages(trainComposition, n - 1, m - 1);

    if (result == 0) {
        std::cout << "Calculation successful." << std::endl;
    } else {
        std::cerr << "Calculation failed." << std::endl;
    }

    return 0;
}
//4
#include <iostream>

void fill2DArray(int** array, int rows, int cols) {
    int value = 1;

    for (int i = 0; i < rows; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter value for array[" << i << "][" << j << "]: ";
                std::cin >> array[i][j];
            }
        } else {
            for (int j = cols - 1; j >= 0; --j) {
                std::cout << "Enter value for array[" << i << "][" << j << "]: ";
                std::cin >> array[i][j];
            }
        }
    }
}

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    fill2DArray(array, rows, cols);

    std::cout << "Filled 2D array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
//5
#include <iostream>
#include <cstring> 

void deleteDigits(char* str) {
    int length = strlen(str);
    int i = 0, j = 0;

    while (i < length) {
        if (isdigit(str[i])) {
 
            ++i;
        } else {
      
            str[j] = str[i];
            ++i;
            ++j;
        }
    }

    str[j] = '\0';
}

int main() {
  
    const int maxSize = 100;
    char inputString[maxSize];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    deleteDigits(inputString);

    std::cout << "String without digits: " << inputString << std::endl;

    return 0;
}
//6
#include <iostream>
#include <cstring> 

void replaceSubstring(char* str, const char* oldSubstr, const char* newSubstr) {
    int oldLen = strlen(oldSubstr);
    int newLen = strlen(newSubstr);
    int strLen = strlen(str);

    char* buffer = new char[strLen + 1]; 
    buffer[0] = '\0';

    for (int i = 0; i <= strLen - oldLen; ) {
        if (strncmp(str + i, oldSubstr, oldLen) == 0) {
            strcat(buffer, newSubstr);
            i += oldLen;
        } else {
            strncat(buffer, str + i, 1);
            ++i;
        }
    }

    strcat(buffer, str + (strLen - oldLen));

    strcpy(str, buffer);

    delete[] buffer;
}

int main() {
  
    const int maxSize = 1000;
    char inputString[maxSize];
    char oldSubstring[maxSize];
    char newSubstring[maxSize];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    std::cout << "Enter the old substring: ";
    std::cin.getline(oldSubstring, maxSize);

    std::cout << "Enter the new substring: ";
    std::cin.getline(newSubstring, maxSize);

    replaceSubstring(inputString, oldSubstring, newSubstring);

    std::cout << "Modified string: " << inputString << std::endl;

    return 0;
}
//7
#include <iostream>

int countEqualChars(const char* str1, const char* str2) {
    int count = 0;

    while (*str1 != '\0' && *str2 != '\0') {
        
        if (*str1 == *str2) {
            count++;
        }

        str1++;
        str2++;
    }

    return count;
}

int main() {
   
    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    std::cout << "Enter the first string: ";
    std::cin.getline(str1, MAX_LENGTH);

    std::cout << "Enter the second string: ";
    std::cin.getline(str2, MAX_LENGTH);

    int equalCount = countEqualChars(str1, str2);

    std::cout << "Number of equal characters: " << equalCount << std::endl;

    return 0;
}

//8
#include <iostream>

int countDistinctCharacters(const char* str1, const char* str2) {
    int count = 0;
    bool characters[256] = {false}; 

    for (int i = 0; str1[i] != '\0'; ++i) {
        if (!characters[static_cast<unsigned char>(str1[i])]) {
            characters[static_cast<unsigned char>(str1[i])] = true;
            ++count;
        }
    }

    for (int i = 0; str2[i] != '\0'; ++i) {
        if (!characters[static_cast<unsigned char>(str2[i])]) {
            characters[static_cast<unsigned char>(str2[i])] = true;
            ++count;
        }
    }

    return count;
}

int main() {
    const int maxStringLength = 100;
    char str1[maxStringLength];
    char str2[maxStringLength];

    std::cout << "Enter the first string: ";
    std::cin.getline(str1, maxStringLength);

    std::cout << "Enter the second string: ";
    std::cin.getline(str2, maxStringLength);

    int distinctCount = countDistinctCharacters(str1, str2);
    std::cout << "Number of distinct characters: " << distinctCount << std::endl;

    return 0;
}
//9
#include <iostream>
#include <cmath>

void separateGroups(int weights[], int n, int group1[], int group2[]) {

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (weights[i] < weights[j]) {
                


                int temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        if (sum1 <= sum2) {
            group1[i] = weights[i];
            sum1 += weights[i];
        } else {
            group2[i] = weights[i];
            sum2 += weights[i];
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of weights: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Number of weights should be greater than 0.\n";
        return 1; 
    }

    int *weights = new int[n];
    int *group1 = new int[n](); 
    int *group2 = new int[n](); 

    std::cout << "Enter the weights, separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    separateGroups(weights, n, group1, group2);

    std::cout << "Separated Groups:\n";
    std::cout << "Group 1: ";
    for (int i = 0; i < n; ++i) {
        if (group1[i] != 0) {
            std::cout << group1[i] << " ";
        }
    }
    std::cout << "\nGroup 2: ";
    for (int i = 0; i < n; ++i) {
        if (group2[i] != 0) {
            std::cout << group2[i] << " ";
        }
    }

    delete[] weights;
    delete[] group1;
    delete[] group2;

    return 0;
}
//10
#include <iostream>

void fillArray(float** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = 3.33 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (333.33 - 3.33)));
        }
    }
}

void printArray(float** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void evenOrderMaxProduct(float** arr, int rows, int cols) {
    float maxProduct = 0;
    int rowIndex = 0;

    for (int j = 0; j < cols; ++j) {
        float product = 1;
        for (int i = 1; i < rows; i += 2) {
            product *= arr[i][j];
        }

        if (product > maxProduct) {
            maxProduct = product;
            rowIndex = j;
        }
    }

    std::cout << "Max product in even order at column " << rowIndex << ": " << maxProduct << std::endl;
}

void diffBetweenMatrices(float** arr1, float** arr2, float** result, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

void zeroBelowSecondaryDiagonal(float** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i > j) {
                arr[i][j] = 0;
            }
        }
    }
}

void populateUnitMatrix(float** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void multiplyMatrices(float** arr1, float** arr2, float** result, int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    std::cout << "Enter the number of rows for array A: ";
    std::cin >> rowsA;
    std::cout << "Enter the number of columns for array A: ";
    std::cin >> colsA;

    float** arrayA = new float*[rowsA];
    for (int i = 0; i < rowsA; ++i) {
        arrayA[i] = new float[colsA];
    }

    std::cout << "Enter values for array A:" << std::endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            std::cout << "Enter value for position (" << i << ", " << j << "): ";
            std::cin >> arrayA[i][j];
        }
    }

    std::cout << "Enter the number of rows for array B: ";
    std::cin >> rowsB;
    std::cout << "Enter the number of columns for array B: ";
    std::cin >> colsB;

    float** arrayB = new float*[rowsB];
    for (int i = 0; i < rowsB; ++i) {
        arrayB[i] = new float[colsB];
    }

    std::cout << "Enter values for array B:" << std::endl;
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            std::cout << "Enter value for position (" << i << ", " << j << "): ";
            std::cin >> arrayB[i][j];
        }
    }

    if (colsA != rowsB) {
        std::cerr << "Matrix multiplication not possible. Number of columns in A must be equal to the number of rows in B." << std::endl;
        return 1;
    }

    float** result = new float*[rowsA];
    for (int i = 0; i < rowsA; ++i) {
        result[i] = new float[colsB];
    }

    std::cout << "Array A:" << std::endl;
    printArray(arrayA, rowsA, colsA);
    std::cout << std::endl;

    std::cout << "Array B:" << std::endl;
    printArray(arrayB, rowsB, colsB);
    std::cout << std::endl;

    evenOrderMaxProduct(arrayA, rowsA, colsA);

    diffBetweenMatrices(arrayA, arrayB, result, rowsA, colsA);
    std::cout << "Result of subtraction of arrays A and B:" << std::endl;
    printArray(result, rowsA, colsA);
    std::cout << std::endl;

    zeroBelowSecondaryDiagonal(arrayA, rowsA, colsA);
    std::cout << "Array A with elements below the secondary diagonal replaced by 0:" << std::endl;
    printArray(arrayA, rowsA, colsA);
    std::cout << std::endl;

    populateUnitMatrix(arrayB, rowsB, colsB);
    std::cout << "Unit matrix B:" << std::endl;
    printArray(arrayB, rowsB, colsB);
    std::cout << std::endl;

    multiplyMatrices(arrayA, arrayB, result, rowsA, colsA, rowsB, colsB);
    std::cout << "Result of multiplication of array A by unit matrix B:" << std::endl;
    printArray(result, rowsA, colsB);

    for (int i = 0; i < rowsA; ++i) {
        delete[] arrayA[i];
    }
    delete[] arrayA;

    for (int i = 0; i < rowsB; ++i) {
        delete[] arrayB[i];
    }
    delete[] arrayB;

    for (int i = 0; i < rowsA; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
