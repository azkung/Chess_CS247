#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include "board.h"
#include "level3Bot.h"
#include "move.h"

using namespace std;


Level3Bot::Level3Bot(char color) : Bot(color) {}

Move Level3Bot::getMove(Board *board) {
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
            vector<Move> allOtherMoves = tempBoard->getAllMoves('b');
            if(tempBoard->inCheck('b')){
                score -= 1;
            }
            for(int j = 0; j < allOtherMoves.size(); j++){
                if(allOtherMoves[j].getRow() == allMoves[i].getRow() && allOtherMoves[j].getCol() == allMoves[i].getCol()){
                    score -= 1;
                }
            }
            if(score > bestScore){
                bestScore = score;
                bestMove = allMoves[i];
            }
        }
        else{
            vector<Move> allOtherMoves = tempBoard->getAllMoves('w');
            if(tempBoard->inCheck('w')){
                score -= 1;
            }
            for(int j = 0; j < allOtherMoves.size(); j++){
                if(allOtherMoves[j].getRow() == allMoves[i].getRow() && allOtherMoves[j].getCol() == allMoves[i].getCol()){
                    score -= 1;
                }
            }
            if(score > bestScore){
                bestScore = score;
                bestMove = allMoves[i];
            }
        }
        delete tempBoard;
    }

    return bestMove;
}