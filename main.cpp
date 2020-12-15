
#include "defenitions.h"
#define FEN "r1bq1rk1/ppp2ppp/2n2n2/2b1pP2/4P1P1/2PP1Q2/P6P/RNB1KBNR b KQ - 0 9"

int startUI() {
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

}




