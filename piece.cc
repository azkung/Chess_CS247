#include <string>
#include "piece.h"

using namespace std;

Piece::Piece(char color) : color{color}, movesMade{0}, lastMoved{-1} {
    name += color;
}

void Piece::appendName(char c) {
    name += c;
}

const string Piece::getName() {
    return name;
}

const int Piece::getMovesMade() {
    return movesMade;
}

const int Piece::getLastMoved() {
    return lastMoved;
}

const char Piece::getColor() {
    return color;
}

void Piece::setLastMoved(int lastMoved) {
    this->lastMoved = lastMoved;
}

Piece::Piece(const Piece &other) : color{other.color}, movesMade{other.movesMade}, lastMoved{other.lastMoved}, name{other.name} {}

Piece::~Piece() {}