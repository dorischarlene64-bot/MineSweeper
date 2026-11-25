#include"minesweeper.h"

int main()
{
    vector<vector<char>> board = CreateBoard();
    PlaceMines(board);
    vector<vector<int>> mineCount = CalculateAdjacentMines(board);
    DisplayBoard(board);
    return 0;
}