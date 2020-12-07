#include <iostream>
#include "board.h"
using namespace std;


int main(){
    Board board{};

    resetBoard(&board);  // fungerer ogsaa som init
    initBitBoard(&board);
    initBitMasks();

    board.pieces[31] = P;
    printBoard(&board, true);

}



