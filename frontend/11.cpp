#include <bits/stdc++.h>
using namespace std;

class Puzzle {
private:
    vector<vector<int>> board;
    int emptyRow, emptyCol;
    int moves; // 🔹 move counter

public:
    Puzzle() {
        board = {
            {1, 2, 3},
            {4, 0, 6},
            {7, 5, 8}
        };

        moves = 0; // initialize moves

        // find empty space
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == 0) {
                    emptyRow = i;
                    emptyCol = j;
                }
    }

    void printBoard() {
        cout << "\n";
        for (auto &row : board) {
            for (auto &cell : row) {
                if (cell == 0) cout << "_ ";
                else cout << cell << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    bool isSolved() {
        vector<vector<int>> goal = {
            {1,2,3},
            {4,5,6},
            {7,8,0}
        };
        return board == goal;
    }

    bool moveUp() {
        if (emptyRow == 0) return false;
        swap(board[emptyRow][emptyCol], board[emptyRow - 1][emptyCol]);
        emptyRow--;
        return true;
    }

    bool moveDown() {
        if (emptyRow == 2) return false;
        swap(board[emptyRow][emptyCol], board[emptyRow + 1][emptyCol]);
        emptyRow++;
        return true;
    }

    bool moveLeft() {
        if (emptyCol == 0) return false;
        swap(board[emptyRow][emptyCol], board[emptyRow][emptyCol - 1]);
        emptyCol--;
        return true;
    }

    bool moveRight() {
        if (emptyCol == 2) return false;
        swap(board[emptyRow][emptyCol], board[emptyRow][emptyCol + 1]);
        emptyCol++;
        return true;
    }

    void play() {
        char move;

        while (true) {
            printBoard();

            if (isSolved()) {
                cout << "🎉 Puzzle Solved!\n";
                cout << "Total Moves Taken: " << moves << endl; // 🔹 print moves
                break;
            }

            cout << "Move (W=Up, S=Down, A=Left, D=Right, Q=Quit): ";
            cin >> move;

            bool valid = true;

            switch (toupper(move)) {
                case 'W': valid = moveUp(); break;
                case 'S': valid = moveDown(); break;
                case 'A': valid = moveLeft(); break;
                case 'D': valid = moveRight(); break;
                case 'Q': return;
                default:
                    cout << "Invalid input!\n";
                    continue;
            }

            if (!valid) {
                cout << "❌ Invalid move!\n";
            } else {
                moves++; // 🔹 increment only if move is valid
            }
        }
    }
};

int main() {
    Puzzle game;
    game.play();
    return 0;
}