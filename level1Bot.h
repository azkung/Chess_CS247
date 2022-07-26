#ifndef LEVEL1BOT_H_
#define LEVEL1BOT_H_

#include "bot.h"

class Level1Bot : public Bot {
    public:
        Level1Bot(char color);
        Move getMove(Board *board);
};


#endif // LEVEL1BOT_H_