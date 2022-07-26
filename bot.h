#ifndef BOT_H_
#define BOT_H_

#include "player.h"
#include "board.h"
#include "move.h"

class Bot : public Player {
    public:
        Bot(char color);
};

#endif // BOT_H_
