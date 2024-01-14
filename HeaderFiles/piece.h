#ifndef PIECE
#define PIECE

class Board;
class Square;

class Piece{
    private:
        PieceType type;
        Color color;
        char row, col;
        vector<int> dx, dy;
        int max_moves;
    public:
        Piece();
        Piece(PieceType type, Color color, char row, char col);
        
        PieceType getType();
        
        Color getColor();

        int get_max_moves();

        void setPosition(char row, char col);
        
        void set_max_moves(int max_moves);

        void set_dx(vector<int> dx);

        void set_dy(vector<int> dy);
        
        set<pair<char, char>> get_valid_moves(Square* board[8][8], char row, char col);
};


#endif // PIECE