#include <string>
#include <vector>
#include <iostream>
#include "tile.h"
#include "piece.h"
#include "observer.h"
#include "textObserver.h"

using namespace std;

TextObserver::TextObserver(std::vector<std::vector<std::string>> board) : board{board} {}

TextObserver::~TextObserver() {}

void TextObserver::notify(Tile &subject){
    string state = subject.getState();
    board[subject.getRow()][subject.getCol()] = state;
}

void TextObserver::printBoard(){
    for(int i = 0; i < 8; i++){
        cout << 8-i << " ";
        for(int j = 0; j < 8; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "  a  b  c  d  e  f  g  h" << endl;
}

std::string TextObserver::getState(int row, int col){
    return board[row][col];
}