
#include "knight.h"

Knight::Knight(char color) : Piece(color) {appendName('N');}

std::vector<Move> Knight::findMoves(int row, int col, Board *board){
    std::vector<Move> moves;
    
    if(row+2 < 8 && col+1 < 8){
        if(board->getPiece(row+2, col+1) == nullptr){
            moves.push_back(Move(row+2, col+1, row, col, false, false));
        }
        else if(board->getPiece(row+2, col+1)->getColor() != getColor()){
            moves.push_back(Move(row+2, col+1, row, col, false, false));
        }
    }
    if(row+2 < 8 && col-1 >= 0){
        if(board->getPiece(row+2, col-1) == nullptr){
            moves.push_back(Move(row+2, col-1, row, col, false, false));
        }
        else if(board->getPiece(row+2, col-1)->getColor() != getColor()){
            moves.push_back(Move(row+2, col-1, row, col, false, false));
        }
    }
    if(row-2 >= 0 && col+1 < 8){
        if(board->getPiece(row-2, col+1) == nullptr){
            moves.push_back(Move(row-2, col+1, row, col, false, false));
        }
        else if(board->getPiece(row-2, col+1)->getColor() != getColor()){
            moves.push_back(Move(row-2, col+1, row, col, false, false));
        }
    }
    if(row-2 >= 0 && col-1 >= 0){
        if(board->getPiece(row-2, col-1) == nullptr){
            moves.push_back(Move(row-2, col-1, row, col, false, false));
        }
        else if(board->getPiece(row-2, col-1)->getColor() != getColor()){
            moves.push_back(Move(row-2, col-1, row, col, false, false));
        }
    }


    return moves;
}