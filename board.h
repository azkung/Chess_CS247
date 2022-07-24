#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include "textObserver.h"

class Board{
    std::vector<std::vector<Tile*>> tiles;
    TextObserver *textScreen;

    public:
        Board();
        ~Board();
};

#endif // BOARD_H_