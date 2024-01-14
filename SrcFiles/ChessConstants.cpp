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