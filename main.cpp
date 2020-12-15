
#include "defenitions.h"
#define FEN "6rk/1p3p1p/p1q2pr1/8/2P2Q2/3P2P1/PP3P2/R3R1K1 b - - 0 21"

void startUI() {
    Board board{};
    Searchinfo info{};

    info.depth = 7;

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
    startUI();
    return 0;

}




