#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/knight.h"

KnightPiece::KnightPiece(PieceType type, Color color, char row, char col, bool first_move) : Piece(type, color, row, col, first_move){
    set_max_moves(1);
    set_dx({2, 2, -2, -2, 1, 1, -1, -1});
    set_dy({1, -1, 1, -1, 2, -2, 2, -2});
}


