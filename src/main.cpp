#include <iostream>
#include <ctime>
#include"minesweeper.h"

int main()
{
    srand(time(0));
    cout << "Seed: " << time(0) << endl;
    int row;
    int col;
    int revealedCells = 0;
    vector<vector<char>> board = CreateBoard();
    PlaceMines(board);
    vector<vector<int>> mineCount = CalculateAdjacentMines(board);
    vector<vector<char>> visibleBoard(ROWS, vector<char>(COLS,'#'));
    while(true)
    {
        system("cls");
        DisplayBoard(visibleBoard);
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter col: ";
        cin >> col;
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS)
        {
            cout << "Invalid input. Please enter a row and column between 0 and 8." << endl;
            continue;
        }
        if(board[row][col] == '*')
        {
            cout << "BOOOOM! You are dead!" << endl;
            break;
        }
        else
        {
            if(visibleBoard[row][col] == '#')
            {
                 if(mineCount[row][col] == 0)
                 {
                    RevealZeros(visibleBoard, mineCount, row, col, revealedCells);
                 }
                 else
                 {
                   visibleBoard[row][col] = '0' + mineCount[row][col];
                   revealedCells++;
                 }
                 if(revealedCells == (ROWS * COLS) - MINES)
                 {
                   cout << "HOORAY!! YOU WON!" << endl;
                   break;
                 }
            }
           
        }
    }
    return 0;
}