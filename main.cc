#include <iostream>
#include "game.h"
#include "human.h"

using namespace std;

int main(){

    int whiteWins = 0;
    int blackWins = 0;

    cout << "Welcome to Chess!" << endl;

    string cmd, p1, p2;
    cin >> cmd;
    if (cmd == "game") {
        cin >> p1 >> p2;

        Game* g = new Game();

        while(true){
            cin >> cmd; 

            if (cmd == "resign") {
                if (g->currTurn() == 'b') {
                    whiteWins++;
                    cout << "White wins!" << endl;
                } else {
                    blackWins++;
                    cout << "Black wins!" << endl;
                }

                cout << "Play again? [Yes] or [No]" << endl;
                cin >> cmd;
                
                if (cmd == "No") {
                    break;
                } else if (cmd == "Yes") {
                    delete g;
                    g = new Game();
                } else {
                    cout << "Invalid command" << endl;
                }
            }

            if (cmd == "move") {
                g->makeMove();
                if (g->gameEnded()) {
                    g->makeMove();
                    cout << "Play again? [Yes] or [No]" << endl;
                    cin >> cmd;

                    if (cmd == "No") {
                        if (g->getWinner()) {
                            whiteWins++;
                        } else {
                            blackWins++;
                        }
                        break;
                    } else if (cmd == "Yes") {
                        if (g->getWinner()) {
                            whiteWins++;
                        } else {
                            blackWins++;
                        }
                        delete g;
                        g = new Game();
                    } else {
                        cout << "Invalid command" << endl;
                    }
                }
            }
        }
        delete g;
    }

    cout << "Scores:" << endl;
    cout << "White: " << whiteWins << endl;
    cout << "Black: " << blackWins << endl;

    return 0;
}