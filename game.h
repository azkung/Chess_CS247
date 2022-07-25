#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "board.h"

class Game{
        Board* board;
    public:
        Game();
        ~Game();
        void makeMove();
};


#endif // GAME_H_