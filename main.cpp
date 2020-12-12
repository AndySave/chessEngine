
#include "defenitions.h"
#define FEN "5k2/8/8/8/8/3Q4/1K6/8 w - - 0 1"
int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, FEN);

    // perftTest(5, &board);
    while(true) {
        cout << "midMultiplier: " << board.midMultiplier << endl;
        cout << "endMultiplier: " << board.midMultiplier << endl;
        searchPosition(&board, 8);
        string mve;
        cin >> mve;
        parseMove(&board, mve);
        printBoard(&board);
    }
}


