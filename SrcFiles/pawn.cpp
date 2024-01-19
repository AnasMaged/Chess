#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/pawn.h"

PawnPiece::PawnPiece(PieceType type, Color color, char row, char col) : Piece(type, color, row, col){
    set_max_moves(1);
    if(color == Black){
        set_dx({1});
    }
    else{
        set_dx({-1});
    }
    set_dy({0});
    first_move = -1;
}

int PawnPiece::get_first_move(){
    return this->first_move;
}

void PawnPiece::set_first_move(int x){
    this->first_move = x;
    return;
}


