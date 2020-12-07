cmake_minimum_required(VERSION 3.17)
project(chessEngine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(chessEngine
        defenitions.cpp
        defenitions.h
        main.cpp)
