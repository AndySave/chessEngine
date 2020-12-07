#include <iostream>
#include "defenitions.h"
using namespace std;


int main(){
    Board board{};

    resetBoard(&board);  // fungerer ogsaa som init
    initBitBoard(&board);
    initBitMasks();

    board.pieces[31] = P;
    printBoard(&board, true);

}



