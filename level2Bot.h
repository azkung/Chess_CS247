#ifndef LEVEL2BOT_H_
#define LEVEL2BOT_H_

#include "bot.h"

class Level2Bot : public Bot {
    public:
        Level2Bot(char color);
        Move getMove(Board *board);
};


#endif // LEVEL2BOT_H_
