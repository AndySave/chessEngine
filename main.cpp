
#include "defenitions.h"
#define FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
int main(){
    Board board{};
    Searchinfo info{};

    info.depth = 6;

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, FEN);

    // perftTest(5, &board);

    playerMenu(&board, &info);

}




