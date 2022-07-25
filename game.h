#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "board.h"

class Game{
        Board* board;
        TextObserver *textScreen;
    public:
        Game();
        ~Game();
        bool makeMove();
};


#endif // GAME_H_