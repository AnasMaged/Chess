#ifndef SQUARE
#define SQUARE

class Piece;

class Square {
    private:
        Color color;
        Piece* piece;

    public:
        Square(Color color, Piece* piece = nullptr);

        void setPiece(Piece* piece);

        void deletePiece();
        
        Color getColor();

        Piece* getPiece() const;
        
};



#endif // SQUARE   

