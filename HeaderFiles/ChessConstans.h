#pragma once

#ifndef CHESS_CONSTANTS
#define CHESS_CONSTANTS

#include <unordered_map>
#include <iostream>
#include <string.h>

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
    BlackBackGround_WhiteText = 135,
    WhiteBackGround_BlackText = 224,
    WhiteBackGround_WhiteText = 239,
    default_color=7
};

#endif // CHESS_CONSTANTS