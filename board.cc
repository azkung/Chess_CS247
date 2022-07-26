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

Board::Board(TextObserver *textScreen) : moveCounter{0}, turnModifier{0} {

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

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tiles[i][j]->attach(textScreen);
        }
    }

}

Board::Board(const Board &other, TextObserver *textScreen) : moveCounter{other.moveCounter} {

    tiles.resize(8);
    for(int i = 0; i < 8; i++){
        tiles[i].resize(8);
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tiles[i][j] = new Tile(i, j, nullptr);
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(other.tiles[i][j]->getPiece() != nullptr){
                if(other.tiles[i][j]->getPiece()->getName() == "wP"){
                    tiles[i][j]->initPiece(new Pawn('w'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "wR"){
                    tiles[i][j]->initPiece(new Rook('w'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "wN"){
                    tiles[i][j]->initPiece(new Knight('w'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "wB"){
                    tiles[i][j]->initPiece(new Bishop('w'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "wQ"){
                    tiles[i][j]->initPiece(new Queen('w'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "wK"){
                    tiles[i][j]->initPiece(new King('w'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "bP"){
                    tiles[i][j]->initPiece(new Pawn('b'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "bR"){
                    tiles[i][j]->initPiece(new Rook('b'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "bN"){
                    tiles[i][j]->initPiece(new Knight('b'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "bB"){
                    tiles[i][j]->initPiece(new Bishop('b'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "bQ"){
                    tiles[i][j]->initPiece(new Queen('b'));
                }
                else if(other.tiles[i][j]->getPiece()->getName() == "bK"){
                    tiles[i][j]->initPiece(new King('b'));
                }
                tiles[i][j]->getPiece()->setLastMoved(other.tiles[i][j]->getPiece()->getLastMoved());
            }
            else{
                tiles[i][j]->initPiece(nullptr);
            }
        }
    }
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

bool Board::inCheck(char playerTurn){
    if(playerTurn == 'w'){
        int kingRow = 0;
        int kingCol = 0; 
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(tiles[i][j]->getPiece() != nullptr){
                    if(tiles[i][j]->getPiece()->getName() == "wK"){
                        kingRow = i;
                        kingCol = j;
                    }
                }
            }
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(tiles[i][j]->getPiece() != nullptr){
                    if(tiles[i][j]->getPiece()->getColor() == 'b'){
                        vector<Move> moves = tiles[i][j]->findMoves(this);
                        for(int k = 0; k < moves.size(); k++){
                            if(moves[k].getRow() == kingRow && moves[k].getCol() == kingCol){
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        int kingRow = 0;
        int kingCol = 0; 
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(tiles[i][j]->getPiece() != nullptr){
                    if(tiles[i][j]->getPiece()->getName() == "bK"){
                        kingRow = i;
                        kingCol = j;
                    }
                }
            }
        }

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(tiles[i][j]->getPiece() != nullptr){
                    if(tiles[i][j]->getPiece()->getColor() == 'w'){
                        vector<Move> moves = tiles[i][j]->findMoves(this);
                        for(int k = 0; k < moves.size(); k++){
                            if(moves[k].getRow() == kingRow && moves[k].getCol() == kingCol){
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Board::inCheckmate(char playerTurn){
    // returns whether playerTurn is in checkmate
    vector<vector<string>> temp;
    TextObserver* t =  new TextObserver(temp);
    if(inCheck(playerTurn)){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(tiles[i][j]->getPiece() != nullptr){
                    if(tiles[i][j]->getPiece()->getColor() == playerTurn){
                        vector<Move> moves = tiles[i][j]->findMoves(this);
                        killRestrict(moves, playerTurn);
                        if(moves.size() > 0){
                            delete t;
                            return false;
                        }
                    }
                }
            }
        }
        delete t;
        return true;
    }
    delete t;
    return false;
    
}

void Board::killRestrict(vector<Move>& moves, char playerTurn){
    vector<vector<string>> temp;
    TextObserver* t =  new TextObserver(temp);
    if(playerTurn == 'w'){
        for(int i = 0; i < moves.size(); i++){
            int row1 = moves[i].getPrevRow();
            int col1 = moves[i].getPrevCol();
            int row2 = moves[i].getRow();
            int col2 = moves[i].getCol();
            Board tempBoard = Board(*this, t);

            Piece* piece1 = tempBoard.getPiece(row1, col1);
            Piece* piece2 = tempBoard.getPiece(row2, col2);

            if(piece2 != nullptr){
                delete piece2;
                tempBoard.tiles[row2][col2]->initPiece(piece1);
            }

            piece1->setLastMoved(moveCounter);
            
            tempBoard.tiles[row1][col1]->setPiece(nullptr);
            tempBoard.tiles[row2][col2]->setPiece(piece1);

            if(moves[i].getIsCastle()){
                if(moves[i].getCol() == 2){
                    tempBoard.tiles[row2][3]->setPiece(tempBoard.tiles[row2][0]->getPiece());
                    tempBoard.tiles[row2][3]->getPiece()->setLastMoved(moveCounter);
                    tempBoard.tiles[row2][0]->setPiece(nullptr);
                }
                else{
                    tempBoard.tiles[row2][5]->setPiece(tempBoard.tiles[row2][7]->getPiece());
                    tempBoard.tiles[row2][5]->getPiece()->setLastMoved(moveCounter);
                    tempBoard.tiles[row2][7]->setPiece(nullptr);
                }
            }            
            if(moves[i].getIsEnPassant()){
                delete tempBoard.tiles[row1][col2]->getPiece();
                tempBoard.tiles[row1][col2]->initPiece(nullptr);
            }
            tempBoard.moveCounter++;
            tempBoard.movesMade.push_back(moves[i]);
            if(tempBoard.inCheck('w')){
                moves.erase(moves.begin() + i);
                i--;
            }
        }
    }
    else{
        for(int i = 0; i < moves.size(); i++){
            int row1 = moves[i].getPrevRow();
            int col1 = moves[i].getPrevCol();
            int row2 = moves[i].getRow();
            int col2 = moves[i].getCol();
            Board tempBoard = Board(*this, t);

            Piece* piece1 = tempBoard.getPiece(row1, col1);
            Piece* piece2 = tempBoard.getPiece(row2, col2);
            if(piece2 != nullptr){
                delete piece2;
                tempBoard.tiles[row2][col2]->initPiece(piece1);
            }
            piece1->setLastMoved(moveCounter);
            tempBoard.tiles[row1][col1]->setPiece(nullptr);
            tempBoard.tiles[row2][col2]->setPiece(piece1);
            if(moves[i].getIsCastle()){
                if(moves[i].getCol() == 2){
                    tempBoard.tiles[row2][3]->setPiece(tempBoard.tiles[row2][0]->getPiece());
                    tempBoard.tiles[row2][3]->getPiece()->setLastMoved(moveCounter);
                    tempBoard.tiles[row2][0]->setPiece(nullptr);
                }
                else{
                    tempBoard.tiles[row2][5]->setPiece(tempBoard.tiles[row2][7]->getPiece());
                    tempBoard.tiles[row2][5]->getPiece()->setLastMoved(moveCounter);
                    tempBoard.tiles[row2][7]->setPiece(nullptr);
                }
            }
            if(moves[i].getIsEnPassant()){
                delete tempBoard.tiles[row1][col2]->getPiece();
                tempBoard.tiles[row1][col2]->initPiece(nullptr);
            }
            tempBoard.moveCounter++;
            tempBoard.movesMade.push_back(moves[i]);
            if(tempBoard.inCheck('b')){
                moves.erase(moves.begin() + i);
                i--;
            }
        }
    }
    delete t;
}

vector<Move> Board::findMoves(int row, int col, char playerTurn){
    vector<Move> moves;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(tiles[i][j]->getPiece() != nullptr){
                vector<Move> temp = tiles[i][j]->findMoves(this);
                for(int k = 0; k < temp.size(); k++){
                    moves.push_back(temp[k]);
                }
            }
        }
    }
    killRestrict(moves, playerTurn);

    return moves;
}


bool Board::move(int row1, int col1, int row2, int col2){
    vector<Move> moves = tiles[row1][col1]->findMoves(this);
    if(tiles[row1][col1]->getPiece() == nullptr){
        return false;
    }

    if(tiles[row1][col1]->getPiece()->getColor() != getTurn()){
        return false;
    }
    killRestrict(moves, getTurn());


    Piece* piece1 = tiles[row1][col1]->getPiece();
    Piece* piece2 = tiles[row2][col2]->getPiece();
    bool found = false;
    int index = 0;
    for(int i = 0; i < moves.size(); i++){
        if(moves[i].getPrevRow() == row1 && moves[i].getPrevCol() == col1 && moves[i].getRow() == row2 && moves[i].getCol() == col2){
            found = true;
            index = i;
            break;
        }
    }
    if(found){
        if(piece2 != nullptr){
            delete piece2;
            tiles[row2][col2]->initPiece(piece1);
        }

        piece1->setLastMoved(moveCounter);
        
        tiles[row1][col1]->setPiece(nullptr);
        tiles[row2][col2]->setPiece(piece1);

        if(moves[index].getIsCastle()){
            if(moves[index].getCol() == 2){
                tiles[row2][3]->setPiece(tiles[row2][0]->getPiece());
                tiles[row2][3]->getPiece()->setLastMoved(moveCounter);
                tiles[row2][0]->setPiece(nullptr);
            }
            else{
                tiles[row2][5]->setPiece(tiles[row2][7]->getPiece());
                tiles[row2][5]->getPiece()->setLastMoved(moveCounter);
                tiles[row2][7]->setPiece(nullptr);
            }
        }
        if(moves[index].getIsEnPassant()){
            delete tiles[row1][col2]->getPiece();
            tiles[row1][col2]->setPiece(nullptr);
        }

        movesMade.push_back(moves[index]);
        moveCounter++;
        return true;
    }
    return false;
}

char Board::getTurn(){
    if((moveCounter+turnModifier) % 2 == 0){
        return 'w';
    }
    return 'b';
}


vector<Move> Board::getAllMoves(char playerTurn){
    vector<Move> moves;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(tiles[i][j]->getPiece() != nullptr && tiles[i][j]->getPiece()->getColor() == playerTurn){
                vector<Move> temp = tiles[i][j]->findMoves(this);
                for(int k = 0; k < temp.size(); k++){
                    moves.push_back(temp[k]);
                }
            }
        }
    }
    killRestrict(moves, playerTurn);
    return moves;
}

void Board::setPiece(int row, int col, Piece* piece){
    if(tiles[row][col]->getPiece() != nullptr){
        delete tiles[row][col]->getPiece();
    }
    tiles[row][col]->setPiece(piece);
}

void Board::removePiece(int row, int col){
    if(tiles[row][col]->getPiece() != nullptr){
        delete tiles[row][col]->getPiece();
    }
    tiles[row][col]->setPiece(nullptr);
}

void Board::setTurn(char turn){
    if(turn == 'w'){
        turnModifier = 0;
    }
    else if (turn == 'b'){
        turnModifier = 1;
    }
    else{
        cout << "Invalid turn" << endl;
    }
}

bool Board::isValid(){
    int whiteKingCounter = 0;
    int blackKingCounter = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(tiles[i][j]->getPiece() != nullptr){
                if(tiles[i][j]->getPiece()->getName() == "wK"){
                    whiteKingCounter++;
                }
                else if(tiles[i][j]->getPiece()->getName() == "bK"){
                    blackKingCounter++;
                }
                else if(tiles[i][j]->getPiece()->getName() == "bP"){
                    if(i == 7 || i == 0){
                        return false;
                    }
                }
                else if(tiles[i][j]->getPiece()->getName() == "wP"){
                    if(i == 7 || i == 0){
                        return false;
                    }
                }
            }
        }
    }
    if(inCheck('w') || inCheck('b')){
        return false;
    }
    if(whiteKingCounter != 1 || blackKingCounter != 1){
        return false;
    }
    return true;
}