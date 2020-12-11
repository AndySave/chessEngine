
#include "defenitions.h"

#define hashPce(pce, sq) (brd->posKey ^= pieceKeys[pce][sq])  // Note: sq has to be a sq64
#define hashCa (brd->posKey ^= castleKeys[brd->castlePerm])
#define hashSide (brd->posKey ^= sideKey)
#define hashEp (brd->posKey ^= pieceKeys[e][brd->enPas])

/**
 * Prints a move in algebraic, i.e. a2a3
 * @param move int 32
 */
void printMove(int move){
    char promotPieces[13] = {' ', 'q', 'n', 'b', 'r', 'q', 'q',
                                  'q', 'n', 'b', 'r', 'q', 'q'};

    cout << sq64ToAlgebraic(sq120(fromsq(move))) << sq64ToAlgebraic(sq120(tosq(move))) << (promoted(move) == 0 ? ' ' : promotPieces[promoted(move)]);
}


int move(int from, int to, int capture, int promote, int flag){
    return (from | (to << 7) | (capture << 14) | (promote << 20) | flag);
}

static void addQuietMove(const Board *brd, int move, Movelist *lst){
    lst->moves[lst->count].move = move;
    lst->moves[lst->count].score = 0;
    lst->count++;
}

static void addCaptureMove(const Board *brd, int move, Movelist *lst){
    lst->moves[lst->count].move = move;
    lst->moves[lst->count].score = 0;
    lst->count++;
}

static void addEnPasMove(const Board *brd, int move, Movelist *lst){
    lst->moves[lst->count].move = move;
    lst->moves[lst->count].score = 0;
    lst->count++;
}

static void addWhitePawnCaptureMove(const Board *brd, int from, int to, int cap, Movelist *lst){
    if ((from/10) - 1 == 7){
        addCaptureMove(brd, move(from, to, cap, Q, 0), lst);
        addCaptureMove(brd, move(from, to, cap, R, 0), lst);
        addCaptureMove(brd, move(from, to, cap, B, 0), lst);
        addCaptureMove(brd, move(from, to, cap, N, 0), lst);
    }else{
        addCaptureMove(brd, move(from, to, cap, e, 0), lst);
    }
}

static void addWhitePawnMove(const Board *brd, int from, int to, Movelist *lst){
    if ((from/10) - 1 == 7){
        addQuietMove(brd, move(from, to, e, Q, 0), lst);
        addQuietMove(brd, move(from, to, e, R, 0), lst);
        addQuietMove(brd, move(from, to, e, B, 0), lst);
        addQuietMove(brd, move(from, to, e, N, 0), lst);
    }else{
        addQuietMove(brd, move(from, to, e, e, 0), lst);
    }
}

static void addBlackPawnCaptureMove(const Board *brd, int from, int to, int cap, Movelist *lst){
    if ((from/10) - 1 == 2){
        addCaptureMove(brd, move(from, to, cap, q, 0), lst);
        addCaptureMove(brd, move(from, to, cap, r, 0), lst);
        addCaptureMove(brd, move(from, to, cap, b, 0), lst);
        addCaptureMove(brd, move(from, to, cap, n, 0), lst);
    }else{
        addCaptureMove(brd, move(from, to, cap, e, 0), lst);
    }
}

static void addBlackPawnMove(const Board *brd, int from, int to, Movelist *lst){
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
                addEnPasMove(brd, move(sq, sq+9, e, e, epFlag), lst);
            }
            if (sq+11 == brd->enPas){
                addEnPasMove(brd, move(sq, sq+11, e, e, epFlag), lst);
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
                if (!sqAttacked(26, black, brd) && !sqAttacked(25, black, brd)){
                    addQuietMove(brd, move(25, 27, e, e, castleFlag), lst);
                }
            }
        }

        // Generating queen side castling move
        if (brd->castlePerm & WQC){
            // 23 and 24 are the squares in between the king and rook
            if (brd->pieces[22] == e && brd->pieces[23] == e && brd->pieces[24] == e){
                if (!sqAttacked(25, black, brd) && !sqAttacked(24, black, brd)){
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
                addEnPasMove(brd, move(sq, sq-9, e, e, epFlag), lst);
            }
            if (sq-11 == brd->enPas){
                addEnPasMove(brd, move(sq, sq-11, e, e, epFlag), lst);
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
                if (!sqAttacked(96, white, brd) && !sqAttacked(95, white, brd)){
                    addQuietMove(brd, move(95, 97, e, e, castleFlag), lst);
                }
            }
        }

        // Generating queen side castling move
        if (brd->castlePerm & BQC){
            // 23 and 24 are the squares in between the king and rook
            if (brd->pieces[92] == e && brd->pieces[93] == e && brd->pieces[94] == e){
                if (!sqAttacked(95, white, brd) && !sqAttacked(94, white, brd)){
                    addQuietMove(brd, move(95, 93, e, e, castleFlag), lst);
                }
            }
        }
    }
}

// Used to bitwise & the brd->castlePerm with every move using these values. This will remove castling permission
// if any pieces move from or land on squares not numbered 15
const int cPerm[120] ={
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 13, 15, 15, 15, 12, 15, 15, 14, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 7, 15, 15, 15, 3, 15, 15, 11, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15
};

static void clearPiece(int sq, Board *brd){
    int pce = brd->pieces[sq];
    int col = pceCol[pce];

    brd->pieces[sq] = e;  // Setting the sq on the board to empty
    brd->material[col] -= pceMat[pce];  // Removing material

    int index = 0;
    for (int i = 0; i < brd->pceNum[pce]; i++){
        if (brd->pieceList[pce][i] == sq){
            index = i;
            break;
        }
    }

    brd->pceNum[pce]--;   // decrementing the pce from pceNum

    brd->pieceList[pce][index] = brd->pieceList[pce][brd->pceNum[pce]];  // Replacing last element with deleted element


    sq = sq120(sq);
    hashPce(pce, sq);  // Hashing the piece out of the key

    if (pce == P || pce == p){  // If the piece is a pawn, remove it from both bitboards
        clearBit(brd->pawns[col], sq);
        clearBit(brd->pawns[2], sq);
    }


}

// Basically the same as clearPiece, except we add a piece.
// Function also takes in pce to add as an argument
static void addPiece(int sq, Board *brd, int pce){

    int col = pceCol[pce];

    brd->pieces[sq] = pce;  // Putting the piece on the board
    brd->material[col] += pceMat[pce];  // Adding material

    brd->pieceList[pce][brd->pceNum[pce]] = sq;  // Adding pce to the pieceList

    brd->pceNum[pce]++;  // Incrementing the pce in pceNum

    sq = sq120(sq);
    hashPce(pce, sq);

    if (pce == P || pce == p){
        setBit(brd->pawns[col], sq);
        setBit(brd->pawns[2], sq);
    }
}

static void movePiece(const int from, const int to, Board *brd){

    int pce = brd->pieces[from];
    int col = pceCol[pce];

    hashPce(pce, from);  // hashing the pce out of the key
    hashPce(pce, to);  // hashing new sq in the key

    brd->pieces[from] = e;  // Setting from sq to empty
    brd->pieces[to] = pce;  // Setting to sq to pce

    if (pce == P || pce == p){  // If pce is a pawn, update bitboards
        clearBit(brd->pawns[col], sq120(from));
        clearBit(brd->pawns[2], sq120(from));
        setBit(brd->pawns[col], sq120(to));
        setBit(brd->pawns[2], sq120(to));
    }

    for (int i = 0; i < brd->pceNum[pce]; i++){
        if (brd->pieceList[pce][i] == from){
            brd->pieceList[pce][i] = to;
            break;
        }
    }
}

bool makeMove(Board *brd, int move){

    int from = fromsq(move);
    int to = tosq(move);
    int side = brd->side;
    int pce = brd->pieces[from];

    brd->history[brd->hisPly].posKey = brd->posKey;  // Adding the posKey to the history array

    if (move & epFlag){
        if (side == white){
            clearPiece(to-10, brd);
        }else{
            clearPiece(to+10, brd);
        }
    }else if (move & castleFlag){
        if (to == 23){
            movePiece(21, 24, brd);
        }else if (to == 93){
            movePiece(91, 94, brd);
        }else if (to == 27){
            movePiece(28, 26, brd);
        }else{
            movePiece(98, 96, brd);
        }
    }

    if (brd->enPas == e){
        hashEp;
    }

    // Hashing castlingPerm out of the key
    hashCa;

    // Storing data in the history array
    brd->history[brd->hisPly].move = move;
    brd->history[brd->hisPly].fiftyMove = brd->fiftyMove;
    brd->history[brd->hisPly].enPas = brd->enPas;
    brd->history[brd->hisPly].castlePerm = brd->castlePerm;

    brd->castlePerm &= cPerm[from];
    brd->castlePerm &= cPerm[to];
    brd->enPas = e;

    // Hashing new castlingPerms in the key
    hashCa;

    int cap = captured(move);
    brd->fiftyMove++;

    if (cap){
        clearPiece(to, brd);
        brd->fiftyMove = 0;
    }

    brd->hisPly++;
    brd->ply++;

    if (pce == P || pce == p){
        brd->fiftyMove = 0;
        if (move & pwnStartFlag){
            if (side == white){
                brd->enPas = from + 10;
            }else{
                brd->enPas = from - 10;
            }
            hashEp;
        }
    }

    movePiece(from, to, brd);

    int promPce = promoted(move);
    if (promPce){
        clearPiece(to, brd);
        addPiece(to, brd, promPce);
    }

    if (pce == K || pce == k){
        brd->kingSq[brd->side] = to;
    }

    brd->side ^= 1;
    hashSide;

    if (sqAttacked(brd->kingSq[side], brd->side, brd)){
        undoMove(brd);
        return false;
    }
    return true;
}


void undoMove(Board *brd){
    brd->hisPly--;
    brd->ply--;

    int move = brd->history[brd->hisPly].move;
    int from = fromsq(move);
    int to = tosq(move);
    int pce = brd->pieces[to];

    // Changing values to previous values in the history array
    brd->castlePerm = brd->history[brd->hisPly].castlePerm;
    brd->fiftyMove = brd->history[brd->hisPly].fiftyMove;
    brd->enPas = brd->history[brd->hisPly].enPas;

    brd->side ^= 1;

    if (move & epFlag){
        if (brd->side == white){
            addPiece(to-10, brd, p);
        }else{
            addPiece(to+10, brd, P);
        }
    }else if (move & castleFlag){
        if (to == 23){
            movePiece(24, 21, brd);
        }else if (to == 93){
            movePiece(94, 91, brd);
        }else if (to == 27){
            movePiece(26, 28, brd);
        }else{
            movePiece(96, 98, brd);
        }
    }

    movePiece(to, from, brd);

    if (pce == K || pce == k){
        brd->kingSq[brd->side] = from;
    }

    int cap = captured(move);
    if (cap){
        addPiece(to, brd, cap);
    }

    if (promoted(move)){
        clearPiece(from, brd);
        addPiece(from, brd, brd->side ? p : P);
    }

    // Updating posKey here so the hashing in movePiece doesn't affect the key
    brd->posKey = brd->history[brd->hisPly].posKey;
}


// TODO: come back later and turn into set
bool isRepetition(Board *brd){
    for (int i = brd->hisPly - brd->fiftyMove; i < brd->hisPly-1; ++i){
        if (brd->posKey == brd->history[i].posKey){
            return true;
        }
    }
    return false;
}


void parseMove(Board *brd, const string& moveStr){
    int from = sq64(algebraicTo64(moveStr.substr(0, 2)));
    int to = sq64(algebraicTo64(moveStr.substr(2, 2)));
    int cap = brd->pieces[to];
    int prom = 0;

    if (moveStr.length() == 5){
        prom = brd->side == white ? 0 : 6;
        switch (moveStr[4]) {
            case 'q':
                prom += Q;
                break;
            case 'n':
                prom += N;
                break;
            case 'b':
                prom += B;
                break;
            default:
                prom += R;
                break;
        }
    }

    int flag = 0;
    if ((brd->pieces[from] == P && (from/10 - 1) == 2 && (to/10 - 1) == 4) ||
    (brd->pieces[from] == p && (from/10 - 1) == 7 && (to/10 - 1) == 5)){
        flag = pwnStartFlag;
    }

    if ((brd->pieces[from] == K && from == 25 && (to == 27 || to == 23)) ||
    (brd->pieces[from] == k && from == 95 && (to == 97 || to == 93))){
        flag = castleFlag;
    }

    if ((brd->pieces[from] == P && to == brd->enPas) || (brd->pieces[from] == p && to == brd->enPas)){
        flag = epFlag;
    }

    makeMove(brd, move(from, to, cap, prom, flag));
}

