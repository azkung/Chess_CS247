#include "tile.h"

Tile::Tile(int row, int col, Piece *piece) : row(row), col(col), piece(piece) {}

int Tile::getRow() {
    return row;
}

int Tile::getCol() {
    return col;
}

Tile::~Tile() {
    if(piece != nullptr) {
        delete piece;
    }
}