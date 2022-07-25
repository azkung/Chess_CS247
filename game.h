#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "board.h"
#include "sdl_wrap.h"

class Game{
        Board* board;
        TextObserver *textScreen;
        Screen s{600,600};
    public:
        Game();
        ~Game();
        void makeMove();
        void drawScreen();
        void updateScreen();
};


#endif // GAME_H_