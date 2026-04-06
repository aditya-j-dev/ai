#include <bits/stdc++.h>
using namespace std;

#define N 9

// Print Sudoku board
void printBoard(vector<vector<int>>& board) {
    cout << "\nCurrent Sudoku Board:\n";
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0)
            cout << "---------------------\n";
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0)
                cout << "| ";
            if (board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if placing num is valid
bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku(board))
                            return true;

                        board[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Check if board is full
bool isComplete(vector<vector<int>>& board) {
    for (auto& row : board)
        for (auto& cell : row)
            if (cell == 0)
                return false;
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    int choice;

    while (true) {
        printBoard(board);

        cout << "\nOptions:\n";
        cout << "1. Enter a number\n";
        cout << "2. Solve Sudoku\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int r, c, num;
            cout << "Enter row (1-9), column (1-9), number (1-9): ";
            cin >> r >> c >> num;

            r--; c--;

            if (r < 0 || r >= 9 || c < 0 || c >= 9 || num < 1 || num > 9) {
                cout << "Invalid input!\n";
                continue;
            }

            if (board[r][c] != 0) {
                cout << "Cell already filled!\n";
                continue;
            }

            if (isSafe(board, r, c, num)) {
                board[r][c] = num;
            } else {
                cout << "Invalid move!\n";
            }

            if (isComplete(board)) {
                cout << "\n🎉 Congratulations! Sudoku Completed!\n";
                printBoard(board);
                break;
            }

        } else if (choice == 2) {
            if (solveSudoku(board)) {
                cout << "\nSolved Sudoku:\n";
                printBoard(board);
            } else {
                cout << "No solution exists!\n";
            }
            break;

        } else if (choice == 3) {
            break;

        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}