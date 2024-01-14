#ifndef KING
#define KING

#include "ChessConstans.h"
#include "piece.h"

class KingPiece : public Piece{
    private:

    public:
        KingPiece(PieceType type, Color color, char row, char col);
};


#endif // KING