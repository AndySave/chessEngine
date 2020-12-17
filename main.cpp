
#include "defenitions.h"
#define FEN "8/p4p1p/2p4P/8/5k2/5p2/2r5/5K2 w - - 2 43"


void startUI() {
    Board board{};
    Searchinfo info{};

    info.depth = 6;

    // foerste inits
    initBitMasks();
    initHashkeys();
    initFilesRanksBrd();
    initEvalMasks();
    initMvvLva();

    // andre inits
    FENBoardUpdater(&board, FEN);

    playerMenu(&board, &info);
}

int main(){
    //startUI();
    uciCommunication();
    return 0;
}





