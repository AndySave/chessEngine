cmake_minimum_required(VERSION 3.17)
project(chessEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(.)

add_executable(chessEngine
        board.cpp
        defenitions.h
        hashkey.cpp
        moveGeneration.cpp
        perft.cpp
        search.cpp
        misc.cpp
        evaluation.cpp
        pvtable.cpp
        uci.cpp
        main.cpp board.cpp tests.cpp)


