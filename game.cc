#include "game.h"
#include "board.h"
#include <iostream>

using namespace std;

Game::Game(){
    board = new Board();
}


void Game::play(){
    while(true){
        cout << "Enter a move: ";
        string move;
        cin >> move;
        if(move == "q"){
            break;
        }
    }
}