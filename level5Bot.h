#ifndef LEVEL5BOT_H_
#define LEVEL5BOT_H_

#include <iostream>
#include <utility>
#include "bot.h"
#include "player.h"
#include "move.h"
#include "board.h"


class Level5Bot : public Bot {
    
        std::pair<float, Move> minimax(Board *board, char color, int depth, float alpha, float beta);
        float evaluate(Board *board);
        int movesMade;
    public:
        Level5Bot(char color);
        Move getMove(Board *board);
};


#endif // LEVEL5BOT_H_