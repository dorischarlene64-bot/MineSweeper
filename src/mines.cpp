#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 10;
const int COLS = 10;
const int MINES = 15;

// Places mines randomly on the board
void placeMines(vector<vector<char>>& board)
{
    int minesPlaced = 0;

    while (minesPlaced < MINES)
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        if (board[row][col] != '*')
        {
            board[row][col] = '*';
            minesPlaced++;
        }
    }
}

// Counts mines around each cell
vector<vector<int>> calculateAdjacentMines(
    const vector<vector<char>>& board)
{
    vector<vector<int>> mineCount(
        ROWS, vector<int>(COLS, 0));

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == '*')
                continue;

            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    int newRow = row + dr;
                    int newCol = col + dc;

                    if (newRow >= 0 && newRow < ROWS &&
                        newCol >= 0 && newCol < COLS &&
                        board[newRow][newCol] == '*')
                    {
                        mineCount[row][col]++;
                    }
                }
            }
        }
    }

    return mineCount;
}