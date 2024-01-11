#include "..\HeaderFiles\ChessConstans.h"

#include <unordered_map>
#include <iostream>
#include <string.h>

using namespace std;

unordered_map<PieceType, string> mp{
    {Pawn, "Pawn"},
    {Rook, "Rook"},
    {Knight, "Knight"},
    {Bishop, "Bishop"},
    {Queen, "Queen"},
    {King, "King"}
};
