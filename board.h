#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include "textObserver.h"
#include "move.h"
#include "piece.h"

class Piece;
class Move;

class Board{
    std::vector<std::vector<Tile*>> tiles;
    int moveCounter;
    std::vector<Move> movesMade;


    public:
        Board(TextObserver *textScreen);
        Board(const Board &other, TextObserver *textScreen);
        ~Board();
        std::vector<Move> findMoves(int row, int col);
        void killRestrict(std::vector<Move> &moves, char playerTurn);
        bool inCheck(char playerTurn);
        bool inCheckmate(char playerTurn);
        Piece* getPiece(int row, int col);
        int getMoveCounter();
        bool move(int row, int col, int newRow, int newCol);

        char getTurn();

};

#endif // BOARD_H_