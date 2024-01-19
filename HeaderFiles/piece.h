#ifndef PIECE
#define PIECE

class Board;
class Square;
class Game;

class Piece{
    private:
        PieceType type;
        Color color;
        char row, col;
        vector<int> dx, dy;
        int max_moves;
        bool first_move;
        bool checked;
    public:
        Piece();

        Piece(PieceType type, Color color, char row, char col, bool first_move = false);

        PieceType getType();
        
        Color getColor();

        int get_max_moves();

        void setPosition(char row, char col);

        pair<char, char> getPosition();
        
        void set_max_moves(int max_moves);

        void set_dx(vector<int> dx);

        void set_dy(vector<int> dy);

        vector<int> get_dx();

        vector<int> get_dy();

        bool get_first_move();

        bool is_checked();

        void set_check(bool check);

        virtual set<pair<char, char>> get_valid_moves(Board* board, char row, char col, Game* game, string last_move = "");
};


#endif // PIECE