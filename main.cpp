
#include "defenitions.h"
#define FEN "r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1"
int main(){
    Board board{};
    Searchinfo info{};

    info.depth = 8;

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


