
#include "defenitions.h"

int nod = 0;
static int negaMax(int alpha, int beta, int depth, Board *brd){
    if (depth == 0){
        nod++;
        return mainEval(brd);
    }

    if (isRepetition(brd) || brd->fiftyMove >= 100){
        return 0;
    }

    bool legal = false;
    int score;
    int bestMove = 0;
    Movelist lst[1];
    generateLegalMoves(brd, lst);

    for (int moveNum = 0; moveNum < lst->count; moveNum++){
        if (!makeMove(brd, lst->moves[moveNum].move)){
            continue;
        }
        legal = true;

        score = -negaMax(-beta, -alpha, depth - 1, brd);
        undoMove(brd);

        if (score > alpha){
            if (score >= beta){
                return beta;
            }
            alpha = score;
        }
    }
    if (!legal){
        if (sqAttacked(brd->kingSq[brd->side], brd->side^1, brd)){
            return -100000 + brd->ply;
        }else{
            return 0;
        }
    }

    return alpha;
}


int searchPosition(Board *brd, int maxDepth){
    brd->ply = 0;

    nod = 0;
    int bestMove = 0;
    int bestScore = -100000;
    int score;
    bool legal = false;

    /*
    for (int currDepth = 0; currDepth < maxDepth; currDepth++){
        bestScore = negaMax(-100000, 100000, currDepth, brd);
    }
     */

    Movelist lst[1];
    generateLegalMoves(brd, lst);

    for (int moveNum = 0; moveNum < lst->count; moveNum++){
        if (!makeMove(brd, lst->moves[moveNum].move)){
            continue;
        }
        legal = true;

        score = max(bestScore, -negaMax(-100000, 100000, maxDepth - 1, brd));
        undoMove(brd);

        if (score > bestScore){
            bestMove = lst->moves[moveNum].move;
            bestScore = score;
        }
    }

    if (!legal){
        if (sqAttacked(brd->kingSq[brd->side], brd->side^1, brd)){
            cout << "CHECKMATE" << endl;
            abort();
        }else{
            cout << "STALEMATE" << endl;
            abort();
        }
    }

    cout << "\nNodes: " << nod << endl;
    cout << "Score: " << bestScore << endl;
    cout << "Best move: ";
    printMove(bestMove);
    cout << "\n";

    return bestMove;
}


