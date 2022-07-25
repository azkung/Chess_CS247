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
        bool makeMove();
        void drawScreen();

};


#endif // GAME_H_