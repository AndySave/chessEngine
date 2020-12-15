
#include "defenitions.h"

#define INFINITE 100000
#define MATE 300000

static void checkUp(){

}

static void clearForSearch(Board *brd, Searchinfo *info){

    for (int i = 0; i < 13; ++i){
        for (int j = 0; j < 120; ++j){
            brd->searchHistory[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < maxdepth; ++j){
            brd->searchKillers[i][j] = 0;
        }
    }

    brd->ply = 0;

    info->starttime = getTime();
    info->stopped = false;
    info->nodes = 0;
    info->fh = 0;
    info->fhf = 0;

}

static int quiescence (int alpha, int beta, Board *brd, Searchinfo *info){
    return 0;
}

static int negaMax(int alpha, int beta, int depth, Board *brd, Searchinfo *info, bool doNull){
    info->nodes++;
    if (depth == 0){
        return mainEval(brd);
    }

    if (isRepetition(brd) || brd->fiftyMove >= 100){
        return 0;
    }

    if (brd->ply > maxdepth - 1){
        return mainEval(brd);
    }

    int legal = 0;
    int score;
    int bestMove = 0;
    int oldAlpha = alpha;
    Movelist lst[1];
    generateLegalMoves(brd, lst);

    for (int moveNum = 0; moveNum < lst->count; moveNum++){
        if (!makeMove(brd, lst->moves[moveNum].move)){
            continue;
        }
        legal++;

        score = -negaMax(-beta, -alpha, depth - 1, brd, info, true);
        undoMove(brd);

        if (score > alpha){
            if (score >= beta){
                if (legal == 1){
                    info->fhf++;
                }
                info->fh++;
                return beta;
            }
            alpha = score;
            bestMove = lst->moves[moveNum].move;
        }
    }

    if (!legal){
        if (sqAttacked(brd->kingSq[brd->side], brd->side^1, brd)){
            return -MATE + brd->ply;
        }else{
            return 0;
        }
    }

    if (alpha != oldAlpha){
        storePVMove(brd, bestMove);
    }

    return alpha;
}

int searchPosition(Board *brd, Searchinfo *info){

    int bestMove = 0;
    int bestScore = -INFINITE;
    int currDepth = 0;
    int pvMoves = 0;
    clearForSearch(brd, info);

    // Iterative deepening
    for (currDepth = 1; currDepth <= info->depth; currDepth++){

        bestScore = negaMax(-INFINITE, INFINITE, currDepth, brd, info, true);
        pvMoves = getPVLine(currDepth, brd);
        bestMove = brd->pvArray[0];

        // Check if out of time

        printf("Depth %d: score:%d move:%d nodes:%ld\n", currDepth, bestScore, bestMove, info->nodes);

        cout << "Best line: ";
        for(int i = 0; i < pvMoves; ++i){
            printMove(brd->pvArray[i]);
        }
        cout << "\n";
        printf("Ordering: %.2f\n", (info->fhf/info->fh));
    }

    return 0;
}
