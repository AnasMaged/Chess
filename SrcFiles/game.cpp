#include "..\HeaderFiles\ChessConstans.h"
#include "..\HeaderFiles\board.h"
#include "..\HeaderFiles\game.h" 
#include "..\HeaderFiles\square.h" 
#include "..\HeaderFiles\piece.h" 
#include "..\HeaderFiles\knight.h"
#include "..\HeaderFiles\pawn.h"
#include "..\HeaderFiles\king.h"
#include "..\HeaderFiles\bishop.h"
#include "..\HeaderFiles\king.h"
#include "..\HeaderFiles\rook.h"
#include "..\HeaderFiles\queen.h"


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

void Game::delete_piece_from_vector(Color color, Piece *piece) {
    vector<Piece*>& pieces = (color == White ? WhitePieces : BlackPieces);

    auto it = find(pieces.begin(), pieces.end(), piece);

    pieces.erase(it);
}

void Game::insert_piece_in_vector(Color color, Piece *piece) {
    vector<Piece*>& pieces = (color == Color::White) ? WhitePieces : BlackPieces;
    pieces.push_back(piece);
}


Piece *make_new_peice(Piece* piece, char row, char col){
    Piece *new_piece = nullptr;

    if(piece->getType() == Knight){
        new_piece = new KnightPiece(piece->getType(), piece->getColor(), row, col);
    }

    if(piece->getType() == Pawn){
        new_piece = new PawnPiece(piece->getType(), piece->getColor(), row, col);
    }
    
    if(piece->getType() == Bishop){
        new_piece = new BishopPiece(piece->getType(), piece->getColor(), row, col);
    }

    if(piece->getType() == King){
        new_piece = new KingPiece(piece->getType(), piece->getColor(), row, col);
    }

    if(piece->getType() == Queen){
        new_piece = new QueenPiece(piece->getType(), piece->getColor(), row, col);
    }

    if(piece->getType() == Rook){
        new_piece = new RookPiece(piece->getType(), piece->getColor(), row, col);
    }


    return new_piece;
}

pair<char , char> get_king_position(vector<vector<Square*>> board, Color player_color){
    char row , col;

    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(board[i][j]->getPiece() == nullptr){
                continue;
            }
            if(board[i][j]->getPiece()->getType() == King && board[i][j]->getPiece()->getColor() == player_color){
                row = get_positions_on_board(i , j).first;
                col = get_positions_on_board(i , j).second;
            }
        }
    }

    return make_pair(row, col);
}   

bool Game::is_check(Board* board, vector<Piece*> other_player_pieces, Color player_color){
    pair<char , char> king_position = get_king_position(board->get_board(), player_color);

    bool can = false;

    for(auto piece : other_player_pieces){
        auto [row , col] = piece->getPosition();
        auto moves = piece->get_valid_moves(board, row, col);

        if(moves.count(king_position)){
            can = true;
        }
    }    

    return can;
}

Board* Game::copy_and_move(Board* board, pair<int, int> from, pair<int , int> to){
    Board* new_board = new Board(board->get_board());

    Piece* piece = new_board->get_board()[from.first][from.second]->getPiece();

    auto [row , col] = get_positions_on_board(to.first, to.second);

    Piece* new_piece = make_new_peice(piece, row, col);
    new_board->get_board()[to.first][to.second]->setPiece(new_piece);
    new_board->get_board()[from.first][from.second]->deletePiece();
    return new_board;
}

bool Game::is_stalemate(Board* board, vector<Piece*> player_pieces){
    bool cannot_move = true;

    for(auto piece : player_pieces){
        auto [row, col] = piece->getPosition();
        auto moves = piece->get_valid_moves(board, row, col);
        moves = review(moves, get_positions_in_array(row, col));
        if(!moves.empty()){
            cannot_move = false;
        }
    }

    return cannot_move;
}

set<pair<char, char>> Game::review(set<pair<char, char>> valid_moves, pair<int , int> from){
    set<pair<char , char>> new_valid_moves;

    for(auto [row, col] : valid_moves){
        auto [i , j] = get_positions_in_array(row, col);
            
        Board* new_board = copy_and_move(board, from, make_pair(i , j));
        vector<Piece*> other_player_pieces;
        Color player_color;

        if(board->get_board()[from.first][from.second]->getPiece()->getColor() == Black){
            other_player_pieces.assign(WhitePieces.begin(), WhitePieces.end());
            player_color = Black;
        }

        else{
            other_player_pieces.assign(BlackPieces.begin(), BlackPieces.end());
            player_color = White;
        }
        
        if(is_check(new_board, other_player_pieces, player_color) == false){
            new_valid_moves.insert(make_pair(row, col));
        }
    }
    return new_valid_moves;
}



void Game::move(Board* board, pair<int , int> from, pair<int , int> to){
    Piece* piece = board->get_board()[from.first][from.second]->getPiece();

    auto [row , col] = get_positions_on_board(to.first, to.second);

    Piece* new_piece = make_new_peice(piece, row, col);  
    
    delete_piece_from_vector(piece->getColor(), piece);

    if(board->get_board()[to.first][to.second]->getPiece() != nullptr){
        Piece *attacked_piece = board->get_board()[to.first][to.second]->getPiece();
        delete_piece_from_vector(attacked_piece->getColor(), attacked_piece);
    }

    insert_piece_in_vector(new_piece->getColor(), new_piece);

    board->get_board()[to.first][to.second]->setPiece(new_piece);
    board->get_board()[from.first][from.second]->deletePiece();
}

void Game::play(){
    while(true){
        label1:
        vector<Piece*> other_player_pieces = (board->turn == White ? BlackPieces : WhitePieces);
        Color player_color = (board->turn == White ? White : Black);
        pair<char, char> king_position = get_king_position(board->get_board(), player_color);
        bool check = is_check(board, other_player_pieces, player_color);

        vector<Piece*> player_pieces = (board->turn == White ? WhitePieces : BlackPieces);;
        bool stalement = is_stalemate(board, player_pieces);

        if(check == true && stalement == true){
            
            board->display({king_position}, (player_color == White ? 2 : 1), false, true);
            return;
        }

        if(stalement == true){
            board->display({}, 0, true, false);
            return;
        }

        if(check == true){
            board->display({king_position}, 0, false, true);
        }
        else{
            board->display();
        }

        cout << "Indicate the current position of the piece you wish to move: ";
        label2:
        char row, col; cin >> col >> row;
        if(col < 'a' || col > 'h' || row < '1' || row > '8'){
            cout << "Invalid input. Please select a valid position on the board: ";
            goto label2;
        }
        auto [i , j] = get_positions_in_array(row, col);
        if(board->board[i][j]->getPiece() == nullptr){
            cout << "Invalid input. Please choose a non-empty square: ";
            goto label2;
        }

        if(board->board[i][j]->getPiece()->getColor() != board->turn){
            cout << "Invalid input. Please select a square with one of your pieces: ";
            goto label2;
        }
        auto valid_moves = board->board[i][j]->getPiece()->get_valid_moves(board, row, col);
        auto new_valid_moves = review(valid_moves, make_pair(i, j));
        
        if(new_valid_moves.empty()){
            cout << "No valid moves for the chosen piece. please select another piece: ";
            goto label2;
        }
        board->display(new_valid_moves);

        label3: 
        cout << "Choose a position of these:{";
        int valid_move_count = (int)new_valid_moves.size();
        for(auto [row, col] : new_valid_moves){
            valid_move_count--;
            cout << col << row;
            if(valid_move_count) cout << ", ";
        }
        cout << "} or type 'undo' to select a different piece: ";

        string s; 
        cin >> s;
        if((int)s.size() == 2 && new_valid_moves.count(make_pair(s[1], s[0]))){
            move(board, get_positions_in_array(row, col), get_positions_in_array(s[1], s[0]));  
            if(board->turn == White){
                board->turn = Black;
            } 
            else{
                board->turn = White;
            }
        }
        else if(s == "undo"){
            goto label1;
        }
        else{
            cout << "Invalid input, ";
            goto label3;
        }
    }
}