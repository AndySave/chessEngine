
#include "defenitions.h"

#define INFINITE 100000
#define MATE 45000

static void checkUp(){

}

static void pickNextMove(int moveNum, Movelist *lst){

    Move temp;
    int bestScore = 0;
    int bestNum = moveNum;

    for (int i = moveNum; i < lst->count; ++i){
        if (lst->moves[i].score > bestScore){
            bestScore = lst->moves[i].score;
            bestNum = i;
        }
    }
    temp = lst->moves[moveNum];
    lst->moves[moveNum] = lst->moves[bestNum];
    lst->moves[bestNum] = temp;
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
    info->nodes++;

    if ((isRepetition(brd) || brd->fiftyMove >= 100) && brd->ply){
        return 0;
    }

    if (brd->ply > maxdepth - 1){
        return mainEval(brd);
    }

    int score = mainEval(brd);

    if (score >= beta){
        return beta;
    }

    if (score > alpha){
        alpha = score;
    }

    int legal = 0;
    score = -INFINITE;
    int bestMove = 0;
    int oldAlpha = alpha;
    Movelist lst[1];
    generateLegalCaptures(brd, lst);

    for (int moveNum = 0; moveNum < lst->count; moveNum++) {
        pickNextMove(moveNum, lst);

        if (!makeMove(brd, lst->moves[moveNum].move)) {
            continue;
        }
        legal++;

        score = -quiescence(-beta, -alpha, brd, info);
        undoMove(brd);

        if (score > alpha) {
            if (score >= beta) {
                if (legal == 1) {
                    info->fhf++;
                }
                info->fh++;
                return beta;
            }
            alpha = score;
            bestMove = lst->moves[moveNum].move;
        }
    }

    if (alpha != oldAlpha){
        storePVMove(brd, bestMove);
    }


    return alpha;
}

static int negaMax(int alpha, int beta, int depth, Board *brd, Searchinfo *info, bool doNull){
    if (depth == 0){
        return quiescence(alpha, beta, brd, info);
    }
    info->nodes++;

    if ((isRepetition(brd) || brd->fiftyMove >= 100) && brd->ply){
        return 0;
    }

    if (brd->ply > maxdepth - 1){
        return mainEval(brd);
    }

    bool inCheck = sqAttacked(brd->kingSq[brd->side], brd->side^1, brd);

    if (inCheck){
        depth++;
    }

    int legal = 0;
    int score;
    int bestMove = 0;
    int oldAlpha = alpha;
    int pvMove = probePVTable(brd);
    Movelist lst[1];
    generateLegalMoves(brd, lst);

    // If the move is a pvMove (best move from previos iteration), then give it a score of 2 million
    // This means it will be searched first
    if (pvMove != 0){
        for (int i = 0; i < lst->count; ++i){
            if (lst->moves[i].move == pvMove){
                lst->moves[i].score = 2000000;
                break;
            }
        }
    }

    for (int moveNum = 0; moveNum < lst->count; moveNum++){
        pickNextMove(moveNum, lst);

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
                if (!(lst->moves[moveNum].move & captureFlag)){
                    brd->searchKillers[1][brd->ply] = brd->searchKillers[0][brd->ply];
                    brd->searchKillers[0][brd->ply] = lst->moves[moveNum].move;
                }
                info->fh++;
                return beta;
            }
            alpha = score;
            bestMove = lst->moves[moveNum].move;

            if (!(lst->moves[moveNum].move & captureFlag)){
                brd->searchHistory[brd->pieces[fromsq(bestMove)]][tosq(bestMove)] += depth;
            }
        }
    }

    // If there are no legal moves, it has to be either checkmate or stalemate
    if (!legal){
        if (inCheck){
            return -MATE + brd->ply;
        }else{
            return 0;
        }
    }

    // If alpha beat oldAlpha, then a new bestMove has been found
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

    return bestMove;
}
