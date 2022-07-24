#ifndef PIECE_H_
#define PIECE_H_

#include <string>

class Piece{
        int movesMade;
        char color;
        std::string name;
    public:
        Piece(char color);
        virtual ~Piece() = 0;

        std::string getName();
        int getMovesMade();
        void appendName(char c);
};


#endif // PIECE_H_