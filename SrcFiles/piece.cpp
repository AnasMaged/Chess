#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/board.h" 
#include "../HeaderFiles/square.h"
#include "../HeaderFiles/game.h"

Piece::Piece(){}

Piece::Piece(PieceType type, Color color, char row, char col, bool first_move) 
            : type(type), color(color), row(row), col(col), first_move(first_move) {

            
            }

PieceType Piece::getType(){
    return this->type;
}

Color Piece::getColor(){
    return this->color;
}

void Piece::setPosition(char row, char col){
    this->row = row;
    this->col = col;
}

pair<char , char> Piece::getPosition(){
    return make_pair(this->row, this->col);
}


void Piece::set_max_moves(int max_moves){
    this->max_moves = max_moves;
}

void Piece::set_dx(vector<int> dx){
    this->dx = dx;
}

void Piece::set_dy(vector<int> dy){
    this->dy = dy;
}

vector<int> Piece::get_dx(){
    return this->dx;
}

vector<int> Piece::get_dy(){
    return this->dy;
}

bool Piece::get_first_move(){
    return this->first_move;
}

int Piece::get_max_moves(){
    int max_count_of_moves = this->max_moves;
    return max_count_of_moves;
}

void Piece::set_check(bool check){
    this->checked = check;
}

bool Piece::is_checked(){
    return this->checked;
}

set<pair<char, char>> Piece::get_valid_moves(Board* board, char row, char col, Game* game, string last_move){
    set<pair<char, char>> valid_moves;
    vector<vector<Square*>> current_board = board->get_board();
    auto [i , j] = get_positions_in_array(row, col);

    for(int k = 0; k < (int)this->dx.size(); k++){
        int x = i + dx[k] , y = j + dy[k] , max_count_of_moves = get_max_moves();
        
        while(valid(x, y) && max_count_of_moves > 0){
            max_count_of_moves--;
            if(current_board[x][y]->getPiece() != nullptr){
                Color original_piece = current_board[i][j]->getPiece()->getColor();
                Color attacked_piece = current_board[x][y]->getPiece()->getColor();
                if(original_piece != attacked_piece){
                    valid_moves.insert(get_positions_on_board(x , y));
                }
                break;
            }
            valid_moves.insert(get_positions_on_board(x , y));
            x += dx[k];
            y += dy[k];
        } 
    }

    
    return valid_moves;
}
