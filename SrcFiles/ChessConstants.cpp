#include "..\HeaderFiles\ChessConstans.h"
#include "..\HeaderFiles\piece.h"
#include "..\HeaderFiles\bishop.h"
#include "..\HeaderFiles\king.h"
#include "..\HeaderFiles\pawn.h"
#include "..\HeaderFiles\knight.h"
#include "..\HeaderFiles\queen.h"
#include "..\HeaderFiles\rook.h"


unordered_map<PieceType, string> mp{
    {Pawn, "Pawn"},
    {Rook, "Rook"},
    {Knight, "Knight"},
    {Bishop, "Bishop"},
    {Queen, "Queen"},
    {King, "King"}
};

unordered_map<int , string> color_anzi_escape{
    {BlackText, "\e[38;5;16m"},
    {WhiteText, "\e[38;5;231m"},
    {RedText, "\e[38;5;160m"},
    {GreenText, "\e[38;5;34m"},
    {YelloText, "\e[38;5;190m"},
    {BlackBackGround, "\e[48;5;94m"},
    {WhiteBackGround, "\e[48;5;222m"},
    {GreenBackGround, "\e[48;5;34m"},
    {RedBackGround, "\e[48;5;160m"},
    {default_color, "\e[0m"}
};

bool valid(int i , int j){
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}


pair<char , char> get_positions_on_board(int row, int col){
    char x = (char)(7 - row + '1');
    char y = (char)(col + 'a');
    return make_pair(x , y);
}

pair<int , int> get_positions_in_array(char row, char col){
    int x = 7 - (row - '1');
    int y = col - 'a';
    return make_pair(x , y);
}

Piece *make_new_peice(Piece* piece, char row, char col, bool first_move){
    Piece *new_piece = nullptr;

    if(piece->getType() == Knight){
        new_piece = new KnightPiece(piece->getType(), piece->getColor(), row, col, first_move);
    }

    if(piece->getType() == Pawn){
        new_piece = new PawnPiece(piece->getType(), piece->getColor(), row, col, first_move);
    }
    
    if(piece->getType() == Bishop){
        new_piece = new BishopPiece(piece->getType(), piece->getColor(), row, col, first_move);
    }

    if(piece->getType() == King){
        new_piece = new KingPiece(piece->getType(), piece->getColor(), row, col, first_move);
    }

    if(piece->getType() == Queen){
        new_piece = new QueenPiece(piece->getType(), piece->getColor(), row, col, first_move);
    }

    if(piece->getType() == Rook){
        new_piece = new RookPiece(piece->getType(), piece->getColor(), row, col, first_move);
    }


    return new_piece;
}


char topLeft = '\xc9';
char topRight = '\xbB';
char bottomLeft = '\xc8';
char bottomRight = '\xbC';
char horizontal_line = '\xcD';
char vertical_line = '\xbA';
