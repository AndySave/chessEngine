
#include "defenitions.h"
#define FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, FEN);

    // perftTest(5, &board);

    playerMenu(&board, 5);

    /*
    while (true){
        makeMove(&board, searchPosition(&board, 5));
        printBoard(&board);
        makeMove(&board, searchPosition(&board, 5));
        printBoard(&board);
    }
     */
}




