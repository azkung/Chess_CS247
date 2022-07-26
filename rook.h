#ifndef ROOK_H_
#define ROOK_H_
#include "piece.h"
#include "board.h"
#include "move.h"
#include <vector>


class Rook : public Piece{
    public:
        Rook(char color);
        std::vector<Move> findMoves(int row, int col, Board *board) override;
};


#endif // ROOK_H_
