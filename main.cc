#include <iostream>
#include "game.h"
#include "human.h"

using namespace std;

int main(){
    Human white{'w'};
    Human black{'b'};

    cout << "Welcome to Chess!" << endl;

    string cmd, p1, p2;
    cin >> cmd;
    if (cmd == "game") {
        cin >> p1 >> p2;

        Game* g = new Game();

        while(true){
            if (!(g->makeMove())) {
                if (g->getWinner()) {
                    white.addWin();
                } else {
                    black.addWin();
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
        }
        delete g;
    }

    cout << "Scores:" << endl;
    cout << "White: " << white.getScore() << endl;
    cout << "Black: " << black.getScore() << endl;

    return 0;
}