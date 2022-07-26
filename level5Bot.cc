#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>

#include "board.h"
#include "level5Bot.h"
#include "move.h"
#include "textObserver.h"

using namespace std;

float Level5Bot::evaluate(Board *board){
    float score = 0;
    float totalPieces = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board->getPiece(i, j) != nullptr){
                totalPieces++;
                if(board->getPiece(i, j)->getName() == "wP"){
                    score += 8;
                    score += ((float)(6-i))/2;
                }
                else if(board->getPiece(i, j)->getName() == "wR"){
                    score += 40;
                }
                else if(board->getPiece(i, j)->getName() == "wN"){
                    score += 24;
                }
                else if(board->getPiece(i, j)->getName() == "wB"){
                    score += 24;
                }
                else if(board->getPiece(i, j)->getName() == "wQ"){
                    score += 64;
                }
                else if(board->getPiece(i, j)->getName() == "bP"){
                    score -= 8;
                    score -= ((float)(i-1))/2;
                }
                else if(board->getPiece(i, j)->getName() == "bR"){
                    score -= 40;
                }
                else if(board->getPiece(i, j)->getName() == "bN"){
                    score -= 24;
                }
                else if(board->getPiece(i, j)->getName() == "bB"){
                    score -= 24;
                }
                else if(board->getPiece(i, j)->getName() == "bQ"){
                    score -= 64;
                }
            }
        }
    }
    score += (((float)board->getAllMoves('w').size())/20);
    score -= (((float)board->getAllMoves('b').size())/20);
    score = score * ((34-totalPieces)/10);
    return score;
}

std::pair<float, Move> Level5Bot::minimax(Board *board, char color, int depth, float alpha, float beta){
    std::vector<std::vector<std::string>> stringboard;
    if(board->inCheckmate(color)){
        if(color == 'w'){
            return std::make_pair(std::numeric_limits<float>::lowest(), Move());
        }
        else{
            return std::make_pair(std::numeric_limits<float>::max(), Move());
        }
    }
    if(depth == 0){
        return std::make_pair(evaluate(board), Move());
    }

    vector<Move> moves = board->getAllMoves(color);

    if(color == 'w'){
        float bestScore = std::numeric_limits<float>::lowest();
        Move bestMove;
        for(int i = 0; i < moves.size(); i++){
            TextObserver *t = new TextObserver(stringboard);
            Board* newBoard = new Board(*board, t);
            newBoard->move(moves[i].getPrevRow(), moves[i].getPrevCol(), moves[i].getRow(), moves[i].getCol());
            std::pair<float, Move> temp = minimax(newBoard, 'b', depth - 1, alpha, beta);
            delete newBoard;
            delete t;
            if(temp.first > bestScore){
                bestScore = temp.first;
                bestMove = moves[i];
            }
            alpha = std::max(alpha, bestScore);
            if(beta <= alpha){
                break;
            }
        }
        return std::make_pair(bestScore, bestMove);
    }
    else{
        float bestScore = std::numeric_limits<float>::max();
        Move bestMove;
        for(int i = 0; i < moves.size(); i++){
            TextObserver *t = new TextObserver(stringboard);
            Board *newBoard = new Board(*board, t);
            newBoard->move(moves[i].getPrevRow(), moves[i].getPrevCol(), moves[i].getRow(), moves[i].getCol());
            std::pair<float, Move> temp = minimax(newBoard, 'w', depth - 1, alpha, beta);
            delete newBoard;
            delete t;
            if(temp.first < bestScore){
                bestScore = temp.first;
                bestMove = moves[i];
            }
            beta = std::min(beta, bestScore);
            if(beta <= alpha){
                break;
            }
        }
        return std::make_pair(bestScore, bestMove);
    }

}

Level5Bot::Level5Bot(char color) : Bot(color), movesMade{0} {
}


Move Level5Bot::getMove(Board *board){
    if(movesMade < 1){
        movesMade++;
        srand (time(NULL));
        int randomChoice = rand() % board->getAllMoves(color).size();
        return board->getAllMoves(color)[randomChoice];
    }
    std::pair<float, Move> temp = minimax(board, color, 3, std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max());
    return temp.second;
}

