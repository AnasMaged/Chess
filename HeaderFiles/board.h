#ifndef BOARD
#define BOARD

#include "square.h"

class Board{
    private:
        Square* board[8][8];         

    public:
        Board();
        void display();

    friend class Game;
};


#endif // BOARD