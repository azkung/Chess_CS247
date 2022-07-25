#ifndef PIECE_H_
#define PIECE_H_

#include <string>

class Piece{
        int movesMade;
        int lastMoved;
        char color;
        std::string name;
    public:
        Piece(char color);
        virtual ~Piece() = 0;

        const std::string getName();
        const int getMovesMade();
        const int getLastMoved();
        void appendName(char c);
};


#endif // PIECE_H_