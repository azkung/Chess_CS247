#include "move.h"

Move::Move(int row, int col, int prevRow, int prevCol, bool isCastle, bool isEnPassant){
    this->row = row;
    this->col = col;
    this->prevRow = prevRow;
    this->prevCol = prevCol;
    this->isCastle = isCastle;
    this->isEnPassant = isEnPassant;
}