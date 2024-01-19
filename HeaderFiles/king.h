#ifndef KING
#define KING

#include "ChessConstans.h"
#include "piece.h"

class Game;
class KingPiece : public Piece{
    private:

    public:
        KingPiece(PieceType type, Color color, char row, char col, bool first_move = false);

        set<pair<char, char>> get_valid_moves(Board* board, char row, char col, Game* game, string last_move = "") override;
};


#endif // KING