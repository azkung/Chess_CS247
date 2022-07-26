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

    // Generate a random row and column
    row = rand() % 8;
    col = rand() % 8;

    while(true) {
        if(board->getPiece(row, col) != nullptr){
            if(board->getPiece(row, col)->getColor() == color){
                vector<Move> moves = board->findMoves(row, col, color);
                
                if(moves.size() > 0){
                    int chooseMove = rand() % moves.size();
                    return moves[chooseMove];
                    break;
                }
            }
        }
        row = rand() % 8;
        col = rand() % 8;
    }

}