#include "queen.h"
#include "board.h"
#include "move.h"
#include <vector>

using namespace std;

Queen::Queen(char color) : Piece(color) {appendName('Q');}

std::vector<Move> Queen::findMoves(int row, int col, Board *board){
    vector<Move> moves;
    
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(board->getPiece(i, j) == nullptr){
            moves.push_back(Move(i, j, row, col, false, false));
        }
        else if(board->getPiece(i, j)->getColor() != color){
            moves.push_back(Move(i, j, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }
    
    for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++){
        if(board->getPiece(i, j) == nullptr){
            moves.push_back(Move(i, j, row, col, false, false));
        }
        else if(board->getPiece(i, j)->getColor() != color){
            moves.push_back(Move(i, j, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }
    
    for (int i = row+1, j = col-1; i < 8 && j >= 0; i++, j--){
        if(board->getPiece(i, j) == nullptr){
            moves.push_back(Move(i, j, row, col, false, false));
        }
        else if(board->getPiece(i, j)->getColor() != color){
            moves.push_back(Move(i, j, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }

    for (int i = row+1, j = col+1; i < 8 && j < 8; i++, j++){
        if(board->getPiece(i, j) == nullptr){
            moves.push_back(Move(i, j, row, col, false, false));
        }
        else if(board->getPiece(i, j)->getColor() != color){
            moves.push_back(Move(i, j, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }

    for (int i = row-1; i >= 0; i--){
        if(board->getPiece(i, col) == nullptr){
            moves.push_back(Move(i, col, row, col, false, false));
        }
        else if(board->getPiece(i, col)->getColor() != color){
            moves.push_back(Move(i, col, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }
    
    for (int i = row+1; i < 8; i++){
        if(board->getPiece(i, col) == nullptr){
            moves.push_back(Move(i, col, row, col, false, false));
        }
        else if(board->getPiece(i, col)->getColor() != color){
            moves.push_back(Move(i, col, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }
    
    for (int j = col-1; j >= 0; j--){
        if(board->getPiece(row, j) == nullptr){
            moves.push_back(Move(row, j, row, col, false, false));
        }
        else if(board->getPiece(row, j)->getColor() != color){
            moves.push_back(Move(row, j, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }
    
    for (int j = col+1; j < 8; j++){
        if(board->getPiece(row, j) == nullptr){
            moves.push_back(Move(row, j, row, col, false, false));
        }
        else if(board->getPiece(row, j)->getColor() != color){
            moves.push_back(Move(row, j, row, col, false, false));
            break;
        }
        else{
            break;
        }
    }

    return moves;

}
