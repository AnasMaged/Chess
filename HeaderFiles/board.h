#ifndef BOARD
#define BOARD

#include "ChessConstans.h"

class Square;

class Board{
    private:
        vector<vector<Square*>> board;    
        Color turn;
    public:
        Board();

        Board(vector<vector<Square*>> other);

        vector<vector<Square*>> get_board();

        void display(set<pair<char , char>> attacked = {}, int winner = 0, bool stalemate = false, bool check = false);

    friend class Game;
    friend class KingPiece;
};


#endif // BOARD