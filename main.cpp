#include <iostream>
#include "defenitions.h"
using namespace std;


int main(){
    Board board{};

    resetBoard(&board);  // fungerer ogsaa som init
    initBitBoard(&board);
    initBitMasks();
    initHashkeys();

    printBoard(&board);

    cout << generateHash(&board);
}


