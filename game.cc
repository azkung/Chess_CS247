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
            stringBoard[i][j] = "__";
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
    textScreen->printBoard();
}


bool Game::makeMove(){
    // cout << board->inCheckmate('w') << board->inCheckmate('b') << endl;
    if(board->inCheckmate('w')){
        cout << "Black wins!" << endl;
        return false;
    }
    else if(board->inCheckmate('b')){
        cout << "White wins!" << endl;
        return false;
    }


    cout << "Enter a move: ";
    char col1, col2, row1, row2;
    cin >> col1 >> row1 >> col2 >> row2;
    int col1Int = col1 - 'a';
    int col2Int = col2 - 'a';
    int row1Int = 7 - (row1 - '1');
    int row2Int = 7 - (row2 - '1');
    cout << endl;
    // cout << col1Int << " " << row1Int << " " << col2Int << " " << row2Int << endl;


    if(!board->move(row1Int, col1Int, row2Int, col2Int)){
        cout << "Invalid move!" << endl;
    }


    textScreen->printBoard();
    return true;
}

Game::~Game(){
    delete board;
}