#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "piece.h"
#include "board.h"
#include "move.h"

class Knight : public Piece{
    public:
        Knight(char color);
        std::vector<Move> findMoves(int row, int col, Board *board) override;
};

#endif // KNIGHT_H_
