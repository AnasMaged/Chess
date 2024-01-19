cmake_minimum_required(VERSION 3.12)
project(ChessGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessGame
    SrcFiles/Bishop.cpp
    SrcFiles/board.cpp
    SrcFiles/ChessConstants.cpp
    SrcFiles/game.cpp
    SrcFiles/king.cpp
    SrcFiles/knight.cpp
    SrcFiles/main.cpp
    SrcFiles/pawn.cpp
    SrcFiles/piece.cpp
    SrcFiles/queen.cpp
    SrcFiles/rook.cpp
    SrcFiles/square.cpp
)

