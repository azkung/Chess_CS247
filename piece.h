#ifndef PIECE_H_
#define PIECE_H_

class Piece{
        int movesMade;
        char color;
    public:
        Piece(char color);
        virtual ~Piece() = 0;
        virtual std::string getState() = 0;
};


#endif // PIECE_H_