#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/king.h"

KingPiece::KingPiece(PieceType type, Color color, char row, char col) : Piece(type, color, row, col){
    set_max_moves(1);
    set_dx({1, 1, 1, -1, -1, -1, 0 ,0});
    set_dy({1, -1, 0, 1, -1, 0, 1, -1});
}


