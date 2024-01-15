#pragma once

#ifndef CHESS_CONSTANTS
#define CHESS_CONSTANTS

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <unordered_map>
#include <vector>
#include <set>

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

extern unordered_map<int, string> color_anzi_escape;

enum Color{
    White,
    Black
};

enum Style{
    BlackText,
    WhiteText,
    RedText,
    GreenText,
    YelloText,
    BlackBackGround,
    WhiteBackGround,
    GreenBackGround,
    RedBackGround,
    default_color
};

bool valid(int i , int j);

pair<char , char> get_positions_on_board(int row, int col);

pair<int , int> get_positions_in_array(char row, char col);

extern char topLeft;
extern char topRight;
extern char bottomLeft;
extern char bottomRight;
extern char horizontal_line;
extern char vertical_line;
#endif // CHESS_CONSTANTS