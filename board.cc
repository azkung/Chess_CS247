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


vector<Move> Board::findMoves(int row, int col){
    vector<Move> moves;
    Piece *piece = tiles[row][col]->getPiece();
    

    if(piece == nullptr){
        return moves;
    }

    string name = piece->getName();
    if(name == "wP"){
        if(row-2 >= 0 && piece->getLastMoved() == -1){
            if(tiles[row-1][col]->getPiece() == nullptr && tiles[row-2][col]->getPiece() == nullptr){
                Move move(row-2, col, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row-1 >= 0){
            if(tiles[row-1][col]->getPiece() == nullptr){
                Move move(row-1, col, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row-1 >= 0 && col+1 < 8){
            if(tiles[row-1][col+1]->getPiece() != nullptr && tiles[row-1][col+1]->getPiece()->getName()[0] == 'b'){
                Move move(row-1, col+1, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row-1 >= 0 && col-1 >= 0){
            if(tiles[row-1][col-1]->getPiece() != nullptr && tiles[row-1][col-1]->getPiece()->getName()[0] == 'b'){
                Move move(row-1, col-1, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row == 3){
            if(col-1 >= 0){
                if(tiles[row][col-1]->getPiece() != nullptr && tiles[row][col-1]->getPiece()->getLastMoved() == moveCounter-1 && tiles[row][col-1]->getPiece()->getName()[0] == 'bP'){
                    Move move(row, col-1, row, col, false, true);
                    moves.push_back(move);
                }
            }
            if(col+1 < 8){
                if(tiles[row][col+1]->getPiece() != nullptr && tiles[row][col+1]->getPiece()->getLastMoved() == moveCounter-1 && tiles[row][col+1]->getPiece()->getName()[0] == 'bP'){
                    Move move(row, col+1, row, col, false, true);
                    moves.push_back(move);
                }
            }
        }
    }
    if(name == "bP"){
        if(row+2 < 8 && piece->getLastMoved() == -1){
            if(tiles[row+1][col]->getPiece() == nullptr && tiles[row+2][col]->getPiece() == nullptr){
                Move move(row+2, col, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row+1 < 8){
            if(tiles[row+1][col]->getPiece() == nullptr){
                Move move(row+1, col, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row+1 < 8 && col+1 < 8){
            if(tiles[row+1][col+1]->getPiece() != nullptr && tiles[row+1][col+1]->getPiece()->getName()[0] == 'w'){
                Move move(row+1, col+1, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row+1 < 8 && col-1 >= 0){
            if(tiles[row+1][col-1]->getPiece() != nullptr && tiles[row+1][col-1]->getPiece()->getName()[0] == 'w'){
                Move move(row+1, col-1, row, col, false, false);
                moves.push_back(move);
            }
        }
        if(row == 4){
            if(col-1 >= 0){
                if(tiles[row][col-1]->getPiece() != nullptr && tiles[row][col-1]->getPiece()->getLastMoved() == moveCounter-1 && tiles[row][col-1]->getPiece()->getName()[0] == 'wP'){
                    Move move(row, col-1, row, col, false, true);
                    moves.push_back(move);
                }
            }
            if(col+1 < 8){
                if(tiles[row][col+1]->getPiece() != nullptr && tiles[row][col+1]->getPiece()->getLastMoved() == moveCounter-1 && tiles[row][col+1]->getPiece()->getName()[0] == 'wP'){
                    Move move(row, col+1, row, col, false, true);
                    moves.push_back(move);
                }
            }
        }
    }

    if(name == "wR"){
        for(int i = row-1; i >= 0; i--){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'b'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = row+1; i < 8; i++){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'b'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col-1; i >= 0; i--){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'b'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col+1; i < 8; i++){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'b'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
    }

    if(name == "bR"){
        for(int i = row-1; i >= 0; i--){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'w'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = row+1; i < 8; i++){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'w'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col-1; i >= 0; i--){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'w'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col+1; i < 8; i++){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'w'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
    }

    if(name == "wQ"){
        for(int i = row-1; i >= 0; i--){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'b'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = row+1; i < 8; i++){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'b'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col-1; i >= 0; i--){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'b'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col+1; i < 8; i++){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'b'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col-1; i < 8 && j >= 0; i++, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col+1; i < 8 && j < 8; i++, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
    }

    if(name == "bQ"){
        for(int i = row-1; i >= 0; i--){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'w'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = row+1; i < 8; i++){
            if(tiles[i][col]->getPiece() == nullptr){
                Move move(i, col, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][col]->getPiece()->getName()[0] == 'w'){
                    Move move(i, col, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col-1; i >= 0; i--){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'w'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
        for(int i = col+1; i < 8; i++){
            if(tiles[row][i]->getPiece() == nullptr){
                Move move(row, i, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[row][i]->getPiece()->getName()[0] == 'w'){
                    Move move(row, i, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col-1; i < 8 && j >= 0; i++, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col+1; i < 8 && j < 8; i++, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
    }

    if(name == "wK"){
        if(row-1 >= 0 && tiles[row-1][col]->getPiece() == nullptr){
            Move move(row-1, col, row, col, false, false);
            moves.push_back(move);
        }
        if(row+1 >= 0 && tiles[row+1][col]->getPiece() == nullptr){
            Move move(row+1, col, row, col, false, false);
            moves.push_back(move);
        }
        if(col-1 >= 0 && tiles[row][col-1]->getPiece() == nullptr){
            Move move(row, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(col+1 >= 0 && tiles[row][col+1]->getPiece() == nullptr){
            Move move(row, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(row-1 >= 0 && col-1 >= 0 && tiles[row-1][col-1]->getPiece() == nullptr){
            Move move(row-1, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(row-1 >= 0 && col+1 >= 0 && tiles[row-1][col+1]->getPiece() == nullptr){
            Move move(row-1, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(row+1 >= 0 && col-1 >= 0 && tiles[row+1][col-1]->getPiece() == nullptr){
            Move move(row+1, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(row+1 >= 0 && col+1 >= 0 && tiles[row+1][col+1]->getPiece() == nullptr){
            Move move(row+1, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(piece->getLastMoved() == -1 && 
            tiles[7][7]->getPiece() != nullptr &&
            tiles[7][7]->getPiece()->getName() == "wR" && 
            tiles[7][7]->getPiece()->getLastMoved() == -1 &&
            tiles[7][6]->getPiece() == nullptr &&
            tiles[7][5]->getPiece() == nullptr
            ){
            Move move(7, 7, row, col, true, false);
        }
        if(piece->getLastMoved() == -1 && 
            tiles[7][0]->getPiece() != nullptr &&
            tiles[7][0]->getPiece()->getName() == "wR" && 
            tiles[0][7]->getPiece()->getLastMoved() == -1 &&
            tiles[7][1]->getPiece() == nullptr &&
            tiles[7][2]->getPiece() == nullptr &&
            tiles[7][3]->getPiece() == nullptr
            ){
            Move move(0, 7, row, col, true, false);
        }
    }

    if(name == "bK"){
        if(row-1 >= 0 && tiles[row-1][col]->getPiece() == nullptr){
            Move move(row-1, col, row, col, false, false);
            moves.push_back(move);
        }
        if(row+1 >= 0 && tiles[row+1][col]->getPiece() == nullptr){
            Move move(row+1, col, row, col, false, false);
            moves.push_back(move);
        }
        if(col-1 >= 0 && tiles[row][col-1]->getPiece() == nullptr){
            Move move(row, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(col+1 >= 0 && tiles[row][col+1]->getPiece() == nullptr){
            Move move(row, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(row-1 >= 0 && col-1 >= 0 && tiles[row-1][col-1]->getPiece() == nullptr){
            Move move(row-1, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(row-1 >= 0 && col+1 >= 0 && tiles[row-1][col+1]->getPiece() == nullptr){
            Move move(row-1, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(row+1 >= 0 && col-1 >= 0 && tiles[row+1][col-1]->getPiece() == nullptr){
            Move move(row+1, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(row+1 >= 0 && col+1 >= 0 && tiles[row+1][col+1]->getPiece() == nullptr){
            Move move(row+1, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(piece->getLastMoved() == -1 && 
            tiles[0][0]->getPiece() != nullptr &&
            tiles[0][0]->getPiece()->getName() == "bR" && 
            tiles[0][0]->getPiece()->getLastMoved() == -1 &&
            tiles[0][1]->getPiece() == nullptr &&
            tiles[0][2]->getPiece() == nullptr &&
            tiles[0][3]->getPiece() == nullptr
            ){
            Move move(0, 0, row, col, true, false);
        }
        if(piece->getLastMoved() == -1 && 
            tiles[0][7]->getPiece() != nullptr &&
            tiles[0][7]->getPiece()->getName() == "bR" && 
            tiles[0][7]->getPiece()->getLastMoved() == -1 &&
            tiles[0][6]->getPiece() == nullptr &&
            tiles[0][5]->getPiece() == nullptr
            ){
            Move move(0, 7, row, col, true, false);
        }
    }

    if(name == "wB"){
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col-1; i < 8 && j >= 0; i++, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col+1; i < 8 && j < 8; i++, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'b'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
    }

    if(name == "bB"){
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col-1; i < 8 && j >= 0; i++, j--){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }

        for (int i = row+1, j = col+1; i < 8 && j < 8; i++, j++){
            if(tiles[i][j]->getPiece() == nullptr){
                Move move(i, j, row, col, false, false);
                moves.push_back(move);
            }
            else{
                if(tiles[i][j]->getPiece()->getName()[0] == 'w'){
                    Move move(i, j, row, col, false, false);
                    moves.push_back(move);
                }
                break;
            }
        }
    }

    if(name == "wN"){
        if(tiles[row-2][col-1]->getPiece() == nullptr || tiles[row-2][col-1]->getPiece()->getName()[0] == 'b'){
            Move move(row-2, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row-2][col+1]->getPiece() == nullptr || tiles[row-2][col+1]->getPiece()->getName()[0] == 'b'){
            Move move(row-2, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row-1][col-2]->getPiece() == nullptr || tiles[row-1][col-2]->getPiece()->getName()[0] == 'b'){
            Move move(row-1, col-2, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row-1][col+2]->getPiece() == nullptr || tiles[row-1][col+2]->getPiece()->getName()[0] == 'b'){
            Move move(row-1, col+2, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row+1][col-2]->getPiece() == nullptr || tiles[row+1][col-2]->getPiece()->getName()[0] == 'b'){
            Move move(row+1, col-2, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row+1][col+2]->getPiece() == nullptr || tiles[row+1][col+2]->getPiece()->getName()[0] == 'b'){
            Move move(row+1, col+2, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row+2][col-1]->getPiece() == nullptr || tiles[row+2][col-1]->getPiece()->getName()[0] == 'b'){
            Move move(row+2, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row+2][col+1]->getPiece() == nullptr || tiles[row+2][col+1]->getPiece()->getName()[0] == 'b'){
            Move move(row+2, col+1, row, col, false, false);
            moves.push_back(move);
        }
    }

    if(name == "bN"){
        if(tiles[row-2][col-1]->getPiece() == nullptr || tiles[row-2][col-1]->getPiece()->getName()[0] == 'w'){
            Move move(row-2, col-1, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row-2][col+1]->getPiece() == nullptr || tiles[row-2][col+1]->getPiece()->getName()[0] == 'w'){
            Move move(row-2, col+1, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row-1][col-2]->getPiece() == nullptr || tiles[row-1][col-2]->getPiece()->getName()[0] == 'w'){
            Move move(row-1, col-2, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row-1][col+2]->getPiece() == nullptr || tiles[row-1][col+2]->getPiece()->getName()[0] == 'w'){
            Move move(row-1, col+2, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row+1][col-2]->getPiece() == nullptr || tiles[row+1][col-2]->getPiece()->getName()[0] == 'w'){
            Move move(row+1, col-2, row, col, false, false);
            moves.push_back(move);
        }
        if(tiles[row+1][col+2]->getPiece() == nullptr || tiles[row+1][col+2]->getPiece()->getName()[0] == 'w'){
            Move move(row+1, col+2, row, col, false, false);
            moves.push_back(move);
        }
    }


    return moves;
}

vector<Move> Board::findMoves(int row, int col){
    vector<Move> possibleMoves;
    Piece *piece = tiles[row][col]->getPiece();

    if(piece->getName() == "wP"){

        possibleMoves.emplace_back(Move(row, col, row+1, col, false, false));

    }
    return possibleMoves;
}