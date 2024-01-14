#include "..\HeaderFiles\ChessConstans.h"
#include "..\HeaderFiles\board.h"
#include "..\HeaderFiles\game.h"

Game::Game(){
    this->board = new Board();
}

void Game::play(){
    board->display(); 
}