#ifndef PAWN
#define PAWN

#include "ChessConstans.h"
#include "piece.h"

class PawnPiece : public Piece{
    private:
   
    public:
        PawnPiece(PieceType type, Color color, char row, char col, bool first_move = false);

        set<pair<char, char>> get_valid_moves(Board* board, char row, char col, string last_move = "") override;
};


#endif // PAWN