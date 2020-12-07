
#include "defenitions.h"

void allInits(Board *brd){
    resetBoard(&brd);  // fungerer ogsaa som init
    initBitBoard(&brd);
    initBitMasks();
    initHashkeys();
}
