#ifndef BISHOP_H_
#define BISHOP_H_

#include "piece.h"

class Bishop : public Piece{
    public:
        Bishop(char color, int row, int col);
};

#endif // BISHOP_H_