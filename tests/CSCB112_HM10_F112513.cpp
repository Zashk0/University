//1
#include <iostream>

// Function to find the maximum element in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum element in an array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find and print the max/min of a row in a 2D array
void findMaxMinForRow(int matrix[][5], int row, int col, bool findMax) {
    int maxOrMin = findMax ? matrix[row][0] : matrix[row][0];
    
    for (int j = 1; j < col; j++) {
        if (findMax) {
            if (matrix[row][j] > maxOrMin) {
                maxOrMin = matrix[row][j];
            }
        } else {
            if (matrix[row][j] < maxOrMin) {
                maxOrMin = matrix[row][j];
            }
        }
    }
    
    if (findMax) {
        std::cout << "Maximum element in row " << row << ": " << maxOrMin << std::endl;
    } else {
        std::cout << "Minimum element in row " << row << ": " << maxOrMin << std::endl;
    }
}

int main() {
    int numRows, numCols;
    
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> numRows >> numCols;
    
    int matrix[numRows][5];
    
    // Input matrix elements
    for (int i = 0; i < numRows; i++) {
        std::cout << "Enter elements for row " << i << ": ";
        for (int j = 0; j < numCols; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    // Find and print max/min for each row based on whether it's even or odd
    for (int i = 0; i < numRows; i++) {
        if (i % 2 == 0) {
            findMaxMinForRow(matrix, i, numCols, true); // Even row, find max
        } else {
            findMaxMinForRow(matrix, i, numCols, false); // Odd row, find min
        }
    }
    
    return 0;
}
//2
#include <iostream>

using namespace std;

// Function to replace positive elements in an array with user-supplied values
void replacePositiveElements(int arr[], int size, int replaceValue) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            arr[i] = replaceValue;
        }
    }
}

// Function to calculate the weighted sum based on array values
int calculateWeightedSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i] * (i + 1); // Multiply each value by its position (1-based index)
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int replaceValue;
    cout << "Enter the value to replace positive elements with: ";
    cin >> replaceValue;

    replacePositiveElements(arr, size, replaceValue);

    int result = calculateWeightedSum(arr, size);
    cout << "Result of the weighted sum: " << result << endl;

    return 0;
}
//3
#include <iostream>
#include <algorithm>

// Predicate function for ascending order
bool AscendingOrder(int a, int b) {
    return a < b;
}

// Predicate function for descending order
bool DescendingOrder(int a, int b) {
    return a > b;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    int* arr = new int[n];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int choice;
    std::cout << "Enter 1 for ascending order or 2 for descending order: ";
    std::cin >> choice;

    // Sort the array based on the user's choice
    if (choice == 1) {
        std::sort(arr, arr + n, AscendingOrder);
        std::cout << "Sorted in ascending order: ";
    } else if (choice == 2) {
        std::sort(arr, arr + n, DescendingOrder);
        std::cout << "Sorted in descending order: ";
    } else {
        std::cout << "Invalid choice. Exiting program." << std::endl;
        delete[] arr;
        return 1;
    }

    // Display the sorted array
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    delete[] arr;

    return 0;
}
//4
#include <iostream>

// Recursive function to copy a C-style string
void copyStringRecursive(const char* src, char* dest, int index = 0) {
    // Base case: If we reach the end of the source string, terminate the destination string
    if (src[index] == '\0') {
        dest[index] = '\0';
        return;
    }

    // Copy the current character from source to destination
    dest[index] = src[index];

    // Recursively copy the rest of the string
    copyStringRecursive(src, dest, index + 1);
}

int main() {
    char inputString[100];
    char copiedString[100];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, sizeof(inputString));

    // Call the recursive function to copy the string
    copyStringRecursive(inputString, copiedString);

    std::cout << "Original string: " << inputString << std::endl;
    std::cout << "Copied string: " << copiedString << std::endl;

    return 0;
}
//5
#include <iostream>

// Recursive function to lexicographically compare two natural numbers
int compareNumbers(const char* num1, const char* num2) {
    // Base case 1: If both numbers have the same length and all digits are the same, return 0 (equal).
    if (*num1 == '\0' && *num2 == '\0') {
        return 0;
    }
    
    // Base case 2: If num1 is shorter, it's lexicographically smaller.
    if (*num1 == '\0') {
        return -1;
    }
    
    // Base case 3: If num2 is shorter, it's lexicographically smaller.
    if (*num2 == '\0') {
        return 1;
    }
    
    // Compare the current digits
    if (*num1 < *num2) {
        return -1;
    } else if (*num1 > *num2) {
        return 1;
    } else {
        // Recursively compare the remaining digits
        return compareNumbers(num1 + 1, num2 + 1);
    }
}

int main() {
    char num1[100], num2[100];
    
    std::cout << "Enter the first natural number: ";
    std::cin >> num1;
    
    std::cout << "Enter the second natural number: ";
    std::cin >> num2;
    
    int result = compareNumbers(num1, num2);
    
    if (result < 0) {
        std::cout << "The first number is lexicographically smaller." << std::endl;
    } else if (result > 0) {
        std::cout << "The second number is lexicographically smaller." << std::endl;
    } else {
        std::cout << "Both numbers are lexicographically equal." << std::endl;
    }
    
    return 0;
}
//6
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
//7
#include <iostream>

// Recursive function to replace all occurrences of 'x' with 'y' in a string.
void replaceChar(char *s, char x, char y) {
    // Base case: if the current character is '\0', end recursion.
    if (*s == '\0') {
        return;
    }

    // If the current character is 'x', replace it with 'y'.
    if (*s == x) {
        *s = y;
    }

    // Recur for the next character in the string.
    replaceChar(s + 1, x, y);
}

int main() {
    char str[100];  // Buffer for the string.
    char x, y;      // Characters for replacement.

    std::cout << "Enter a string (up to 99 characters): ";
    std::cin.getline(str, 100);  // Read the string with spaces.

    std::cout << "Enter the character to replace: ";
    std::cin >> x;

    std::cin.ignore();  // Ignore the newline character in the buffer.

    std::cout << "Enter the character to replace with: ";
    std::cin >> y;

    std::cout << "Original String: " << str << std::endl;

    replaceChar(str, x, y);  // Call the recursive function.

    std::cout << "Modified String: " << str << std::endl;

    return 0;
}
//8
#include <iostream>
#include <vector>

int m, n, S;
std::vector<std::vector<int>> grid;
std::vector<std::vector<bool>> visited;

bool isSafe(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]);
}

bool DFS(int x, int y, int sum) {
    if (sum > S) return false;  // Prune if sum exceeds S
    if (sum == S) return true;  // Check if sum equals S

    visited[x][y] = true;  // Mark the current cell as visited

    // 8 possible directions
    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int dir = 0; dir < 8; dir++) {
        int newX = x + dx[dir], newY = y + dy[dir];
        if (isSafe(newX, newY) && DFS(newX, newY, sum + grid[newX][newY]))
            return true;
    }

    visited[x][y] = false;  // Backtrack
    return false;
}

bool findRegionWithSumS() {
    visited.assign(m, std::vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (DFS(i, j, grid[i][j])) return true;
        }
    }
    return false;
}

int main() {
    std::cout << "Enter the dimensions of the grid (m and n): ";
    std::cin >> m >> n;

    grid.assign(m, std::vector<int>(n));
    std::cout << "Enter the elements of the grid:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::cout << "Enter the sum S: ";
    std::cin >> S;

    if (findRegionWithSumS()) {
        std::cout << "Yes, there is a region with sum " << S << std::endl;
    } else {
        std::cout << "No, there is no such region with sum " << S << std::endl;
    }

    return 0;
}
//9
#include <iostream>
#include <cmath>

using namespace std;

const int BOARD_MAX_ROWS = 20;
const int BOARD_MAX_COLS = 20;

int numRows, numCols;

bool isMoveValid(int currentRow, int currentCol, int previousRow, int previousCol)
{
    int rowDifference = abs(currentRow - previousRow);
    int colDifference = abs(currentCol - previousCol);
    return (rowDifference == 2 && colDifference == 1) || (rowDifference == 1 && colDifference == 2);
}

bool followTextPath(char chessBoard[BOARD_MAX_ROWS][BOARD_MAX_COLS], const string &path, int currentRow, int currentCol)
{
    int pathLength = path.length();

    for (int i = 0; i < pathLength; ++i)
    {
        char targetChar = path[i];
        bool isFound = false;

        for (int deltaRow = -2; deltaRow <= 2 && !isFound; ++deltaRow)
        {
            for (int deltaCol = -2; deltaCol <= 2 && !isFound; ++deltaCol)
            {
                int newRow = currentRow + deltaRow;
                int newCol = currentCol + deltaCol;

                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && isMoveValid(newRow, newCol, currentRow, currentCol))
                {
                    if (chessBoard[newRow][newCol] == targetChar)
                    {
                        currentRow = newRow;
                        currentCol = newCol;
                        isFound = true;
                    }
                }
            }
        }

        if (!isFound)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    if (numRows <= 0 || numRows > BOARD_MAX_ROWS || numCols <= 0 || numCols > BOARD_MAX_COLS)
    {
        cerr << "Invalid dimensions. Exiting program.\n";
        return 1;
    }

    char chessBoard[BOARD_MAX_ROWS][BOARD_MAX_COLS];
    cout << "Enter the chessboard (one character per cell):\n";
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            cin >> chessBoard[row][col];
        }
    }

    int startRow, startCol;
    cout << "Enter the starting position (row column): ";
    cin >> startRow >> startCol;

    string path;
    cout << "Enter the path to be followed: ";
    cin >> path;

    bool canFollowPath = followTextPath(chessBoard, path, startRow, startCol);

    if (canFollowPath)
    {
        cout << "The path can be followed starting from the given position.\n";
    }
    else
    {
        cout << "The path cannot be followed starting from the given position.\n";
    }

    return 0;
}

//10
#include <iostream>
#include <cstring>

using namespace std;

char* deleteFirst(char* pch, const char* findWhat) {
    int len = strlen(findWhat);
    char* found = strstr(pch, findWhat);

    if (found) { // if the substring is found
        while (*(found + len)) {
            *found = *(found + len);
            ++found;
        }
        *found = '\0'; // terminate the string
    }

    return pch;
}

int main() {
    char str[100];
    char findWhat[50];

    cout << "Enter the string: ";
    cin.getline(str, 100);

    cout << "Enter the substring to delete: ";
    cin.getline(findWhat, 50);

    char* result = deleteFirst(str, findWhat);
    cout << "Resulting string: " << result << endl;

    return 0;
}
//11
#include <iostream>
#include <cstring>

using namespace std;

char* deleteLast(char* pch, const char* findWhat) {
    int len = strlen(findWhat);
    char* lastFound = nullptr;
    char* currentFound = strstr(pch, findWhat);

    // Find the last occurrence of findWhat
    while (currentFound != nullptr) {
        lastFound = currentFound;
        currentFound = strstr(currentFound + 1, findWhat);
    }

    if (lastFound) { // If the substring is found
        char* endOfString = lastFound + len;
        while (*endOfString) {
            *lastFound++ = *endOfString++;
        }
        *lastFound = '\0'; // Terminate the string
    }

    return pch;
}

int main() {
    char str[100];
    char findWhat[50];

    cout << "Enter the string: ";
    cin.getline(str, 100);

    cout << "Enter the substring to delete: ";
    cin.getline(findWhat, 50);

    char* result = deleteLast(str, findWhat);
    cout << "Resulting string: " << result << endl;

    return 0;
}
//12
#include <iostream>
#include <cstring>

using namespace std;

char* deleteAll(char* pch, const char* findWhat) {
    int lenFindWhat = strlen(findWhat);
    char* result = pch;

    while (*pch != '\0') {
        char* found = strstr(pch, findWhat); // Find occurrence of findWhat

        if (found) {
            // Shift characters to overwrite findWhat
            for (char* src = found + lenFindWhat; (*found = *src); ++found, ++src) {}
        } else {
            // No more occurrences
            break;
        }
    }

    return result;
}

int main() {
    char str[100];
    char findWhat[50];

    cout << "Enter the string: ";
    cin.getline(str, 100);

    cout << "Enter the substring to delete: ";
    cin.getline(findWhat, 50);

    char* result = deleteAll(str, findWhat);
    cout << "Resulting string: " << result << endl;

    return 0;
}
//13
#include <iostream>
#include <cstring>

using namespace std;

char* common(char* s1, char* s2) {
    int length = 0;  // Length of the common prefix
    while (s1[length] && s2[length] && s1[length] == s2[length]) {
        ++length;
    }

    // Temporarily null-terminate s1 at the end of the common prefix
    char originalChar = s1[length];
    s1[length] = '\0';

    // Since we are returning a pointer to the modified s1, store the original character
    char* commonPrefix = s1;

    // Restore the original character in s1
    s1[length] = originalChar;

    return commonPrefix;
}

int main() {
    char s1[100], s2[100];

    cout << "Enter first string: ";
    cin.getline(s1, 100);

    cout << "Enter second string: ";
    cin.getline(s2, 100);

    char* commonStr = common(s1, s2);
    cout << "Common prefix: " << commonStr << endl;

    return 0;
}
//14
#include <iostream>
#include <string>

int countChar(const std::string& s1, const std::string& s2) {
    int count = 0;

    // Iterate over each character of s1
    for (size_t i = 0; i < s1.length(); ++i) {
        // Compare with each character of s2
        for (size_t j = 0; j < s2.length(); ++j) {
            if (s1[i] == s2[j]) {
                count++;
                break; // To avoid counting duplicates in s2
            }
        }
    }

    return count;
}

int main() {
    std::string str1, str2;

    // Get user input for the two strings
    std::cout << "Enter first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter second string: ";
    std::getline(std::cin, str2);
    
    int identicalChars = countChar(str1, str2);
    std::cout << "Number of identical characters: " << identicalChars << std::endl;

    return 0;
}
//15
#include <iostream>
using namespace std;

int longestNonDecreasingSubsequence(int arr[], int n) {
    if (n == 0) return 0;

    int dp[20]; // Since n ≤ 20
    for (int i = 0; i < n; ++i) {
        dp[i] = 1; // Initialize with 1s
    }

    int maxLength = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] <= arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    int n;
    cout << "Enter the number of elements (1 <= n <= 20): ";
    cin >> n;

    int arr[20]; // Array to store the elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int length = longestNonDecreasingSubsequence(arr, n);
    cout << "Length of the longest non-decreasing subsequence is: " << length << endl;

    return 0;
}
//16
#include <iostream>

using namespace std;

bool isIndependentSet(const int* cities, int setSize, int** graph, int n) {
    for (int i = 0; i < setSize; ++i) {
        for (int j = i + 1; j < setSize; ++j) {
            if (graph[cities[i]][cities[j]] == 1) {
                return false;
            }
        }
    }
    return true;
}

void findLargestIndependentSet(int n, int** graph, int*& maxSet, int& maxSetSize) {
    maxSetSize = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int setSize = 0;
        int* subset = new int[n];
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset[setSize++] = i;
            }
        }

        if (isIndependentSet(subset, setSize, graph, n) && setSize > maxSetSize) {
            delete[] maxSet;
            maxSet = subset;
            maxSetSize = setSize;
        } else {
            delete[] subset;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    int** graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n]{0};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << "Is there a road between city " << i << " and city " << j << "? (1 for yes, 0 for no): ";
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    int* maxSet = nullptr;
    int maxSetSize = 0;
    findLargestIndependentSet(n, graph, maxSet, maxSetSize);

    cout << "Largest subset of cities not connected by any road: ";
    for (int i = 0; i < maxSetSize; ++i) {
        cout << maxSet[i] << " ";
    }
    cout << endl;

    // Cleaning up memory
    for (int i = 0; i < n; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] maxSet;

    return 0;
}
