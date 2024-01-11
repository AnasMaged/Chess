#ifndef PIECE
#define PIECE

#include <iostream>
#include <string.h>
#include "ChessConstans.h"

using namespace std;


class Piece{
    private:
        PieceType type;
        Color color;
        char row, col;
    public:
        Piece(PieceType type, Color color, char row, char col);

        PieceType getType();
        
        Color getColor();

        void setPosition(char row, char col);

};


#endif // PIECE