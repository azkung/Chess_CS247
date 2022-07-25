#include "game.h"
#include "board.h"
#include <iostream>
#include "textObserver.h"
#include <vector>

using namespace std;

Game::Game(){
    cout << "Welcome to Chess!" << endl;
    vector<vector<string>> stringBoard;
    stringBoard.resize(8);
    for(int i = 0; i < 8; i++){
        stringBoard[i].resize(8);
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            stringBoard[i][j] = " ";
        }
    }
    stringBoard[0][0] = "bR";
    stringBoard[0][1] = "bN";
    stringBoard[0][2] = "bB";
    stringBoard[0][3] = "bQ";
    stringBoard[0][4] = "bK";
    stringBoard[0][5] = "bB";
    stringBoard[0][6] = "bN";
    stringBoard[0][7] = "bR";
    for(int i = 0; i < 8; i++){
        stringBoard[1][i] = "bP";
    }
    stringBoard[7][0] = "wR";
    stringBoard[7][1] = "wN";
    stringBoard[7][2] = "wB";
    stringBoard[7][3] = "wQ";
    stringBoard[7][4] = "wK";
    stringBoard[7][5] = "wB";
    stringBoard[7][6] = "wN";
    stringBoard[7][7] = "wR";
    for(int i = 0; i < 8; i++){
        stringBoard[6][i] = "wP";
    }
    
    textScreen = new TextObserver(stringBoard);
    board = new Board(textScreen);
}


void Game::makeMove(){
    cout << "Enter a move: ";
    char col1, col2, row1, row2;
    cin >> col1 >> row1 >> col2 >> row2;


}

Game::~Game(){
    delete board;
}