#ifndef QUEEEN_H_
#define QUEEEN_H_

#include "piece.h"

class Queen : public Piece{
    public:
        Queen(char color, int row, int col);
};

#endif // QUEEEN_H_