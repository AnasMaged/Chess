#include "..\HeaderFiles\ChessConstans.h"


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

char topLeft = '\xc9';
char topRight = '\xbB';
char bottomLeft = '\xc8';
char bottomRight = '\xbC';
char horizontal_line = '\xcD';
char vertical_line = '\xbA';
