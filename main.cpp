
#include "defenitions.h"
using namespace std;


int main(){
    Board board{};

    // foerste inits
    initBitMasks();
    initHashkeys();

    // andre inits
    FENBoardUpdater(&board, standardFen);


    printBoard(&board);
}

