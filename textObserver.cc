#include <string>
#include <vector>
#include "tile.h"
#include "piece.h"
#include "observer.h"
#include "textObserver.h"

void textObserver::notify(Tile &subject){
    subject.getState();
}