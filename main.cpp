
#include "defenitions.h"
#define FEN "6k1/5Q2/1B4p1/7p/8/P1PB3P/5PP1/R5K1 b - - 0 3"


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





