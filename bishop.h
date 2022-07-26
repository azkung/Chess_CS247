#ifndef BISHOP_H_
#define BISHOP_H_

#include "piece.h"
#include "board.h"
#include "move.h"
#include <vector>

class Bishop : public Piece{
    public:
        Bishop(char color);
        std::vector<Move> findMoves(int row, int col, Board *board) override;
};

#endif // BISHOP_H_
