#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int ROWS = 9;
const int COLS = 9;
const int MINES = 10;

vector<vector<char>> CreateBoard();

void DisplayBoard(const vector<vector<char>> & board);

void PlaceMines(vector<vector<char>> & board);

vector<vector<int>> CalculateAdjacentMines(const vector<vector<char>> & board);

void RevealZeros(vector<vector<char>>& visibleBoard,
                 const vector<vector<int>>& mineCount,
                 int startRow,
                 int startCol,
                 int& revealedCells);