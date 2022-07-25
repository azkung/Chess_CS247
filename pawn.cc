#include "piece.h"
#include "board.h"
#include "move.h"
#include "pawn.h"
#include <vector>
#include <string>

using namespace std;

Pawn::Pawn(char color) : Piece(color) {appendName('P');}

vector<Move> Pawn::findMoves(int row, int col, Board *board){
    vector<Move> moves;
    if(color == 'w'){
        if(row - 1 >= 0 && board->getPiece(row - 1, col) == nullptr){
            moves.push_back(Move(row - 1, col, row, col, false, false));
            if(lastMoved == -1 && board->getPiece(row - 2, col) == nullptr){
                moves.push_back(Move(row - 2, col, row, col, false, false));
            }
        }
        if(col - 1 >= 0 && board->getPiece(row - 1, col - 1) != nullptr && board->getPiece(row - 1, col - 1)->getColor() != color){
            moves.push_back(Move(row - 1, col - 1, row, col, false, false));
        }
        if(col + 1 < 8 && board->getPiece(row - 1, col + 1) != nullptr && board->getPiece(row - 1, col + 1)->getColor() != color){
            moves.push_back(Move(row - 1, col + 1, row, col, false, false));
        }
        if(row == 3){
            if(col-1 >= 0){
                if(board->getPiece(row, col - 1) != nullptr && board->getPiece(row, col-1)->getName() == "bp" && board->getPiece(row, col-1)->getLastMoved() == board->getMoveCounter()-1){
                    moves.push_back(Move(row - 1, col - 1, row, col, false, true));
                }
            }
            if(col+1 < 8){
                if(board->getPiece(row, col + 1) != nullptr && board->getPiece(row, col+1)->getName() == "bp" && board->getPiece(row, col+1)->getLastMoved() == board->getMoveCounter()-1){
                    moves.push_back(Move(row - 1, col + 1, row, col, false, true));
                }
            }
        }
    }
    else{
        if(row + 1 < 8 && board->getPiece(row + 1, col) == nullptr){
            moves.push_back(Move(row + 1, col, row, col, false, false));
            if(lastMoved == -1 && board->getPiece(row + 2, col) == nullptr){
                moves.push_back(Move(row + 2, col, row, col, false, false));
            }
        }
        if(col - 1 >= 0 && board->getPiece(row + 1, col - 1) != nullptr && board->getPiece(row + 1, col - 1)->getColor() != color){
            moves.push_back(Move(row + 1, col - 1, row, col, false, false));
        }
        if(col + 1 < 8 && board->getPiece(row + 1, col + 1) != nullptr && board->getPiece(row + 1, col + 1)->getColor() != color){
            moves.push_back(Move(row + 1, col + 1, row, col, false, false));
        }
        if(row == 4){
            if(col-1 >= 0){
                if(board->getPiece(row, col - 1) != nullptr && board->getPiece(row, col-1)->getName() == "wp" && board->getPiece(row, col-1)->getLastMoved() == board->getMoveCounter()-1){
                    moves.push_back(Move(row + 1, col - 1, row, col, false, true));
                }
            }
            if(col+1 < 8){
                if(board->getPiece(row, col + 1) != nullptr && board->getPiece(row, col+1)->getName() == "wp" && board->getPiece(row, col+1)->getLastMoved() == board->getMoveCounter()-1){
                    moves.push_back(Move(row + 1, col + 1, row, col, false, true));
                }
            }
        }
    }

    return moves;
}