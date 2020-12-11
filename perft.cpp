
#include "defenitions.h"

long leafNodes;

void perft(int depth, Board *brd){
    if (depth == 0){
        leafNodes++;
        return;
    }

    Movelist lst[1];
    generateLegalMoves(brd, lst);

    for (int moveNum = 0; moveNum < lst->count; moveNum++){
        if (!makeMove(brd, lst->moves[moveNum].move)){
            continue;
        }

        perft(depth - 1, brd);
        undoMove(brd);
    }

    return;
}

void perftTest(int depth, Board *brd){
    printBoard(brd);
    printf("\nStarting Test To Depth:%d\n", depth);
    leafNodes = 0;
    Movelist lst[1];
    generateLegalMoves(brd, lst);

    int move;
    for (int moveNum = 0; moveNum < lst->count; moveNum++){
        move = lst->moves[moveNum].move;
        if (!makeMove(brd, move)){
            continue;
        }

        long cnodes = leafNodes;
        perft(depth - 1, brd);
        undoMove(brd);
        long oldnodes = leafNodes - cnodes;
        printf("move %d : ", moveNum+1);
        printMove(move);
        cout << ": " << oldnodes << "\n";

    }
    printf("\nTest Complete : %ld nodes nodes visited\n", leafNodes);

    return;
}




