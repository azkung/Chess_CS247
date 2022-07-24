#ifndef PAWN_H_
#define PAWN_H_

#include "piece.h"

class Pawn : public Piece{
    public:
        Pawn(char color, int row, int col);
};

#endif // PAWN_H_