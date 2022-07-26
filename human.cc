#include "move.h"
#include "board.h"
#include "human.h"

using namespace std;

Human::Human(char color) : Player(color), score(0) {};

Move Human::getMove(Board *board) {
    char col1, col2, row1, row2;
    cin >> col1 >> row1 >> col2 >> row2;
    int col1Int = col1 - 'a';
    int col2Int = col2 - 'a';
    int row1Int = 7 - (row1 - '1');
    int row2Int = 7 - (row2 - '1');
    cout << endl;
    return Move(row2Int, col2Int, row1Int, col1Int, false, false);
}