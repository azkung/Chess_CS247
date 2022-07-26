#ifndef LEVEL3BOT_H_
#define LEVEL3BOT_H_

#include "bot.h"

class Level3Bot : public Bot {
        float evaluate(Board *board);
    public:
        Level3Bot(char color);
        Move getMove(Board *board);
};


#endif // LEVEL3BOT_H_
