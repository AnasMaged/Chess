#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/pawn.h"
#include "../HeaderFiles/board.h" 
#include "../HeaderFiles/square.h"



PawnPiece::PawnPiece(PieceType type, Color color, char row, char col, bool first_move) : Piece(type, color, row, col, first_move){
    set_max_moves(1);
    if(color == Black){
        set_dx({1});
    }
    else{
        set_dx({-1});
    }
    set_dy({0});
}


set<pair<char, char>> PawnPiece::get_valid_moves(Board* board, char row, char col, string last_move){
    set<pair<char, char>> valid_moves;
    vector<vector<Square*>> current_board = board->get_board();
    auto [i , j] = get_positions_in_array(row, col);


    vector<int> dx = this->get_dx();
    vector<int> dy = this->get_dy();

    int x = i + dx[0], y = j + dy[0];

    if(valid(x, y) && current_board[x][y]->getPiece() == nullptr){
        valid_moves.insert(get_positions_on_board(x , y));
    }

    y--;
    if(valid(x , y)){
        if(current_board[x][y]->getPiece() != nullptr){
            Color original_piece = current_board[i][j]->getPiece()->getColor();
            Color attacked_piece = current_board[x][y]->getPiece()->getColor();
            if(original_piece != attacked_piece){
                valid_moves.insert(get_positions_on_board(x , y));
            }    
        }

        else if(valid(x - dx[0], y)){
            auto coordinates = get_positions_on_board(x - dx[0], y);

            string en_passent; en_passent += coordinates.second; en_passent += coordinates.first;

            if(current_board[x - dx[0]][y]->getPiece() != nullptr){
                Piece *attacked_piece = current_board[x - dx[0]][y]->getPiece();
                if(en_passent == last_move && attacked_piece->getType() == Pawn && attacked_piece->getColor() != current_board[i][j]->getPiece()->getColor()){
                    valid_moves.insert(get_positions_on_board(x , y));
                }
            }
        }
    }
    y++;

    y++;
    if(valid(x , y)){
        if(current_board[x][y]->getPiece() != nullptr){
            Color original_piece = current_board[i][j]->getPiece()->getColor();
            Color attacked_piece = current_board[x][y]->getPiece()->getColor();
            if(original_piece != attacked_piece){
                valid_moves.insert(get_positions_on_board(x , y));
            }    
        }

        else if(valid(x - dx[0], y)){
            auto coordinates = get_positions_on_board(x - dx[0], y);

            string en_passent; en_passent += coordinates.second; en_passent += coordinates.first;

            if(current_board[x - dx[0]][y]->getPiece() != nullptr){
                Piece *attacked_piece = current_board[x - dx[0]][y]->getPiece();
                if(en_passent == last_move && attacked_piece->getType() == Pawn && attacked_piece->getColor() != current_board[i][j]->getPiece()->getColor()){
                    valid_moves.insert(get_positions_on_board(x , y));
                }
            }
        }
    }
    y--;

    if(current_board[i][j]->getPiece()->get_first_move() == true){
        x += dx[0];
        if(valid(x, y) && current_board[x][y]->getPiece() == nullptr){
            valid_moves.insert(get_positions_on_board(x , y));
        }   
    }

    return valid_moves;
}

