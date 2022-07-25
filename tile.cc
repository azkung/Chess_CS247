#include "tile.h"
#include "piece.h"
#include <string>

using namespace std;


Tile::Tile(int row, int col, Piece *piece) : row(row), col(col), piece(piece) {}

const int Tile::getRow() {
    return row;
}

const int Tile::getCol() {
    return col;
}

Piece* Tile::getPiece() {
    return piece;
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

vector<Move> Tile::findMoves(Board *board) {
    vector<Move> moves;
    if(piece == nullptr) {
        return moves;
    }
    return piece->findMoves(row, col, board);
}