#include "king.h"
#include "board.h"
#include "move.h"
#include <vector>
#include <iostream>

King::King(char color) : Piece(color) {appendName('K');}


std::vector<Move> King::findMoves(int row, int col, Board *board){
    std::vector<Move> moves;
    if(row - 1 >= 0 && col - 1 >= 0){
        if(board->getPiece(row-1, col-1) == nullptr || board->getPiece(row - 1, col - 1)->getColor() != color){
            moves.push_back(Move(row, col, row - 1, col - 1, false, false));
        }
    }
    if(row - 1 >= 0){
        if(board->getPiece(row-1, col) == nullptr || board->getPiece(row - 1, col)->getColor() != color){
            moves.push_back(Move(row, col, row - 1, col, false, false));
        }
    }
    if(row - 1 >= 0 && col + 1 < 8){
        if(board->getPiece(row-1, col+1) == nullptr || board->getPiece(row - 1, col + 1)->getColor() != color){
            moves.push_back(Move(row, col, row - 1, col + 1, false, false));
        }
    }
    if(col - 1 >= 0){
        if(board->getPiece(row, col-1) == nullptr || board->getPiece(row, col - 1)->getColor() != color){
            moves.push_back(Move(row, col, row, col - 1, false, false));
        }
    }
    if(col + 1 < 8){
        if(board->getPiece(row, col+1) == nullptr || board->getPiece(row, col + 1)->getColor() != color){
            moves.push_back(Move(row, col, row, col + 1, false, false));
        }
    }
    if(row + 1 < 8 && col - 1 >= 0){
        if(board->getPiece(row+1, col-1) == nullptr || board->getPiece(row + 1, col - 1)->getColor() != color){
            moves.push_back(Move(row, col, row + 1, col - 1, false, false));
        }
    }
    if(row + 1 < 8){
        if(board->getPiece(row+1, col) == nullptr || board->getPiece(row + 1, col)->getColor() != color){
            moves.push_back(Move(row, col, row + 1, col, false, false));
        }
    }
    if(row + 1 < 8 && col + 1 < 8){
        if(board->getPiece(row+1, col+1) == nullptr || board->getPiece(row + 1, col + 1)->getColor() != color){
            moves.push_back(Move(row, col, row + 1, col + 1, false, false));
        }
    }

    //Castling
    if(lastMoved == -1){
        if(color == 'b'){
            if(board->getPiece(0, 0) != nullptr && 
                board->getPiece(0, 0)->getName() == "bR" && 
                board->getPiece(0, 0)->getLastMoved() == -1 &&
                board->getPiece(0, 1) == nullptr && 
                board->getPiece(0, 2) == nullptr && 
                board->getPiece(0, 3) == nullptr){
                moves.push_back(Move(0, 2, row, col, true, false));
            }
            if(board->getPiece(0, 7) != nullptr && 
                board->getPiece(0, 7)->getName() == "bR" && 
                board->getPiece(0, 7)->getLastMoved() == -1 &&
                board->getPiece(0, 5) == nullptr && 
                board->getPiece(0, 6) == nullptr){
                moves.push_back(Move(0, 6, row, col, true, false));
            }
        }
        else{
            std::cout << "hi";
            if(board->getPiece(7, 0) != nullptr && 
                board->getPiece(7, 0)->getName() == "wR" && 
                board->getPiece(7, 0)->getLastMoved() == -1 &&
                board->getPiece(7, 1) == nullptr && 
                board->getPiece(7, 2) == nullptr && 
                board->getPiece(7, 3) == nullptr){
                moves.push_back(Move(7, 2, row, col, true, false));
            }
            if(board->getPiece(7, 7) != nullptr && 
                board->getPiece(7, 7)->getName() == "wR" && 
                board->getPiece(7, 7)->getLastMoved() == -1 &&
                board->getPiece(7, 5) == nullptr && 
                board->getPiece(7, 6) == nullptr){
                moves.push_back(Move(7, 6, row, col, true, false));
            }
        }
    }


    return moves;

}