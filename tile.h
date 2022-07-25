#ifndef TILE_H_
#define TILE_H_
#include <iostream>
#include <string>
#include "subject.h"
#include "piece.h"

class Board;
class Piece;

class Tile : public Subject{
        Piece *piece;
        int row;
        int col;
        void setPiece(Piece *p);
        void initPiece(Piece *p);
    public:
        Tile(int row, int col, Piece *p);
        ~Tile();
        std::string getState();
        const int getRow();
        const int getCol();
        Piece* getPiece();

        void notifyObservers();

        friend Board;
};

#endif // TILE_H_