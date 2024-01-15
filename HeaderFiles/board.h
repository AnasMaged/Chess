#ifndef BOARD
#define BOARD

#include "ChessConstans.h"

class Square;

class Board{
    private:
        Square* board[8][8];         
        Color turn;
    public:
        Board();
        void display(set<pair<char , char>> attacked = {}, int winner = 0, bool stalemate = false, bool check = false);

    friend class Game;
};


#endif // BOARD