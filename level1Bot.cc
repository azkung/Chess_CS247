#include "level1Bot.h"
#include "move.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <vector>

using namespace std;

Level1Bot::Level1Bot(char color) : Bot(color) {}

Move Level1Bot::getMove(Board *board) {
    int row, col;
    srand (time(NULL));

    vector<Move> allMoves = board->getAllMoves(color);
    int randomChoice = rand() % allMoves.size();
    return allMoves[randomChoice];
}