#ifndef PAWN
#define PAWN

#include "ChessConstans.h"
#include "piece.h"

class PawnPiece : public Piece{
    private:

    public:
        PawnPiece(PieceType type, Color color, char row, char col);
};


#endif // PAWN