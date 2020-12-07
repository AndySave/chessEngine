#include <iostream>
#include "defenitions.h"
using namespace std;


int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    resetBoard(&board);  // fungerer ogsaa som init
    FENBoardUpdater(&board, "8/p7/2R4p/6p1/3R1p2/P4P1P/r2krPK1/8 b - - 3 33");

    // resten
    initBitBoard(&board);

    printBoard(&board);
}

