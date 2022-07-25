#include <string>
#include <vector>
#include "tile.h"
#include "piece.h"
#include "observer.h"
#include "textObserver.h"

using namespace std;

TextObserver::TextObserver(std::vector<std::vector<std::string>> board) : board(board) {}

TextObserver::~TextObserver() {}

void TextObserver::notify(Tile &subject){
    string state = subject.getState();
    board[subject.getRow()][subject.getCol()] = state;
    printBoard();
}

void TextObserver::printBoard(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}