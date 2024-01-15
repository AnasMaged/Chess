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

bool Game::can_move(Board* board, vector<Piece*> other_player_pieces, Color player_color){
    cout << "a7a\n";
    return true;
    pair<char , char> king_position = get_king_position(board->get_board(), player_color);

    bool can = true;


        cout << king_position.first << ' ' << king_position.second << '\n';
        return true;
    for(auto piece : other_player_pieces){
        auto [row , col] = piece->getPosition();
        cout << row << ' ' << col << '\n';
        return true;
        auto moves = piece->get_valid_moves(board, row, col);
        if(moves.count(king_position)){
            can = false;
        }
    }    

    return can;
}

Board* Game::copy_and_move(Board* board, pair<int, int> from, pair<int , int> to){
    Board* new_board = new Board(board->get_board());

    Piece* piece = new_board->get_board()[from.first][from.second]->getPiece();

    auto [row , col] = get_positions_on_board(to.first, to.second);

    Piece* new_piece = new Piece(piece->getType(), piece->getColor(), row, col);
    new_board->get_board()[to.first][to.second]->setPiece(new_piece);
    new_board->get_board()[from.first][from.second]->deletePiece();
    return new_board;
}

set<pair<char, char>> Game::check(set<pair<char, char>> valid_moves, pair<int , int> from){
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
        
        if(can_move(new_board, other_player_pieces, player_color) == true){
            new_valid_moves.insert(make_pair(row, col));
        }
    }
    return new_valid_moves;
}

void Game::move(Board* board, pair<int , int> from, pair<int , int> to){
    Piece* piece = board->get_board()[from.first][from.second]->getPiece();

    auto [row , col] = get_positions_on_board(to.first, to.second);

    Piece* new_piece = new Piece(piece->getType(), piece->getColor(), row, col);
    board->get_board()[to.first][to.second]->setPiece(new_piece);
    board->get_board()[from.first][from.second]->deletePiece();
}

void Game::play(){
    while(true){
        label1:
        board->display(); 
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
        auto new_valid_moves = check(valid_moves, make_pair(i , j));
        
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