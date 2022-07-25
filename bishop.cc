#include "bishop.h"
#include "piece.h"
#include "board.h"
#include "move.h"
#include <vector>

using namespace std;

Bishop::Bishop(char color) : Piece(color) {appendName('B');}

vector<Move> Bishop::findMoves(int row, int col, Board *board){
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

    return moves;
}
