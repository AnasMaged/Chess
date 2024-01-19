#ifndef BISHOP
#define BISHOP

#include "ChessConstans.h"
#include "piece.h"

class BishopPiece : public Piece{
    private:

    public:
        BishopPiece(PieceType type, Color color, char row, char col, bool first_move = false);
};


#endif // BISHOP