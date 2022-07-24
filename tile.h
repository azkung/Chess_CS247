#ifndef TILE_H_
#define TILE_H_
#include <iostream>
#include <string>
#include "subject.h"
#include "piece.h"

class Tile : public Subject{
        Piece *piece;
        int x;
        int y;
    public:
        Tile(int x, int y, Piece *piece);
        ~Tile();
        std::string getState();
};

#endif // TILE_H_