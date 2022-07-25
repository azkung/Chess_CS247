#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include "textObserver.h"
#include "move.h"

class Board{
    std::vector<std::vector<Tile*>> tiles;
    int moveCounter;

    public:
        Board(TextObserver *textScreen);
        ~Board();
        std::vector<Move> findMoves(int row, int col);

};

#endif // BOARD_H_