cmake_minimum_required(VERSION 3.17)
project(chessEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(chessEngine
        board.cpp main.cpp)