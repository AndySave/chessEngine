
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
    if ((from/10) - 1 == 7){
        addCaptureMove(brd, move(from, to, cap, Q, 0), lst);
        addCaptureMove(brd, move(from, to, cap, R, 0), lst);
        addCaptureMove(brd, move(from, to, cap, B, 0), lst);
        addCaptureMove(brd, move(from, to, cap, N, 0), lst);
    }else{
        addCaptureMove(brd, move(from, to, cap, e, 0), lst);
    }
}

void addWhitePawnMove(const Board *brd, int from, int to, Movelist *lst){
    if ((from/10) - 1 == 7){
        addQuietMove(brd, move(from, to, e, Q, 0), lst);
        addQuietMove(brd, move(from, to, e, R, 0), lst);
        addQuietMove(brd, move(from, to, e, B, 0), lst);
        addQuietMove(brd, move(from, to, e, N, 0), lst);
    }else{
        addQuietMove(brd, move(from, to, e, e, 0), lst);
    }
}

void addBlackPawnCaptureMove(const Board *brd, int from, int to, int cap, Movelist *lst){
    if ((from/10) - 1 == 2){
        addCaptureMove(brd, move(from, to, cap, q, 0), lst);
        addCaptureMove(brd, move(from, to, cap, r, 0), lst);
        addCaptureMove(brd, move(from, to, cap, b, 0), lst);
        addCaptureMove(brd, move(from, to, cap, n, 0), lst);
    }else{
        addCaptureMove(brd, move(from, to, cap, e, 0), lst);
    }
}

void addBlackPawnMove(const Board *brd, int from, int to, Movelist *lst){
    if ((from/10) - 1 == 2){
        addQuietMove(brd, move(from, to, e, q, 0), lst);
        addQuietMove(brd, move(from, to, e, r, 0), lst);
        addQuietMove(brd, move(from, to, e, b, 0), lst);
        addQuietMove(brd, move(from, to, e, n, 0), lst);
    }else{
        addQuietMove(brd, move(from, to, e, e, 0), lst);
    }
}

const int pceCol[] = {2, white, white, white, white, white, white,
                      black, black, black, black, black, black, 2};
const int slidingPieces[6] = {B, R, Q, b, r, q};
const int nonSlidingPieces[4] = {N, K, n, k};

void generateLegalMoves(const Board *brd, Movelist *lst){
    lst->count = 0;

    if (brd->side == white){
        for (int i = 0; i < brd->pceNum[P]; i++){
            int sq = brd->pieceList[P][i];
            int rank = sq/10 - 1;

            if (brd->pieces[sq+10] == e){
                addWhitePawnMove(brd, sq, sq+10, lst);

                if (rank == 2 && brd->pieces[sq+20] == e){
                    addQuietMove(brd, move(sq, sq+20, e, e, pwnStartFlag), lst);
                }
            }

            if (pceCol[brd->pieces[sq+9]] == black){
                addWhitePawnCaptureMove(brd, sq, sq+9, brd->pieces[sq+9], lst);
            }
            if (pceCol[brd->pieces[sq+11]] == black){
                addWhitePawnCaptureMove(brd, sq, sq+11, brd->pieces[sq+11], lst);
            }

            if (sq+9 == brd->enPas){
                addCaptureMove(brd, move(sq, sq+9, e, e, epFlag), lst);
            }
            if (sq+11 == brd->enPas){
                addCaptureMove(brd, move(sq, sq+11, e, e, epFlag), lst);
            }

        }

    }else{
        for (int i = 0; i < brd->pceNum[p]; i++){
            int sq = brd->pieceList[p][i];
            int rank = sq/10 - 1;

            if (brd->pieces[sq-10] == e){
                addBlackPawnMove(brd, sq, sq-10, lst);

                if (rank == 7 && brd->pieces[sq-20] == e){
                    addQuietMove(brd, move(sq, sq-20, e, e, pwnStartFlag), lst);
                }
            }

            if (pceCol[brd->pieces[sq-9]] == white){
                addBlackPawnCaptureMove(brd, sq, sq-9, brd->pieces[sq-9], lst);
            }
            if (pceCol[brd->pieces[sq-11]] == white){
                addBlackPawnCaptureMove(brd, sq, sq-11, brd->pieces[sq-11], lst);
            }

            if (sq-9 == brd->enPas){
                addCaptureMove(brd, move(sq, sq-9, e, e, epFlag), lst);
            }
            if (sq-11 == brd->enPas){
                addCaptureMove(brd, move(sq, sq-11, e, e, epFlag), lst);
            }
        }
    }
}
