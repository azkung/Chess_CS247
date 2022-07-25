#include <iostream>
#include "game.h"

using namespace std;

int main(){
    Game* g = new Game();

    while(true){
        g->makeMove();
    }

    delete g;

    return 0;
}