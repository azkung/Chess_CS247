#include "move.h"
#include "board.h"
#include "human.h"

using namespace std;

Human::Human(char color) : Player(color), score(0) {};

void Human::addWin() {
    score++;
}

int Human::getScore() {
    return score;
}

Move Human::getMove(Board *board) {

}