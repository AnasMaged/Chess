#include "../HeaderFiles/ChessConstans.h"
#include "../HeaderFiles/piece.h"
#include "../HeaderFiles/king.h"
#include "../HeaderFiles/game.h"
#include "../HeaderFiles/board.h"
#include "../HeaderFiles/square.h"

KingPiece::KingPiece(PieceType type, Color color, char row, char col, bool first_move) : Piece(type, color, row, col, first_move){
    set_max_moves(1);
    set_dx({1, 1, 1, -1, -1, -1, 0 ,0});
    set_dy({1, -1, 0, 1, -1, 0, 1, -1});
}

set<pair<char, char>> KingPiece::get_valid_moves(Board* board, char row, char col, Game* game, string last_move){
    set<pair<char, char>> valid_moves;
    vector<vector<Square*>> current_board = board->get_board();
    auto [i , j] = get_positions_in_array(row, col);

    vector<int> dx = this->get_dx();
    vector<int> dy = this->get_dy();

    for(int k = 0; k < (int)dx.size(); k++){
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

    if(current_board[i][j]->getPiece()->get_first_move() == true && current_board[i][j]->getPiece()->is_checked() == false){
        // short castle
        int rook_row = i, rook_col = 7;
        if(current_board[rook_row][rook_col]->getPiece() != nullptr){
            Piece *rook = current_board[rook_row][rook_col]->getPiece();
            if(rook->getType() == Rook && rook->get_first_move() == true){
                bool clear_path = true;
                int j2 = j + 1;
                vector<Piece*> other_player_pieces = (board->turn == White ? game->get_black_pieces() : game->get_white_pieces());
                Color player_color = (board->turn == White ? White : Black);
    
                while(j2 < rook_col){
                    if(current_board[i][j2]->getPiece() != nullptr){
                        clear_path = false;
                    }
                    if(game->is_check(board, other_player_pieces, player_color, get_positions_on_board(i , j2)) == true){
                        clear_path = false;
                    }
                    j2++;
                }
                
                if(clear_path == true){
                    valid_moves.insert(get_positions_on_board(i, j + 2));
                }
            }
        }

        // long castle
        rook_col = 0;
        if(current_board[rook_row][rook_col]->getPiece() != nullptr){
            Piece *rook = current_board[rook_row][rook_col]->getPiece();
            if(rook->getType() == Rook && rook->get_first_move() == true){
                bool clear_path = true;
                int j2 = j - 1;
                vector<Piece*> other_player_pieces = (board->turn == White ? game->get_black_pieces() : game->get_white_pieces());
                Color player_color = (board->turn == White ? White : Black);
    
                while(j2 > rook_col){
                    if(current_board[i][j2]->getPiece() != nullptr){
                        clear_path = false;
                    }
                    if(game->is_check(board, other_player_pieces, player_color, get_positions_on_board(i , j2)) == true){
                        clear_path = false;
                    }
                    j2--;
                }
                
                if(clear_path == true){
                    valid_moves.insert(get_positions_on_board(i, j - 2));
                }
            }
        }
    }    
    return valid_moves;
}

