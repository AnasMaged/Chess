#ifndef KNIGHT
#define KNIGHT

#include "ChessConstans.h"
#include "piece.h"

class KnightPiece : public Piece{
    private:

    public:
        KnightPiece(PieceType type, Color color, char row, char col);
};


#endif // KNIGHT