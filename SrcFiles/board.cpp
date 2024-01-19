#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/board.h"
#include "../HeaderFiles/square.h"
#include "../HeaderFiles/rook.h"
#include "../HeaderFiles/pawn.h"
#include "../HeaderFiles/king.h"
#include "../HeaderFiles/knight.h"
#include "../HeaderFiles/queen.h"
#include "../HeaderFiles/bishop.h"

void changeColor(int desiredColor) {
    cout << color_anzi_escape[desiredColor];
}
    
Board::Board(vector<vector<Square*>> other){
    board.resize(8, vector<Square*>(8));
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(other[i][j]->getColor());
            
            if(other[i][j]->getPiece() != nullptr){
                Piece* current_piece = other[i][j]->getPiece();
                auto [row, col] = get_positions_on_board(i, j);
                Piece* new_piece = make_new_peice(current_piece, row, col, current_piece->get_first_move());
                board[i][j]->setPiece(new_piece);
            }
        }
    }
}


vector<vector<Square*>> Board::get_board(){
    return this->board;
}

Board::Board() : board(8, vector<Square*>(8)){
    turn = White;

    for(int i = 7 ; i >= 0; i--){
        for(int j = 0; j < 8 ; j++){
            if((i & 1) != (j & 1)){
                board[i][j] = new Square(Black);
            }
            else{
                board[i][j] = new Square(White);
            }

            auto [row , col] = get_positions_on_board(i , j);

            if(i == 7 || i == 0){
                Color color = (i == 0 ? Black: White);
                PieceType type;
                
                if(j == 0 || j == 7){
                    type = Rook;
                    RookPiece* rook = new RookPiece(type, color, row, col, true); 
                    board[i][j]->setPiece(rook);
                }

                if(j == 1 || j == 6){
                    type = Knight;
                    KnightPiece* piece = new KnightPiece(type, color, row, col, true); 
                    board[i][j]->setPiece(piece);
                }

                if(j == 2 || j == 5){
                    type = Bishop;
                    BishopPiece* piece = new BishopPiece(type, color, row, col, true); 
                    board[i][j]->setPiece(piece);
                }

                if(j == 3){
                    type = Queen;
                    QueenPiece* piece = new QueenPiece(type, color, row, col, true); 
                    board[i][j]->setPiece(piece);
                }

                if(j == 4){
                    type = King;
                    KingPiece* piece = new KingPiece(type, color, row, col, true); 
                    board[i][j]->setPiece(piece);
                }

            }

            if(i == 6 || i == 1){
                Color color = (i == 6 ? White: Black);
                PawnPiece* piece = new PawnPiece(Pawn, color, row, col, true); 
                board[i][j]->setPiece(piece);
            }
            
        }
    }
}

string setw(int x){
    string spaces;
    while(x--) spaces += ' ';
    return spaces;
}

void PrintDefualtLine(int i, bool down = 0){
    changeColor(default_color);
    cout << setw(11); 
    for(int j = 0 ; j < 8 ; j++){
        if((i & 1) != (j & 1)){
            changeColor(BlackBackGround);
        }       
        else{
            changeColor(WhiteBackGround);
        }
        cout << setw(11);
    }
    changeColor(default_color);

    if(i == 3 || i == 4){
        if((i == 3 && down == 0) || (i == 4 && down == 1)){
            
            if(i == 3){
                cout << topLeft;
            }
            else{
                cout << bottomLeft;
            }

            cout << string(15 , horizontal_line);

            if(i == 3){
                cout << topRight;
            }
            else{
                cout << bottomRight;
            }
        }
        else{
            cout << vertical_line;
            cout << setw(15);
            cout << vertical_line;
        }
    }
    cout << "\n";
}

void handle_spaces(string message, int spaces_count, Style text_color){
    int length = (int)message.size();
    changeColor(default_color);
    int before = (spaces_count - length) / 2;
    int after = spaces_count - length - before;
    cout << setw(before);
    changeColor(text_color);
    cout << message;
    changeColor(default_color);
    cout << setw(after);
}
void Board::display(set<pair<char , char>> attacked, int winner, bool stalemate, bool check){

    for(int i = 0 ; i < 8 ; i++){
        PrintDefualtLine(i);   
        changeColor(default_color);
        cout << setw(5) << 8 - i << setw(5);    
        for(int j = 0 ; j < 8 ; j++){
            Piece* piece = board[i][j]->getPiece();
            
            Style square_color;
            if(board[i][j]->getColor() == Black){
                square_color = BlackBackGround;
            }
            else{
                square_color = WhiteBackGround;
            }

            changeColor(square_color);

            if(piece != nullptr){
                if(piece->getColor() == White){
                    changeColor(WhiteText);
                }
                else{
                    changeColor(BlackText);
                }
                int length;

                if(piece->getType() == Rook || piece->getType() == King || piece->getType() == Pawn){
                    length = 4;
                }

                if(piece->getType() == Knight || piece->getType() == Bishop){
                    length = 6;
                }
                if(piece->getType() == Queen){
                    length = 5;
                }

                cout << setw((11 - length) / 2);
                
                pair<char , char> current_position = get_positions_on_board(i , j);
                if(attacked.count(current_position)){
                    changeColor(RedBackGround);
                }

                cout << mp[piece->getType()];
                
                changeColor(square_color);

                cout << setw(11 - length - (11 - length) / 2);
            }
            else{
                pair<char , char> current_position = get_positions_on_board(i , j);
                if(attacked.count(current_position)){
                    cout << setw(3);
                    changeColor(GreenBackGround);
                    cout << setw(5);
                    changeColor(square_color);
                    cout << setw(3);
                }
                else{
                    cout << setw(11);
                }
            }
        }
        changeColor(default_color);
        if(i >= 3 && i <= 4){
            cout << vertical_line;
            if(i == 3){
                if(winner != 0){
                    string message = "Checkmate!";
                    Style text_color = RedText; 

                    handle_spaces(message, 15, text_color); 
                }

                else if(stalemate == true){
                    string message = "Stalemate!";
                    Style text_color = RedText; 
                    
                    handle_spaces(message, 15, text_color); 
                }

                else{
                    string message = "White to play";
                    Style text_color = YelloText;

                    if(turn == Black){
                        message = "Black to play";
                    }

                    handle_spaces(message, 15, text_color);
                }
            }   

            if(i == 4){
                
                if(winner != 0){
                    Color winner_color = (winner == 1 ? White : Black);
                    
                    string message = "White Wins!";
                    Style text_color = GreenText;
                    
                    if(winner_color == Black){
                        message = "Black Wins";
                    }
                    
                    handle_spaces(message, 15, text_color); 
                }   

                else if(stalemate == true){
                    string message = "Draw!";
                    Style text_color = YelloText;
                    
                    handle_spaces(message, 15, text_color); 
                }

                else if(check == true){
                    string message = "Check!";
                    Style text_color = RedText;
                    
                    handle_spaces(message, 15, text_color); 
                }

                else{
                    changeColor(default_color);
                    cout << setw(15);
                }
            }   

            changeColor(default_color);
            cout << vertical_line;
        }
        cout << "\n";
        PrintDefualtLine(i , 1);
    }

    changeColor(default_color);
    cout << '\n';
    cout << setw(11);
    for(int i = 0 ; i < 8 ; i++){
        cout << setw(5);
        cout << (char)(i + 'a');
        cout << setw(5);
    }
    cout << "\n";
}