#include "move.h"
Move::Move(){
    this->row = -1;
    this->col = -1;
    this->prevRow = -1;
    this->prevCol = -1;
    this->isCastle = false;
    this->isEnPassant = false;
}


Move::Move(int row, int col, int prevRow, int prevCol, bool isCastle, bool isEnPassant){
    this->row = row;
    this->col = col;
    this->prevRow = prevRow;
    this->prevCol = prevCol;
    this->isCastle = isCastle;
    this->isEnPassant = isEnPassant;
}

const int Move::getCol(){
    return this->col;
}

const int Move::getRow(){
    return this->row;
}

const int Move::getPrevCol(){
    return this->prevCol;
}

const int Move::getPrevRow(){
    return this->prevRow;
}

const bool Move::getIsCastle(){
    return this->isCastle;
}

const bool Move::getIsEnPassant(){
    return this->isEnPassant;
}
