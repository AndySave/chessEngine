
#include "defenitions.h"

int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, standardFen);

    perftTest(7, &board);
}



