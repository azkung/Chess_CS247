#ifndef PLAYER_H_
#define PLAYER_H_

#include "move.h"
#include "board.h"

class Player {
    protected:
        char color;
    public:
        Player(char color);
        virtual ~Player();

        virtual Move getMove(Board *board)=0;
};

#endif // PLAYER_H_
