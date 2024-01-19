#ifndef PAWN
#define PAWN

#include "ChessConstans.h"
#include "piece.h"

class PawnPiece : public Piece{
    private:
        int first_move;
    public:
        PawnPiece(PieceType type, Color color, char row, char col);

        int get_first_move();

        void set_first_move(int x);
};


#endif // PAWN