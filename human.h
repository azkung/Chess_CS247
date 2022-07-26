#ifndef HUMAN_H_
#define HUMAN_H_

#include "move.h"
#include "board.h"
#include "player.h"

class Human : public Player {
    int score;
    public:
        Human(char color);
        
        Move getMove(Board *board);
};

#endif // HUMAN_H_