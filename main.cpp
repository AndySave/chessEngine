
#include "defenitions.h"
#define FEN "rnbqkbnr/ppp1pppp/8/3p4/2PP4/8/PP2PPPP/RNBQKBNR b KQkq - 0 2"
int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, FEN);

    // perftTest(5, &board);

    playerMenu(&board, 5);

}



