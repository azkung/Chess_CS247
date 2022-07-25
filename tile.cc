#include "tile.h"
#include <string>

using namespace std;


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


string Tile::getState() {
    if(piece == nullptr) {
        return "__";
    }
    return piece->getName();
}

void Tile::notifyObservers() {
    for (auto ob : observers) ob->notify(*this);
}

void Tile::setPiece(Piece *p) {
    piece = p;
    notifyObservers();
}

void Tile::initPiece(Piece *p) {
    piece = p;
}