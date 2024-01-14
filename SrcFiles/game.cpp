#include "..\HeaderFiles\ChessConstans.h"
#include "..\HeaderFiles\board.h"
#include "..\HeaderFiles\game.h" 
#include "..\HeaderFiles\square.h" 
#include "..\HeaderFiles\piece.h"

Game::Game(){
    this->board = new Board();
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(board->board[i][j]->getPiece() != nullptr){
                Piece *p = board->board[i][j]->getPiece();
                if(p->getColor() == Black){
                    BlackPieces.emplace_back(p);
                }
                else{
                    WhitePieces.emplace_back(p);
                }
            }
        }
    }
}

vector<Piece*> Game::get_black_pieces(){
    return BlackPieces;
}

vector<Piece*> Game::get_white_pieces(){
    return WhitePieces;
}

void Game::play(){
    while(true){
        board->display({}); 
        cout << "Enter the position of the piece you want to move: ";
        char row, col; cin >> col >> row;
        int i = 7 - (row - '1'), j = col - 'a';
        auto valid_moves = board->board[i][j]->getPiece()->get_valid_moves(board->board, row, col);
        board->display(valid_moves);
        Sleep(5000);
        break;
    }
}