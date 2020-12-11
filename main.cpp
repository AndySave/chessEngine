
#include "defenitions.h"

int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, standardFen);

    perftTest(5, &board);

    parseMove(&board, "a2a4");
    printBoard(&board);
}



