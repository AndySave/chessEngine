
#include "defenitions.h"

int main(){
    Board board{};
    Movelist movelist{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR b KQkq - 0 1");


    printBoard(&board);
    generateLegalMoves(&board, &movelist);
    printMoveList(&movelist);
}

