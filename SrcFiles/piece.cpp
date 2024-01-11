#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/ChessConstans.h"

Piece::Piece(PieceType type, Color color, char row, char col) 
            : type(type), color(color), row(row), col(col) {}

PieceType Piece::getType(){
    return this->type;
}

Color Piece::getColor(){
    return this->color;
}

void Piece::setPosition(char row, char col){
    this->row = row;
    this->col = col;
}


