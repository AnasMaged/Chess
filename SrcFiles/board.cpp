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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

Board::Board(){
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
                    RookPiece* rook = new RookPiece(type, color, row, col); 
                    board[i][j]->setPiece(rook);
                }

                if(j == 1 || j == 6){
                    type = Knight;
                    KnightPiece* piece = new KnightPiece(type, color, row, col); 
                    board[i][j]->setPiece(piece);
                }

                if(j == 2 || j == 5){
                    type = Bishop;
                    BishopPiece* piece = new BishopPiece(type, color, row, col); 
                    board[i][j]->setPiece(piece);
                }

                if(j == 3){
                    type = Queen;
                    QueenPiece* piece = new QueenPiece(type, color, row, col); 
                    board[i][j]->setPiece(piece);
                }

                if(j == 4){
                    type = King;
                    KingPiece* piece = new KingPiece(type, color, row, col); 
                    board[i][j]->setPiece(piece);
                }

            }

            if(i == 6 || i == 1){
                Color color = (i == 6 ? White: Black);
                PawnPiece* piece = new PawnPiece(Pawn, color, row, col); 
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

void PrintDefualtLine(int i){
    changeColor(default_color);
    cout << setw(11); 
    for(int j = 0 ; j < 8 ; j++){
        if((i & 1) != (j & 1)){
            changeColor(BlackBackGround_BlackText);
        }       
        else{
            changeColor(WhiteBackGround_BlackText);
        }
        cout << setw(11);
    }
    changeColor(default_color);
    cout << "\n";
}
void Board::display(set<pair<char , char>> attacked = {}){

    for(int i = 0 ; i < 8 ; i++){
        PrintDefualtLine(i);   
        changeColor(default_color);
        cout << setw(5) << 8 - i << setw(5);    
        for(int j = 0 ; j < 8 ; j++){
            Piece* piece = board[i][j]->getPiece();
            
            Style style = (board[i][j]->getColor() == Black ? BlackBackGround_BlackText: WhiteBackGround_BlackText);

            if(piece != nullptr){
                if(piece->getColor() == White){
                    if(board[i][j]->getColor() == Black){
                        style = BlackBackGround_WhiteText;
                    }
                    else{
                        style = WhiteBackGround_WhiteText;
                    }
                }
                changeColor(style);
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
                    if(piece->getColor() == Black){
                        changeColor(RedBackGround_BlackText);
                    }
                    else{
                        changeColor(RedBackGround_WhiteText);
                    }
                }

                cout << mp[piece->getType()];
                
                changeColor(style);
                cout << setw(11 - length - (11 - length) / 2);
            }
            else{
                changeColor(style);
                pair<char , char> current_position = get_positions_on_board(i , j);
                if(attacked.count(current_position)){
                    cout << setw(3);
                    changeColor(GreedBackGround);
                    cout << setw(5);
                    changeColor(style);
                    cout << setw(3);
                }
                else{
                    cout << setw(11);
                }
            }
        }
        changeColor(default_color);
        cout << "\n";
        PrintDefualtLine(i);
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