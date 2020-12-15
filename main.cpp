
#include "defenitions.h"
#define FEN "r1b1kb1r/2pp1ppp/1np1q3/p3P3/2P5/1P6/PB1NQPPP/R3KB1R w - - 0 1"
int main(){
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
    FENBoardUpdater(&board, standardFen);

    playerMenu(&board, &info);

}


