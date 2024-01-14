#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/pawn.h"

PawnPiece::PawnPiece(PieceType type, Color color, char row, char col) : Piece(type, color, row, col){
    set_max_moves(1);
    set_dx({0});
    set_dy({1});
}


