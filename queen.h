#ifndef QUEEEN_H_
#define QUEEEN_H_

#include "piece.h"
#include "board.h"
#include "move.h"
#include <vector>


class Queen : public Piece{
    public:
        Queen(char color);
        std::vector<Move> findMoves(int row, int col, Board *board) override;
};

#endif // QUEEEN_H_