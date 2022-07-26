#include "level1Bot.h"
#include "move.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Level1Bot::Level1Bot(char color) : Bot(color) {}

Move Level1Bot::getMove(Board *board) {
    int row, col;
    srand (time(NULL));

    // Generate a random row and column
    row = rand() % 8;
    col = rand() % 8;

    while(board->getPiece(row, col) != nullptr && board->getPiece(row, col)->getColor() == color) {
        row = rand() % 8;
        col = rand() % 8;
    }

}