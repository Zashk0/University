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
