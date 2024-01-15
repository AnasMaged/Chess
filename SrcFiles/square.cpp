#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/square.h"

Square::Square(Color color, Piece* piece) : color(color), piece(piece){}

Color Square::getColor(){
    return this->color;
}

void Square::setPiece(Piece* piece){
    this->piece = piece;
}

void Square::deletePiece(){
    delete this->piece;
    this->piece = nullptr;
}

Piece* Square::getPiece() const{
    return this->piece;
}
