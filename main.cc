#include <iostream>
#include "game.h"
#include "human.h"

using namespace std;

int main(){
    cin.exceptions(ios::eofbit|ios::failbit);
    int whiteWins = 0;
    int blackWins = 0;

    cout << "Welcome to Chess!" << endl;

    string cmd;
    Game *g = nullptr;
    char p1, p2;

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
                    if(!((p1 == 'h' || p1 == '1'|| p1 == '2'|| p1 == '3'|| p1 == '3') && (p2 == 'h' || p2 == '1'|| p2 == '2'|| p2 == '3'|| p2 == '3'))){
                        cout << "Invalid Game Initilization" << endl;
                    }
                    else{
                        g->initPlayers(p1,p2);
                    }
                }
            }
            else if(cmd == "resign"){
                if(g != nullptr){
                    if (g->currTurn() == 'b') {
                        whiteWins++;
                        cout << "White wins!" << endl;
                    } else {
                        blackWins++;
                        cout << "Black wins!" << endl;
                    }
                }
                else{
                    cout << "No active game" << endl;
                }
            }
            else if(cmd == "move"){
                g->makeMove();
                if (g->gameEnded()) {
                    if (g->getWinner()) {
                        whiteWins++;
                    }
                    else {
                        blackWins++;
                    }
                    delete g;
                    g = nullptr;
                }
            }
            else if(cmd == "setup"){
                if(g != nullptr){
                    cout << "Game in Progress, setup not possible" << end;
                }
                else{
                    g = new Game();
                    while (cin >> cmd){
                        if(cmd == "+"){
                            string name;
                            char col;
                            char row;
                            cin >> name >> col >> row;
                            int colInt = col1 - 'a';
                            int rowInt = 7 - (row1 - '1');
                            if(!(colInt >= 0 && colInt < 8 && rowInt >= 0 && rowInt < 8)){
                                cout << "Invalid location" << endl;
                            }
                            else{
                                
                            }
                        }
                        else if(cmd == "-"){
                            char col;
                            char row;
                            cin >> col >> row;
                            int colInt = col1 - 'a';
                            int rowInt = 7 - (row1 - '1');
                            if(!(colInt >= 0 && colInt < 8 && rowInt >= 0 && rowInt < 8)){
                                cout << "Invalid location" << endl;
                            }
                            else{

                            }
                        }
                        else if(cmd == "="){
                            char color;
                            cin >> color;
                            if(!(color == 'w' || color == 'b')){

                            }
                            else{
                                cout << "Not a color" << endl;
                            }
                        }
                        else if(cmd == "done"){

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


    // string cmd;
    // char p1, p2;
    // cin >> cmd;
    // if (cmd == "game") {
    //     while(cin >> p1 >> p2){
    //         if((p1 == 'h' || p1 == '1'|| p1 == '2'|| p1 == '3'|| p1 == '3') && (p2 == 'h' || p2 == '1'|| p2 == '2'|| p2 == '3'|| p2 == '3')){
    //             break;
    //         }
    //         cout << "Invalid Player Intialization" << endl;
    //     }

    //     Game* g = new Game();
    //     g->initPlayers(p1,p2);
    //     while(true){
    //         cin >> cmd; 

    //         if (cmd == "resign") {
    //             if (g->currTurn() == 'b') {
    //                 whiteWins++;
    //                 cout << "White wins!" << endl;
    //             } else {
    //                 blackWins++;
    //                 cout << "Black wins!" << endl;
    //             }

    //             cout << "Play again? [Yes] or [No]" << endl;
    //             cin >> cmd;
                
    //             if (cmd == "No") {
    //                 break;
    //             } else if (cmd == "Yes") {
    //                 delete g;
    //                 g = new Game();
    //             } else {
    //                 cout << "Invalid command" << endl;
    //             }
    //         }

    //         if (cmd == "move") {
    
    //             g->makeMove();
    //             if (g->gameEnded()) {
    //                 g->makeMove();
    //                 cout << "Play again? [Yes] or [No]" << endl;
    //                 cin >> cmd;

    //                 if (cmd == "No") {
    //                     if (g->getWinner()) {
    //                         whiteWins++;
    //                     } else {
    //                         blackWins++;
    //                     }
    //                     break;
    //                 } else if (cmd == "Yes") {
    //                     if (g->getWinner()) {
    //                         whiteWins++;
    //                     } else {
    //                         blackWins++;
    //                     }
    //                     delete g;
    //                     g = new Game();
    //                 } else {
    //                     cout << "Invalid command" << endl;
    //                 }
    //             }
    //         }
    //     }
    //     delete g;
    // }

    cout << "Scores:" << endl;
    cout << "White: " << whiteWins << endl;
    cout << "Black: " << blackWins << endl;

    return 0;
}