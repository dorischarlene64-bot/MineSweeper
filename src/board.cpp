#include<iostream>
#include<vector>

#include"minesweeper.h"

using namespace std;

const int ROWS = 9;
const int COLS = 9;

vector<vector<char>> CreateBoard()
{
    vector<vector<char>> board(ROWS, vector<char>(COLS,'.'));
    return board;
};

void DisplayBoard(const vector<vector<char>> & board)
{
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    vector<vector<char>> board = CreateBoard();
    DisplayBoard(board);
    return 0;
}