#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/bishop.h"

BishopPiece::BishopPiece(PieceType type, Color color, char row, char col) : Piece(type, color, row, col){
    set_max_moves(8);
    set_dx({1, 1, -1, -1});
    set_dy({1, -1, 1, -1});
}


