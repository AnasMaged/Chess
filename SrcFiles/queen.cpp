#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/queen.h"

QueenPiece::QueenPiece(PieceType type, Color color, char row, char col, bool first_move) : Piece(type, color, row, col, first_move){
    set_max_moves(8);
    set_dx({1, 1, 1, -1, -1, -1, 0 , 0});
    set_dy({1, -1, 0, 1, -1, 0, 1, -1});
}


