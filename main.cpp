
#include "defenitions.h"

int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N b - - 0 1");

    perftTest(6, &board);
}



