#ifndef LEVEL4BOT_H_
#define LEVEL4BOT_H_

#include "bot.h"

class Level4Bot : public Bot {
    public:
        Level4Bot(char color);
        Move getMove(Board *board);
};


#endif // LEVEL4BOT_H_