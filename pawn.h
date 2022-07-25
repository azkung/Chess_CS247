#ifndef PAWN_H_
#define PAWN_H_

#include "piece.h"
#include "board.h"
#include "move.h"
#include <vector>
#include <string>


class Pawn : public Piece{
    public:
        Pawn(char color);

        std::vector<Move> findMoves(int row, int col, Board *board) override;
};

#endif // PAWN_H_