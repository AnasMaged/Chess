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

        bool can_move(Board* board, vector<Piece*> other_player_pieces, Color player_color);

        Board* copy_and_move(Board* board, pair<int, int> from, pair<int , int> to);

        void move(Board* board, pair<int , int> from, pair<int , int> to);

        set<pair<char, char>> check(set<pair<char, char>> valid_moves, pair<int , int> from);
};


#endif // GAME