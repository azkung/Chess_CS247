#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include "board.h"
#include "level2Bot.h"
#include "move.h"

using namespace std;

Level2Bot::Level2Bot(char color) : Bot(color) {}

Move Level2Bot::getMove(Board *board) {
    string cmd;
    cin >> cmd;
    if(cmd != "move"){
        return Move();
    }
    int row, col;
    srand (time(NULL));
    
    vector<Move> allMoves = board->getAllMoves(color);
    Move bestMove = allMoves[0];
    float bestScore = -10000;
    for(int i = 0; i < allMoves.size(); i++){
        float score = 0;
        if(board->getPiece(allMoves[i].getRow(), allMoves[i].getCol()) != nullptr && board->getPiece(allMoves[i].getRow(), allMoves[i].getCol())->getColor() != color){
            score += 1;
        }

        Board *tempBoard = new Board(*board);

        tempBoard->move(allMoves[i].getPrevRow(), allMoves[i].getPrevCol(), allMoves[i].getRow(), allMoves[i].getCol());

        if(color == 'w'){
            if(tempBoard->inCheck('b')){
                score += 1;
            }
        }
        else{
            if(tempBoard->inCheck('w')){
                score += 1;
            }
        }

        if(score > bestScore){
            bestScore = score;
            bestMove = allMoves[i];
        }
        

        delete tempBoard;
    }

    return bestMove;
}