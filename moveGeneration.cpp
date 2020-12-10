
#include "defenitions.h"

void printMove(int move){
    char promotPieces[13] = {' ', 'q', 'n', 'b', 'r', 'q', 'q',
                                  'q', 'n', 'b', 'r', 'q', 'q'};

    cout << sq64ToAlgebraic(sq120(fromsq(move))) << sq64ToAlgebraic(sq120(tosq(move))) << (promoted(move) == 0 ? ' ' : promotPieces[promoted(move)]);
}


int move(int from, int to, int capture, int promote, int flag){
    return (from | (to << 7) | (capture << 14) | (promote << 20) | flag);
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

const int diagPces[4] = {B, Q, b, q};
const int horVertPces[4] = {R, Q, r, q};

void generateLegalMoves(Board *brd, Movelist *lst){
    lst->count = 0;

    if (brd->side == white){

        // Generating pawn moves
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

        // Generating knight moves
        for (int i = 0; i < brd->pceNum[N]; i++){
            int sq = brd->pieceList[N][i];
            for (int dir : NDir){
                if (brd->pieces[sq + dir] == e){
                    addQuietMove(brd, move(sq, sq+dir, e, e, e), lst);
                }else if (pceCol[brd->pieces[sq+dir]] == black){
                    addCaptureMove(brd, move(sq, sq+dir, brd->pieces[sq+dir], e, e), lst);
                }
            }
        }

        // Generating king moves
        for (int i = 0; i < brd->pceNum[K]; i++){
            int sq = brd->pieceList[K][i];
            for (int dir : KDir){
                if (brd->pieces[sq + dir] == e){
                    addQuietMove(brd, move(sq, sq+dir, e, e, e), lst);
                }else if (pceCol[brd->pieces[sq+dir]] == black){
                    addCaptureMove(brd, move(sq, sq+dir, brd->pieces[sq+dir], e, e), lst);
                }
            }
        }

        // Generate bishop and queen moves
        for (int i = 0; i < 2; i++){
            int pce = diagPces[i];
            for (int j = 0; j < brd->pceNum[pce]; j++){
                int sq = brd->pieceList[pce][j];
                for (int dir : BDir){
                    int tSq = sq + dir;
                    int pceOnSq = brd->pieces[tSq];

                    while (pceOnSq == e){
                        addQuietMove(brd, move(sq, tSq, e, e, e), lst);
                        tSq += dir;
                        pceOnSq = brd->pieces[tSq];
                    }
                    if (pceCol[pceOnSq] == black){
                        addCaptureMove(brd, move(sq, tSq, brd->pieces[tSq], e, e), lst);
                    }
                }
            }
        }

        // Generate rook and queen moves
        for (int i = 0; i < 2; i++){
            int pce = horVertPces[i];
            for (int j = 0; j < brd->pceNum[pce]; j++){
                int sq = brd->pieceList[pce][j];
                for (int dir : RDir){
                    int tSq = sq + dir;
                    int pceOnSq = brd->pieces[tSq];

                    while (pceOnSq == e){
                        addQuietMove(brd, move(sq, tSq, e, e, e), lst);
                        tSq += dir;
                        pceOnSq = brd->pieces[tSq];
                    }
                    if (pceCol[pceOnSq] == black){
                        addCaptureMove(brd, move(sq, tSq, brd->pieces[tSq], e, e), lst);
                    }
                }
            }
        }

        // Generating king side castling move
        if (brd->castlePerm & WKC){
            // 26 and 27 are the squares in between the king and rook
            if (brd->pieces[26] == e && brd->pieces[27] == e){
                if (!sqAttacked(26, black, brd) && !sqAttacked(27, black, brd)){
                    addQuietMove(brd, move(25, 27, e, e, castleFlag), lst);
                }
            }
        }

        // Generating queen side castling move
        if (brd->castlePerm & WQC){
            // 23 and 24 are the squares in between the king and rook
            if (brd->pieces[23] == e && brd->pieces[24] == e){
                if (!sqAttacked(23, black, brd) && !sqAttacked(24, black, brd)){
                    addQuietMove(brd, move(25, 23, e, e, castleFlag), lst);
                }
            }
        }

    }
    else{
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

        // Generating knight moves
        for (int i = 0; i < brd->pceNum[n]; i++){
            int sq = brd->pieceList[n][i];
            for (int dir : NDir){
                if (brd->pieces[sq + dir] == e){
                    addQuietMove(brd, move(sq, sq+dir, e, e, e), lst);
                }else if (pceCol[brd->pieces[sq+dir]] == white){
                    addCaptureMove(brd, move(sq, sq+dir, brd->pieces[sq+dir], e, e), lst);
                }
            }
        }

        // Generating king moves
        for (int i = 0; i < brd->pceNum[k]; i++){
            int sq = brd->pieceList[k][i];
            for (int dir : KDir){
                if (brd->pieces[sq + dir] == e){
                    addQuietMove(brd, move(sq, sq+dir, e, e, e), lst);
                }else if (pceCol[brd->pieces[sq+dir]] == white){
                    addCaptureMove(brd, move(sq, sq+dir, brd->pieces[sq+dir], e, e), lst);
                }
            }
        }

        // Generate bishop and queen moves
        for (int i = 2; i < 4; i++){
            int pce = diagPces[i];
            for (int j = 0; j < brd->pceNum[pce]; j++){
                int sq = brd->pieceList[pce][j];
                for (int dir : BDir){
                    int tSq = sq + dir;
                    int pceOnSq = brd->pieces[tSq];

                    while (pceOnSq == e){
                        addQuietMove(brd, move(sq, tSq, e, e, e), lst);
                        tSq += dir;
                        pceOnSq = brd->pieces[tSq];
                    }
                    if (pceCol[pceOnSq] == white){
                        addCaptureMove(brd, move(sq, tSq, brd->pieces[tSq], e, e), lst);
                    }
                }
            }
        }

        // Generate rook and queen moves
        for (int i = 2; i < 4; i++){
            int pce = horVertPces[i];
            for (int j = 0; j < brd->pceNum[pce]; j++){
                int sq = brd->pieceList[pce][j];
                for (int dir : RDir){
                    int tSq = sq + dir;
                    int pceOnSq = brd->pieces[tSq];

                    while (pceOnSq == e){
                        addQuietMove(brd, move(sq, tSq, e, e, e), lst);
                        tSq += dir;
                        pceOnSq = brd->pieces[tSq];
                    }
                    if (pceCol[pceOnSq] == white){
                        addCaptureMove(brd, move(sq, tSq, brd->pieces[tSq], e, e), lst);
                    }
                }
            }
        }

        // Generating king side castling move
        if (brd->castlePerm & BKC){
            // 26 and 27 are the squares in between the king and rook
            if (brd->pieces[96] == e && brd->pieces[97] == e){
                if (!sqAttacked(96, white, brd) && !sqAttacked(97, white, brd)){
                    addQuietMove(brd, move(95, 97, e, e, castleFlag), lst);
                }
            }
        }

        // Generating queen side castling move
        if (brd->castlePerm & BQC){
            // 23 and 24 are the squares in between the king and rook
            if (brd->pieces[93] == e && brd->pieces[94] == e){
                if (!sqAttacked(93, white, brd) && !sqAttacked(94, white, brd)){
                    addQuietMove(brd, move(95, 93, e, e, castleFlag), lst);
                }
            }
        }
    }
}
