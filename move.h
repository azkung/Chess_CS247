#ifndef MOVE_H_
#define MOVE_H_

#include <iostream>
#include <string>
#include "piece.h"

class Move{
    int row;
    int col;
    int prevRow;
    int prevCol;
    bool isCastle;
    bool isEnPassant;

    public:
        Move(int row, int col, int prevRow, int prevCol, bool isCastle, bool isEnPassant);
        const int getRow();
        const int getCol();
        const int getPrevRow();
        const int getPrevCol();
        const bool getIsCastle();
        const bool getIsEnPassant();
};

#endif // MOVE_H_
