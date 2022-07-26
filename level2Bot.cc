#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include "textObserver.h"

#include "board.h"
#include "level2Bot.h"
#include "move.h"

using namespace std;

Level2Bot::Level2Bot(char color) : Bot(color) {}

Move Level2Bot::getMove(Board *board) {
    std::vector<std::vector<std::string>> stringboard;
    
    vector<Move> allMoves = board->getAllMoves(color);
    Move bestMove = allMoves[0];
    float bestScore = -10000;
    bool allSameScore = true;

    for(int i = 0; i < allMoves.size(); i++){
        float score = 0;
        if(board->getPiece(allMoves[i].getRow(), allMoves[i].getCol()) != nullptr && board->getPiece(allMoves[i].getRow(), allMoves[i].getCol())->getColor() != color){
            score += 1;
        }

        TextObserver *t = new TextObserver(stringboard);
        Board tempBoard = Board(*board, t);

        tempBoard.move(allMoves[i].getPrevRow(), allMoves[i].getPrevCol(), allMoves[i].getRow(), allMoves[i].getCol());

        if(color == 'w'){
            if(tempBoard.inCheck('b')){
                score += 1;
            }
        }
        else{
            if(tempBoard.inCheck('w')){
                score += 1;
            }
        }
        if(i != 0){
            if(score != bestScore){
                allSameScore = false;
            }
        }

        if(score > bestScore){
            bestScore = score;
            bestMove = allMoves[i];
        }
        delete t;
    }

    if(allSameScore){
        srand (time(NULL));
        int randomChoice = rand() % allMoves.size();
        bestMove = allMoves[randomChoice];
    }

    return bestMove;
}