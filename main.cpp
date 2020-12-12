
#include "defenitions.h"

int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, "4r1k1/p2p1ppp/8/2p4K/pr3P2/6q1/8/8 w - - 0 47");

    // perftTest(5, &board);
    while(true) {
        searchPosition(&board, 5);
        string mve;
        cin >> mve;
        parseMove(&board, mve);
        printBoard(&board);
    }
}

