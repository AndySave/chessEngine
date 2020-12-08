
#include "defenitions.h"

void printMove(int move){
    char promotPieces[13] = {' ', 'q', 'n', 'b', 'r', 'q', 'q',
                                  'q', 'n', 'b', 'r', 'q', 'q'};

    cout << sq64ToAlgebraic(sq120(fromsq(move))) << sq64ToAlgebraic(sq120(tosq(move))) << (promoted(move) == 0 ? ' ' : promotPieces[promoted(move)]);
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

void generateLegalMoves(const Board *brd, Movelist *lst){
    lst->count = 0;
}