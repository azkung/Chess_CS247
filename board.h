#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include "textObserver.h"
#include "move.h"
#include "piece.h"

class Piece;
class Move;

class Board{
    std::vector<std::vector<Tile*>> tiles;
    int moveCounter;

    public:
        Board(TextObserver *textScreen);
        ~Board();
        std::vector<Move> findMoves(int row, int col);
        Piece* getPiece(int row, int col);
        int getMoveCounter();
        void move(int row, int col, int newRow, int newCol);

};

#endif // BOARD_H_