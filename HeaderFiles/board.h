#ifndef BOARD
#define BOARD

class Square;

class Board{
    private:
        Square* board[8][8];         

    public:
        Board();
        void display(set<pair<char , char>> attacked);

    friend class Game;
};


#endif // BOARD