#ifndef BOARD
#define BOARD

#include<iostream>
#include "square.h"

using namespace std;

class Board{
    private:
        Square* board[8][8];         

    public:
        Board();
        void display();

};


#endif // BOARD