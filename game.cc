#include "game.h"
#include "board.h"
#include <iostream>
#include "textObserver.h"
#include <vector>

using namespace std;

SDL_Runner g;

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
    drawScreen();

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

    s.update();
}


void Game::makeMove(){


    cout << "Enter a move: ";
    char col1, col2, row1, row2;
    cin >> col1 >> row1 >> col2 >> row2;
    int col1Int = col1 - 'a';
    int col2Int = col2 - 'a';
    int row1Int = 7 - (row1 - '1');
    int row2Int = 7 - (row2 - '1');

    // cout << col1Int << " " << row1Int << " " << col2Int << " " << row2Int << endl;


    board->move(row1Int, col1Int, row2Int, col2Int);
    textScreen->printBoard();
}

Game::~Game(){
    delete board;
}