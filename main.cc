#include <iostream>
#include "game.h"
#include "human.h"

using namespace std;

int main(){
    cin.exceptions(ios::eofbit|ios::failbit);
    float whiteWins = 0;
    float blackWins = 0;

    cout << "Welcome to Chess!" << endl;

    string cmd;
    Game *g = nullptr;
    char p1, p2;
    bool playersInitialized = false;

    try{
        while (true) {
            cin >> cmd;
            if(cmd == "game"){
                if(g == nullptr){
                    cout << "Setup must be done first" << endl;
                }
                else{
                    cin >> p1;
                    cin >> p2;
                    if(!((p1 == 'h' || p1 == '1'|| p1 == '2'|| p1 == '3'|| p1 == '4' || p1 == '5') && 
                        (p2 == 'h' || p2 == '1'|| p2 == '2'|| p2 == '3'|| p2 == '4' || p2 == '5'))){
                        cout << "Invalid Game Initilization" << endl;
                    }
                    else{
                        g->initPlayers(p1,p2);
                        playersInitialized = true;
                    }
                }
            }
            else if(cmd == "resign"){
                if(g != nullptr && playersInitialized){
                    if (g->currTurn() == 'b') {
                        whiteWins += 1;
                        cout << "White wins! Enter anything to continue" << endl;
                    } else {
                        blackWins += 1;
                        cout << "Black wins! Enter anything to continue" << endl;
                    }
                    string temp;
                    cin >> temp;
                    delete g;
                    g = nullptr;
                    playersInitialized = false;
                }
                else{
                    cout << "No active game" << endl;
                }
            }
            else if(cmd == "move"){
                if(g != nullptr){
                    g->makeMove();
                    if (g->gameEnded()) {
                        if (g->getWinner() == 'w') {
                            whiteWins += 1;
                            cout << "White wins! Enter anything to continue" << endl;
                        }
                        else if(g->getWinner() == 'b'){
                            blackWins += 1;
                            cout << "Black wins! Enter anything to continue" << endl;
                        }
                        else{
                            whiteWins += 0.5;
                            blackWins += 0.5;
                            cout << "Draw! Enter anything to continue" << endl;
                        }
                        string temp;
                        cin >> temp;
                        delete g;
                        g = nullptr;
                        playersInitialized = false;
                    }
                }
                else{
                    cout << "No active game" << endl;
                }
            }
            else if(cmd == "setup"){
                if(g != nullptr){
                    cout << "Game in Progress, setup not possible" << endl;
                }
                else{
                    g = new Game();
                    while (cin >> cmd){
                        if(cmd == "+"){
                            string name;
                            char col;
                            char row;
                            cin >> name >> col >> row;
                            int colInt = col - 'a';
                            int rowInt = 7 - (row - '1');
                            if(!(colInt >= 0 && colInt < 8 && rowInt >= 0 && rowInt < 8)){
                                cout << "Invalid location" << endl;
                            }
                            else{
                                g->setPiece(rowInt, colInt, name);
                            }
                            g->drawScreen();
                        }
                        else if(cmd == "-"){
                            char col;
                            char row;
                            cin >> col >> row;
                            int colInt = col - 'a';
                            int rowInt = 7 - (row - '1');
                            if(!(colInt >= 0 && colInt < 8 && rowInt >= 0 && rowInt < 8)){
                                cout << "Invalid location" << endl;
                            }
                            else{
                                g->removePiece(rowInt, colInt);
                            }
                            g->drawScreen();
                        }
                        else if(cmd == "="){
                            char color;
                            cin >> color;
                            if((color == 'w' || color == 'b')){
                                g->setTurn(color);
                            }
                            else{
                                cout << "Invalid color" << endl;
                            }
                            g->drawScreen();
                        }
                        else if(cmd == "done"){
                            if(g->boardIsValid()){
                                if(g->gameEnded()){
                                    if (g->getWinner() == 'w') {
                                        whiteWins += 1;
                                        cout << "White wins! Enter anything to continue" << endl;
                                    }
                                    else if(g->getWinner() == 'b'){
                                        blackWins += 1;
                                        cout << "Black wins! Enter anything to continue" << endl;
                                    }
                                    else{
                                        whiteWins += 0.5;
                                        blackWins += 0.5;
                                        cout << "Draw! Enter anything to continue" << endl;
                                    }
                                    string temp;
                                    cin >> temp;
                                    g->initPlayers('h','h');
                                    delete g;
                                    g = nullptr;
                                    playersInitialized = false;
                                }
                                break;
                            }
                            else{
                                cout << "Invalid board" << endl;
                            }
                        }
                        else{
                            cout << "Invalid Setup Command" << endl;
                        }
                    }
                    
                }
                
            }
            else{
                cout << "Invalid Command" << endl;
            }
        }
    }
    catch(ios::failure &){
    }

    if(g != nullptr && playersInitialized){
        delete g;
    }
    else if(g != nullptr && !playersInitialized){
        g->initPlayers('h','h');
        delete g;
    }


    cout << "Scores:" << endl;
    cout << "White: " << whiteWins << endl;
    cout << "Black: " << blackWins << endl;

    return 0;
}