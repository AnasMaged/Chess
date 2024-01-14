#ifndef GAME
#define GAME

class Board;
class Piece;

class Game{
    private:
        Board *board;
        vector<Piece*> WhitePieces;
        vector<Piece*> BlackPieces;
    public:
        Game();
        
        void play();
        
        vector<Piece*> get_white_pieces();
        
        vector<Piece*> get_black_pieces();
};


#endif // GAME