#include "game.h"
#include "board.h"
#include <iostream>
#include "textObserver.h"
#include <vector>

using namespace std;

SDL_Runner g;

Game::Game(){
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
    drawScreen();
}



bool Game::makeMove(){
    if(board->inCheckmate('w')){
        cout << "Black wins!" << endl;
        return false;
    }
    else if(board->inCheckmate('b')){
        cout << "White wins!" << endl;
        return false;
    }


    // cout << "Enter a move: ";
    char col1, col2, row1, row2;
    cin >> col1;
    if(col1 == 'x'){
        return false;
    }
    cin >> row1 >> col2 >> row2;
    int col1Int = col1 - 'a';
    int col2Int = col2 - 'a';
    int row1Int = 7 - (row1 - '1');
    int row2Int = 7 - (row2 - '1');
    cout << endl;


    if(!board->move(row1Int, col1Int, row2Int, col2Int)){
        cout << "Invalid move!" << endl;
    }


    drawScreen();
    return true;
}

bool Game::getWinner() {
    return !board->inCheckmate('w');
}

bool Game::gameEnded() {
    return (board->inCheckmate('w') || board->inCheckmate('b'));
}

char Game::currTurn() {
    return board->getTurn();
}


void Game::drawScreen() {
    Colour green{'\x76','\x96','\x56'};
    Colour tan{'\xEE','\xEE','\xD2'};


    s.draw_rect(0, 0, 600, 600, green);
    s.draw_rect(0, 0, 75, 75, tan);
    s.draw_rect(150, 0, 75, 75, tan);
    s.draw_rect(300, 0, 75, 75, tan);
    s.draw_rect(450, 0, 75, 75, tan);

    s.draw_rect(75, 75, 75, 75, tan);
    s.draw_rect(225, 75, 75, 75, tan);
    s.draw_rect(375, 75, 75, 75, tan);
    s.draw_rect(525, 75, 75, 75, tan);

    s.draw_rect(0, 150, 75, 75, tan);
    s.draw_rect(150, 150, 75, 75, tan);
    s.draw_rect(300, 150, 75, 75, tan);
    s.draw_rect(450, 150, 75, 75, tan);

    s.draw_rect(75, 225, 75, 75, tan);
    s.draw_rect(225, 225, 75, 75, tan);
    s.draw_rect(375, 225, 75, 75, tan);
    s.draw_rect(525, 225, 75, 75, tan);

    s.draw_rect(0, 300, 75, 75, tan);
    s.draw_rect(150, 300, 75, 75, tan);
    s.draw_rect(300, 300, 75, 75, tan);
    s.draw_rect(450, 300, 75, 75, tan);

    s.draw_rect(75, 375, 75, 75, tan);
    s.draw_rect(225, 375, 75, 75, tan);
    s.draw_rect(375, 375, 75, 75, tan);
    s.draw_rect(525, 375, 75, 75, tan);

    s.draw_rect(0, 450, 75, 75, tan);
    s.draw_rect(150, 450, 75, 75, tan);
    s.draw_rect(300, 450, 75, 75, tan);
    s.draw_rect(450, 450, 75, 75, tan);

    s.draw_rect(75, 525, 75, 75, tan);
    s.draw_rect(225, 525, 75, 75, tan);
    s.draw_rect(375, 525, 75, 75, tan);
    s.draw_rect(525, 525, 75, 75, tan);

    s.draw_rect(150, 600, 75, 75, tan);
    s.draw_rect(300, 600, 75, 75, tan);
    s.draw_rect(450, 600, 75, 75, tan);
    s.draw_rect(600, 600, 75, 75, tan);

    s.draw_string("8", 5, 0, green);
    s.draw_string("7", 5, 75, tan);
    s.draw_string("6", 5, 150, green);
    s.draw_string("5", 5, 225, tan);
    s.draw_string("4", 5, 300, green);
    s.draw_string("3", 5, 375, tan);
    s.draw_string("2", 5, 450, green);
    s.draw_string("1", 5, 525, tan);

    s.draw_string("h", 585, 575, green);
    s.draw_string("g", 510, 575, tan);
    s.draw_string("f", 435, 575, green);
    s.draw_string("e", 360, 575, tan);
    s.draw_string("d", 285, 575, green);
    s.draw_string("c", 210, 575, tan);
    s.draw_string("b", 135, 575, green);
    s.draw_string("a", 60, 575, tan);

    s.add_img("bR", "pieces/br.png");
    s.add_img("bN", "pieces/bkn.png");
    s.add_img("bB", "pieces/bb.png");
    s.add_img("bK", "pieces/bk.png");
    s.add_img("bQ", "pieces/bq.png");
    s.add_img("bP", "pieces/bp.png");

    s.add_img("wR", "pieces/wr.png");
    s.add_img("wN", "pieces/wkn.png");
    s.add_img("wB", "pieces/wb.png");
    s.add_img("wK", "pieces/wk.png");
    s.add_img("wQ", "pieces/wq.png");
    s.add_img("wP", "pieces/wp.png");
    
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if (textScreen->getState(i,j) == "bR") {
                s.draw_img("bR", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "bN") {
                s.draw_img("bN", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "bB") {
                s.draw_img("bB", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "bK") {
                s.draw_img("bK", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "bQ") {
                s.draw_img("bQ", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "bP") {
                s.draw_img("bP", j*75+5, i*75+5);
            }

            if (textScreen->getState(i,j) == "wR") {
                s.draw_img("wR", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "wN") {
                s.draw_img("wN", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "wB") {
                s.draw_img("wB", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "wK") {
                s.draw_img("wK", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "wQ") {
                s.draw_img("wQ", j*75+5, i*75+5);
            }
            if (textScreen->getState(i,j) == "wP") {
                s.draw_img("wP", j*75+5, i*75+5);
            }
        }
    }

    s.update();
}

Game::~Game(){
    delete board;
}