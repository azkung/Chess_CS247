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

        void initPlayers(char p1, char p2);

        void setPiece(int row, int col, string piece);
        void removePiece(int x, int y);
        void setTurn(char turn);

        bool makeMove();
        void drawScreen();
        bool getWinner();
        bool gameEnded();

        bool boardIsValid();

        char currTurn();

        Player* player1;
        Player* player2;

};


#endif // GAME_H_