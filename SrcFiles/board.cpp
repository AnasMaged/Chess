#include <windows.h>
#include <iostream>

#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/board.h"


void changeColor(int desiredColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

using namespace std;


Board::Board(){
    for(int i = 7 ; i >= 0; i--){
        for(int j = 0; j < 8 ; j++){
            if((i & 1) == (j & 1)){
                board[i][j] = new Square(Black);
            }
            else{
                board[i][j] = new Square(White);
            }

            if(i == 7 || i == 0){
                Color color = (i == 0 ? Black: White);
                PieceType type;
                
                if(j == 0 || j == 7){
                    type = Rook;
                }

                if(j == 1 || j == 6){
                    type = Knight;
                }

                if(j == 2 || j == 5){
                    type = Bishop;
                }

                if(j == 3){
                    type = Queen;
                }

                if(j == 4){
                    type = King;
                }

                

                Piece* piece = new Piece(type, color, (char)(8 - i + '0'), (char)('a' + j)); 
                board[i][j]->setPiece(piece);
            
            }

            if(i == 6 || i == 1){
                Color color = (i == 6 ? White: Black);
                Piece* piece = new Piece(Pawn, color, (char)(8 - i + '0'), (char)('a' + j)); 
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
        if((i & 1) == (j & 1)){
            changeColor(BlackBackGround_BlackText);
        }       
        else{
            changeColor(WhiteBackGround_BlackText);
        }
        cout << setw(11);
    }
    cout << '\n';
}
void Board::display(){

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
                int len = 4;
                if(piece->getType() == Knight || piece->getType() == Bishop){
                    len = 6;
                }
                if(piece->getType() == Queen){
                    len = 5;
                }

                cout << setw((11 - len) / 2);
                cout << mp[piece->getType()];
                cout << setw(11 - len - (11 - len) / 2);
            }
            else{
                changeColor(style);
                cout << setw(11);
            }
        }
        cout << '\n';
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
    cout << '\n';
    Sleep(100000000);
}