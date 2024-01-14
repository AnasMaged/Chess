#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/board.h"

Piece::Piece(){}

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


void Piece::set_max_moves(int max_moves){
    this->max_moves = max_moves;
}

void Piece::set_dx(vector<int> dx){
    this->dx = dx;
}

void Piece::set_dy(vector<int> dy){
    this->dy = dy;
}

set<pair<char, char>> Piece::get_valid_moves(Board* board, char row, char col){
    set<pair<char, char>> valid_moves;
    int i = row - 'a', j = col - '1';
    for(int k = 0; k < (int)this->dx.size(); k++){
        int x = i , y = j;
        while(valid(x, y)){
            valid_moves.insert(make_pair((char)(x + 'a'), (char)(y + '1')));
            x += dx[k];
            y += dy[k];
        }
    }
    return valid_moves;
}
