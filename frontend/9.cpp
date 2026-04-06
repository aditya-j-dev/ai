#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void printBoard()
{
    cout << "\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << " " << board[i][j] << " ";
            if(j<2) cout << "|";
        }
        cout << "\n";
        if(i<2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin()
{
    // rows & columns
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return true;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return true;
    }

    // diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return true;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return true;

    return false;
}

bool checkDraw()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main()
{
    int choice;
    char player = 'X';

    while(true)
    {
        printBoard();
        cout << "Player " << player << " enter position (1-9): ";
        cin >> choice;

        int row = (choice-1)/3;
        int col = (choice-1)%3;

        if(board[row][col]=='X' || board[row][col]=='O')
        {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row][col] = player;

        if(checkWin())
        {
            printBoard();
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if(checkDraw())
        {
            printBoard();
            cout << "Match Draw! No winner." << endl;
            break;
        }

        player = (player=='X') ? 'O' : 'X';
    }

    return 0;
}