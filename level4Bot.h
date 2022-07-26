#ifndef LEVEL4BOT_H_
#define LEVEL4BOT_H_

#include <iostream>
#include <utility>
#include "bot.h"
#include "player.h"
#include "move.h"
#include "board.h"


class Level4Bot : public Bot {
        std::pair<float, Board> minimax(Board *board, char color, int depth, int alpha, int beta);
        float evaluate(Board *board);
    public:
        Level4Bot(char color);
        Move getMove(Board *board);
};


#endif // LEVEL4BOT_H_