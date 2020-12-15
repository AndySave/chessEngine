
#include "defenitions.h"
#define FEN "5rk1/pp4pp/2pp1q2/4n3/P1P2N2/6P1/1PP1Q2P/4R1K1 b - - 2 21"
int main(){
    Board board{};
    Searchinfo info{};

    info.depth = 7;

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, FEN);

    playerMenu(&board, &info);

}

