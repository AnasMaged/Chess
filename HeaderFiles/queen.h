#ifndef QUEEN
#define QUEEN

#include "ChessConstans.h"
#include "piece.h"

class QueenPiece : public Piece{
    private:

    public:
        QueenPiece(PieceType type, Color color, char row, char col);
};


#endif // QUEEN