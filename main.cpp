#include <iostream>
#include "board.h"
using namespace std;


int main(){
    Board board{};

    resetBoard(&board);
    // printBoard120(&board);

    board.pieces[21] = P;
    board.pieces[25] = P;
    board.pieces[36] = P;
    board.pieces[98] = P;
    initBitBoard(&board);
    printBitBoard(board.pawns[0]);
}


