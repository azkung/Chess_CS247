#include "board.h"
#include "tile.h"
#include "piece.h"
#include <vector>

Board::Board(){
    tiles.resize(8);
    for(int i = 0; i < 8; i++){
        tiles[i].resize(8);
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tiles[i][j] = new Tile(i, j, nullptr);
        }
    }
}