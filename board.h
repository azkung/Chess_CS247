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
class TextObserver;

class Board{
    std::vector<std::vector<Tile*>> tiles;
    int moveCounter;
    int turnModifier;
    std::vector<Move> movesMade;


    public:
        Board(TextObserver *textScreen);
        Board(const Board &other, TextObserver *textScreen);
        ~Board();
        std::vector<Move> findMoves(int row, int col, char playerTurn);
        void killRestrict(std::vector<Move> &moves, char playerTurn);
        bool inCheck(char playerTurn);
        bool inCheckmate(char playerTurn);
        bool inStalemate(char playerTurn);
        Piece* getPiece(int row, int col);
        int getMoveCounter();
        std::vector<Move> getAllMoves(char color);
        bool move(int row, int col, int newRow, int newCol);

        void setPiece(int row, int col, Piece *piece);
        void removePiece(int row, int col);
        void setTurn(char turn);

        bool isValid();

        char getTurn();

};

#endif // BOARD_H_
