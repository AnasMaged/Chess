#include "../HeaderFiles/square.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/ChessConstans.h"

Square::Square(Color color, Piece* piece) : color(color), piece(piece){}

Color Square::getColor(){
    return this->color;
}

void Square::setPiece(Piece* piece){
    this->piece = piece;
}

Piece* Square::getPiece() const{
    return this->piece;
}
