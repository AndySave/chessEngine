
#include "defenitions.h"

void printMove(int move){
    char promotPieces[13] = {' ', 'q', 'n', 'b', 'r', 'q', 'q',
                                  'q', 'n', 'b', 'r', 'q', 'q'};

    cout << sq64ToAlgebraic(sq120(fromsq(move))) << sq64ToAlgebraic(sq120(tosq(move))) << (promoted(move) == 0 ? ' ' : promotPieces[promoted(move)]);
}


int move(int from, int to, int capture, int promote, int psfl){
    return (from | (to << 7) | (capture << 14) | (promote << 20) | psfl);
}

void addQuietMove(const Board *brd, int move, Movelist *lst){
    lst->moves[lst->count].move = move;
    lst->moves[lst->count].score = 0;
    lst->count++;
}

void addCaptureMove(const Board *brd, int move, Movelist *lst){
    lst->moves[lst->count].move = move;
    lst->moves[lst->count].score = 0;
    lst->count++;
}

void addEnPasMove(const Board *brd, int move, Movelist *lst){
    lst->moves[lst->count].move = move;
    lst->moves[lst->count].score = 0;
    lst->count++;
}

void addWhitePawnCaptureMove(const Board *brd, int from, int to, int cap, Movelist *lst){
    if ((from/10) - 2 == 7){
        addCaptureMove(brd, move(from, to, cap, Q, 0), lst);
        addCaptureMove(brd, move(from, to, cap, R, 0), lst);
        addCaptureMove(brd, move(from, to, cap, B, 0), lst);
        addCaptureMove(brd, move(from, to, cap, N, 0), lst);
    }else{
        addCaptureMove(brd, move(from, to, cap, e, 0), lst);
    }
}

void addWhitePawnMove(const Board *brd, int from, int to, Movelist *lst){
    if ((from/10) - 2 == 7){
        addQuietMove(brd, move(from, to, e, Q, 0), lst);
        addQuietMove(brd, move(from, to, e, R, 0), lst);
        addQuietMove(brd, move(from, to, e, B, 0), lst);
        addQuietMove(brd, move(from, to, e, N, 0), lst);
    }else{
        addQuietMove(brd, move(from, to, e, e, 0), lst);
    }
}

void generateLegalMoves(const Board *brd, Movelist *lst){
    lst->count = 0;
}
