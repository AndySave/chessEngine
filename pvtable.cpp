
#include "defenitions.h"

void storePVMove(Board *brd, int move){
    brd->pvTable[brd->posKey] = move;
}


int probePVTable(Board *brd){
    if (brd->pvTable.find(brd->posKey) != brd->pvTable.end()){
        return brd->pvTable[brd->posKey];
    }
    return 0;
}


int getPVLine(int depth, Board *brd){
    int move = probePVTable(brd);
    int count = 0;

    while (move != 0 && count < depth){
        makeMove(brd, move);
        brd->pvArray[count++] = move;

        move = probePVTable(brd);
    }

    while (brd->ply > 0){
        undoMove(brd);
    }

    return count;
}

