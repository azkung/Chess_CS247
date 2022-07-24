#include <string>
#include "piece.h"

using namespace std;

Piece::Piece(char color) : color{color}, movesMade{0} {
    name += color;
}

void Piece::appendName(char c) {
    name += c;
}

string Piece::getName() {
    return name;
}