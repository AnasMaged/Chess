#pragma once

#ifndef CHESS_CONSTANTS
#define CHESS_CONSTANTS

#include <unordered_map>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <windows.h>

using namespace std;

enum PieceType{
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};

extern unordered_map<PieceType, string> mp;

enum Color{
    White,
    Black
};

enum Style{
    BlackBackGround_BlackText = 128,
    BlackBackGround_WhiteText = 143,
    WhiteBackGround_BlackText = 96,
    WhiteBackGround_WhiteText = 111,
    default_color=7
};

bool valid(int i , int j);


#endif // CHESS_CONSTANTS