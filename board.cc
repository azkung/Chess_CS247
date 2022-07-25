#include "board.h"
#include "tile.h"
#include "piece.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "textObserver.h"
#include "move.h"
#include <vector>

using namespace std;

Board::Board(TextObserver *textScreen) : moveCounter{0} {

    tiles.resize(8);
    for(int i = 0; i < 8; i++){
        tiles[i].resize(8);
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tiles[i][j] = new Tile(i, j, nullptr);
        }
    }
    tiles[0][0]->initPiece(new Rook('b'));
    tiles[0][1]->initPiece(new Knight('b'));
    tiles[0][2]->initPiece(new Bishop('b'));
    tiles[0][3]->initPiece(new Queen('b'));
    tiles[0][4]->initPiece(new King('b'));
    tiles[0][5]->initPiece(new Bishop('b'));
    tiles[0][6]->initPiece(new Knight('b'));
    tiles[0][7]->initPiece(new Rook('b'));
    for(int i = 0; i < 8; i++){
        tiles[1][i]->initPiece(new Pawn('b'));
    }
    tiles[7][0]->initPiece(new Rook('w'));
    tiles[7][1]->initPiece(new Knight('w'));
    tiles[7][2]->initPiece(new Bishop('w'));
    tiles[7][3]->initPiece(new Queen('w'));
    tiles[7][4]->initPiece(new King('w'));
    tiles[7][5]->initPiece(new Bishop('w'));
    tiles[7][6]->initPiece(new Knight('w'));
    tiles[7][7]->initPiece(new Rook('w'));
    for(int i = 0; i < 8; i++){
        tiles[6][i]->initPiece(new Pawn('w'));
    }

    vector<vector<string>> board;
    board.resize(8);
    for(int i = 0; i < 8; i++){
        board[i].resize(8);
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = tiles[i][j]->getState();
        }
    }

    textScreen = new TextObserver(board);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tiles[i][j]->attach(textScreen);
        }
    }

    textScreen->printBoard();
}

Board::~Board(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            delete tiles[i][j];
        }
    }
}

Piece* Board::getPiece(int row, int col){
    return tiles[row][col]->getPiece();
}

int Board::getMoveCounter(){
    return moveCounter;
}