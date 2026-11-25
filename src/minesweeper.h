#include<vector>

using namespace std;

const int ROWS = 9;
const int COLS = 9;
const int MINES = 15;

vector<vector<char>> CreateBoard();

void DisplayBoard(const vector<vector<char>> & board);

void PlaceMines(vector<vector<char>> & board);

vector<vector<int>> CalculateAdjacentMines(const vector<vector<char>> & board);