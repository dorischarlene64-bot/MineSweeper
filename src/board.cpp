#include<iostream>

#include"minesweeper.h"

using namespace std;


vector<vector<char>> CreateBoard()
{
    vector<vector<char>> board(ROWS, vector<char>(COLS,'.'));
    return board;
}

void DisplayBoard(const vector<vector<char>> & board)
{
    cout << "   ";
    for(int i = 0; i < COLS; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "   -----------------" << endl;
    for(int row = 0; row < ROWS; row++)
    {
        cout << row << " ";
        cout << "|";
        for(int col = 0; col < COLS; col++)
        {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

void RevealZeros(vector<vector<char>> & visibleBoard, const vector<vector<int>> & mineCount, int startRow, int startCol, int & revealedCells)
{
    queue<pair<int, int>> q;
    q.push({startRow, startCol});

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(visibleBoard[row][col] == '#')
        {
            visibleBoard[row][col] = '0' + mineCount[row][col];
            revealedCells++;
        }
        for(int di = -1; di <= 1; di++)
        {
            for(int dj = -1; dj <= 1; dj++)
            {
                int newRow = row + di;
                int newCol = col + dj;

                if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS)
                {
                    if(visibleBoard[newRow][newCol] == '#')
                    {
                       
                        visibleBoard[newRow][newCol] = '0' + mineCount[newRow][newCol];
                        revealedCells++;
                        if(mineCount[newRow][newCol] == 0)
                        {
                             q.push({newRow, newCol});
                        }
                    }
                }

            }
        }
    }
}