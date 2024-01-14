#ifndef GAME
#define GAME

#include "board.h"

class Game{
    private:
        Board *board;

    public:
        Game();
        void play();
};


#endif // GAME