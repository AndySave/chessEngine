
#include "defenitions.h"

int main(){
    Board board{};
    Movelist movelist{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, standardFen);


    printBoard(&board);
    generateLegalMoves(&board, &movelist);
    printMoveList(&movelist);

}


