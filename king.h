#ifndef KING_H_
#define KING_H_

#include "piece.h"
#include "board.h"
#include "move.h"
#include <vector>

class King : public Piece{
    public:
        King(char color);
        std::vector<Move> findMoves(int row, int col, Board *board) override;
};

#endif // KING_H_