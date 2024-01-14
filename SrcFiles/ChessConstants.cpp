#include "..\HeaderFiles\ChessConstans.h"


unordered_map<PieceType, string> mp{
    {Pawn, "Pawn"},
    {Rook, "Rook"},
    {Knight, "Knight"},
    {Bishop, "Bishop"},
    {Queen, "Queen"},
    {King, "King"}
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
