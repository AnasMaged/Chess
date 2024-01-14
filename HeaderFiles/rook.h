#ifndef ROOK
#define ROOK

#include "ChessConstans.h"
#include "piece.h"

class RookPiece : public Piece{
    private:

    public:
        RookPiece(PieceType type, Color color, char row, char col);
};


#endif // ROOK