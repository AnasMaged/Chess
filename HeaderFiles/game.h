#ifndef GAME
#define GAME

class Board;
class Piece;

class Game{
    private:
        Board *board;
        vector<Piece*> WhitePieces;
        vector<Piece*> BlackPieces;
        string last_move;
    public:
        Game();
        
        void play();
        
        vector<Piece*> get_white_pieces();
        
        vector<Piece*> get_black_pieces();  

        void delete_piece_from_vector(Color color, Piece *piece);

        void insert_piece_in_vector(Color color, Piece *piece);

        bool is_check(Board* board, vector<Piece*> other_player_pieces, Color player_color);

        bool is_stalemate(Board* board, vector<Piece*> player_pieces);

        Board* copy_and_move(Board* board, pair<int, int> from, pair<int , int> to);

        void move(Board* board, pair<int , int> from, pair<int , int> to);

        string get_last_move();

        void set_last_move(string s);
        
        set<pair<char, char>> review(set<pair<char, char>> valid_moves, pair<int , int> from);
};


#endif // GAME