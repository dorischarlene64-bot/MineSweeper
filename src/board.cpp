#include<iostream>

#include"minesweeper.h"

using namespace std;


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