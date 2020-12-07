#include <iostream>
#include "defenitions.h"
using namespace std;


int main(){
    Board board{};

    resetBoard(&board);  // fungerer ogsaa som init
    initBitBoard(&board);
    initBitMasks();
    initHashkeys();

    FENBoardUpdater(&board, "r2q1rk1/B1pb2p1/p2p3p/1p1P3Q/P3p3/1BPn3P/1P2RPP1/R4NK1 b - - 0 19");
    printBoard(&board);
    printBoard120(&board);
}

