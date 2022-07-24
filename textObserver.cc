#include <string>
#include <vector>
#include "tile.h"
#include "piece.h"
#include "observer.h"
#include "textObserver.h"

using namespace std;

void TextObserver::notify(Tile &subject){
    string state = subject.getState();
    board[subject.getRow()][subject.getCol()] = state;
}