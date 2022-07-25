#ifndef PIECE_H_
#define PIECE_H_

#include <string>
#include <vector>
#include "board.h"
#include "move.h"

class Board;
class Move;


class Piece{
    protected:
        int movesMade;
        int lastMoved;
        char color;
        std::string name;
    public:
        Piece(char color);
        Piece(const Piece &other);
        virtual ~Piece() = 0;

        const std::string getName();
        const char getColor();
        const int getMovesMade();
        const int getLastMoved();
        void appendName(char c);

        virtual std::vector<Move> findMoves(int row, int col, Board *board) = 0;
};


#endif // PIECE_H_