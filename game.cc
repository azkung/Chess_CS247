#include "game.h"
#include "board.h"
#include <iostream>

using namespace std;

Game::Game(){
    cout << "Welcome to Chess!" << endl;
    board = new Board();
}


void Game::makeMove(){
    cout << "Enter a move: ";
    string move;
    cin >> move;

}

Game::~Game(){
    delete board;
}