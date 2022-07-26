#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "board.h"
#include "sdl_wrap.h"
#include "player.h"

class Game{
        Board* board;
        TextObserver *textScreen;
        Screen s{600,600};
    public:
        Game();
        ~Game();
        bool makeMove();
        void drawScreen();
        bool getWinner();
        bool gameEnded();

        char currTurn();

        Player* player1;
        Player* player2;

};


#endif // GAME_H_