#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#include "board.h"
#include "level4Bot.h"
#include "move.h"

using namespace std;

float Level4Bot::evaluate(Board *board){
    float score = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board->getPiece(i, j) != nullptr){
                if(board->getPiece(i, j)->getName() == "wP"){
                    score += 1;
                }
                else if(board->getPiece(i, j)->getName() == "wR"){
                    score += 5;
                }
                else if(board->getPiece(i, j)->getName() == "wN"){
                    score += 3;
                }
                else if(board->getPiece(i, j)->getName() == "wB"){
                    score += 3;
                }
                else if(board->getPiece(i, j)->getName() == "wQ"){
                    score += 9;
                }
                else if(board->getPiece(i, j)->getName() == "bP"){
                    score -= 1;
                }
                else if(board->getPiece(i, j)->getName() == "bR"){
                    score -= 5;
                }
                else if(board->getPiece(i, j)->getName() == "bN"){
                    score -= 3;
                }
                else if(board->getPiece(i, j)->getName() == "bB"){
                    score -= 3;
                }
                else if(board->getPiece(i, j)->getName() == "bQ"){
                    score -= 9;
                }
            }
        }
    }
    return score;
}

std::pair<float, Move> Level4Bot::minimax(Board *board, char color, int depth, float alpha, float beta){
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
            Board *newBoard = new Board(*board);
            newBoard->move(moves[i].getPrevRow(), moves[i].getPrevCol(), moves[i].getRow(), moves[i].getCol());
            std::pair<float, Move> temp = minimax(newBoard, 'b', depth - 1, alpha, beta);
            if(temp.first > bestScore){
                bestScore = temp.first;
                bestMove = moves[i];
            }
            alpha = std::max(alpha, bestScore);
            if(beta <= alpha){
                break;
            }
            delete newBoard;
        }
        return std::make_pair(bestScore, bestMove);
    }
    else{
        float bestScore = std::numeric_limits<float>::max();
        Move bestMove;
        for(int i = 0; i < moves.size(); i++){
            Board *newBoard = new Board(*board);
            newBoard->move(moves[i].getPrevRow(), moves[i].getPrevCol(), moves[i].getRow(), moves[i].getCol());
            std::pair<float, Move> temp = minimax(newBoard, 'w', depth - 1, alpha, beta);
            if(temp.first < bestScore){
                bestScore = temp.first;
                bestMove = moves[i];
            }
            beta = std::min(beta, bestScore);
            if(beta <= alpha){
                break;
            }
            delete newBoard;
        }
        return std::make_pair(bestScore, bestMove);
    }

}

Level4Bot::Level4Bot(char color) : Bot(color) {
}


Move Level4Bot::getMove(Board *board){
    std::pair<float, Move> temp = minimax(board, color, 4, std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max());
    return temp.second;
}

