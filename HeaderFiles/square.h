#ifndef SQUARE
#define SQUARE

#include "piece.h"
#include "ChessConstans.h"

class Square {
    private:
        Color color;
        Piece* piece;

    public:
        Square(Color color, Piece* piece = nullptr);

        void setPiece(Piece* piece);

        Color getColor();

        Piece* getPiece() const;

};



#endif // SQUARE   

