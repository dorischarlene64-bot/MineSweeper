#include <cstdlib>
#include <ctime>

#include "minesweeper.h"

using namespace std;

void PlaceMines(vector<vector<char>> & board)
{
    int minesPlaced = 0;
    while(minesPlaced < MINES)
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(board[row][col] != '*')
        {
            board[row][col] = '*';
            minesPlaced++;
        }
    }
}

vector<vector<int>> CalculateAdjacentMines(const vector<vector<char>> & board)
{
    vector<vector<int>> mineCount(ROWS, vector<int>(COLS, 0));
    for(int Ri = 0; Ri < ROWS; Ri++)
    {
        for(int Cj = 0; Cj < COLS; Cj++)
        {
            if(board[Ri][Cj] == '*')
            {
                continue;
            }
            for(int di = -1; di <= 1; di++)
            {
                for(int dj = -1; dj <= 1; dj++)
                {
                    int newRow = Ri + di;
                    int newCol = Cj + dj;

                    if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && board[newRow][newCol] == '*')
                    {
                        mineCount[Ri][Cj]++;
                    }
                }
            }
        }
    }

    return mineCount;

}