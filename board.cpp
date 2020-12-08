//TODO 120sq brett
//TODO 120sq til 64 sq brett
//TODO printBoard, 1 faktiske verdier, en med brikker (boolean for aa velge.)
//TODO enum brikke til navn
#include <bits/stdc++.h>
#include "defenitions.h"

using namespace std;

short sq64sq120[64] = {21, 22, 23, 24, 25, 26, 27, 28,
                       31, 32, 33, 34, 35, 36, 37, 38,
                       41, 42, 43, 44, 45, 46, 47, 48,
                       51, 52, 53, 54, 55, 56, 57, 58,
                       61, 62, 63, 64, 65, 66, 67, 68,
                       71, 72, 73, 74, 75, 76, 77, 78,
                       81, 82, 83, 84, 85, 86, 87, 88,
                       91, 92, 93, 94, 95, 96, 97, 98};

int sq64(int sq){
    return sq64sq120[sq];
}


// Toemmer brettet
// Viktig: Maa kalle denne funksjonen naar man initialiserer brettet for aa
// definere offboard rutene
void resetBoard(Board *brd){
    for (int & piece : brd->pieces){
        piece = o;
    }
    for (int i = 0; i < 64; i++){
        (*brd).pieces[sq64(i)] = e;
    }
}

// Printer 120 brettets eksakte verdier
void printBoard120(Board *brd){
    for (int i = 0; i < 120; i++){
        cout << brd->pieces[i] << " ";
        if ((i+1) % 10 == 0){
            cout << endl;
        }
    }
}

void printBoard(Board *brd) {
    string pieceChars[13] = {".", "P", "N", "B", "R", "Q", "K",
                             "p", "n", "b", "r", "q", "k"};

    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            cout << pieceChars[(*brd).pieces[sq64(rank*8 + file)]] << " ";

            if ((file + 1) % 8 == 0){
                cout << endl;
            }
        }
    }
    cout << "side: " << ((brd->side == 0) ? 'w' : 'b') << endl;
    cout << "enPas: " << brd->enPas << endl;

    // Handling castling permissions
    string cp;
    if (brd->castlePerm & WKC) { cp += 'K';}
    if (brd->castlePerm & WQC) { cp += 'Q';}
    if (brd->castlePerm & BKC) { cp += 'k';}
    if (brd->castlePerm & BQC) { cp += 'q';}
    cout << "castle: " << (cp.empty() ? "-" : cp) << endl;

    cout << "key: " << brd->posKey << endl;
}

const int pceMat[13] = {0, 100, 325, 325, 500, 1000, 60000, 100, 325, 325, 500, 1000, 60000};
// Iterates through the board and sets different data: material, number of pieces, king sq, bitboard info
void initBoardValues(Board *brd){
    int piece;
    for (short sq = 0; sq < 64; sq++) {
        piece = brd->pieces[sq64(sq)];
        if (piece == e){continue;}

        // piece must be white if piece is <= K
        if (piece <= K) {
            brd->material[white] += pceMat[piece];
        }else{
            brd->material[black] += pceMat[piece];
        }

        // incrementing number of pieces
        brd->pceNum[piece]++;
        // TODO: find out how pieceList works and add pieces to it

        // saving pos of kings
        if (piece == K) { brd->kingSq[0] = sq64(sq); }
        if (piece == k) { brd->kingSq[1] = sq64(sq); }

        // adding pawns to bitboards
        if (piece == P){
            setBit(brd->pawns[white], sq);
            setBit(brd->pawns[2], sq);
        }else if (piece == p){
            setBit(brd->pawns[black], sq);
            setBit(brd->pawns[2], sq);
        }

    }

}


// Initializes the board
void FENBoardUpdater(Board *brd, string fen) {
    //rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
    //rnbqkbnr/pp2pppp/8/2p5/2pPP3/8/PPP2PPP/RNBQK1NR w KQkq - 0 4


    // Resetter brettet og legger til offboard squares
    resetBoard(brd);

    vector<string> elements(6);
    int c = 0;
    for (char i : fen) {
        if (i == ' ') {
            c++;
            continue;
        }
        elements[c] += i;
    }
    int castlePerm = 0;
    for (char c : elements[2]) {
        switch (c) {
            case 'k': castlePerm |= BKC; break;
            case 'K': castlePerm |= WKC; break;
            case 'Q': castlePerm |= WQC; break;
            case 'q': castlePerm |= BQC; break;
            default : break;
        }
    }
    brd->castlePerm = castlePerm;

    brd->fiftyMove = elements[4][0] - '0';

    brd->ply = elements[5][0] - '0';

    brd->side = (elements[1] == "w") ? 0 : 1;

    //Sets en Passant square.
    if (elements[3][0] == '-') {
        brd->enPas = 0;
    } else {
        brd->enPas = sq64(algebraicTo64(elements[3]));
    }

    //Sets the chessboard string used to set the chessboard.
    string chessBoard = "";
    for (char c : elements[0]) {
        if (c < 60) {
            int empties = c - '0';
            for (int i = 0; i<empties; i++) {
                chessBoard += 'e';
            }
        } else if (c != '/') {
            chessBoard += c;
        }
    }

    //Sets the board to right integers.
    int squareNr[64];
    int C = 0;
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int sq = (rank * 8 + file);
            squareNr[C] = sq;
            C++;
        }
    }
    int i = 0;
    for (char c : chessBoard) {
        short v;
        switch (c) {
            case 'e': v = e; break;
            case 'P': v = P; break;
            case 'N': v = N; break;
            case 'B': v = B; break;
            case 'R': v = R; break;
            case 'Q': v = Q; break;
            case 'K': v = K; break;
            case 'p': v = p; break;
            case 'n': v = n; break;
            case 'b': v = b; break;
            case 'r': v = r; break;
            case 'q': v = q; break;
            case 'k': v = k; break;
            default : v = o; break;
        }
        brd->pieces[sq64sq120[squareNr[i]]] = v;
        i++;
    }

    // Updating hash key
    brd->posKey = generateHash(brd);

    // Updating board values
    initBoardValues(brd);
}

int algebraicTo64(string square) {
    /* This function turns a square from algebraic to 64-board notation.
     * Example: a1 --> 0
     */
    int row = square[1] - '0';
    int col = square[0] - 96;
    return (row-1) * 8 + col - 1;
}

//Hva er dette?
const int NDir[8] = {-8, -19, -21, -12, 8, 19, 21, 12};
const int RDir[4] = {-1, -10, 1, 10};
const int BDir[4] = {-9, -11, 11, 9};
const int KDir[8] = {-1, -10, 1, 10, -9, -11, 11, 9};


bool sqAttacked(int sq, int side, Board *brd){
    int pce, tSq, dir;
    if (side == white){
        // Checking for pawns
        if (brd->pieces[sq-11] == P || brd->pieces[sq-9] == P){
            return true;
        }

        // Checking knight directions
        for (int i : NDir){
            pce = brd->pieces[sq + i];
            if (pce == N){
                return true;
            }
        }

        // Checking for rooks and queens
        for (int i : RDir){
            dir = i;
            tSq = sq + dir;
            pce = brd->pieces[tSq];
            while (pce != o){
                if (pce != e){
                    if (pce == R || pce == Q){
                        return true;
                    }
                    break;
                }
                tSq += dir;
                pce = brd->pieces[tSq];
            }
        }

        // Checking for bishops and queens
        for (int i : BDir){
            dir = i;
            tSq = sq + dir;
            pce = brd->pieces[tSq];
            while (pce != o){
                if (pce != e){
                    if (pce == B || pce == Q){
                        return true;
                    }
                    break;
                }
                tSq += dir;
                pce = brd->pieces[tSq];
            }
        }

        // Checking for king
        for (int i : KDir){
            pce = brd->pieces[sq + i];
            if (pce == K){
                return true;
            }
        }

    }else{
        // Checking for pawns
        if (brd->pieces[sq+11] == p || brd->pieces[sq+9] == p){
            return true;
        }

        // Checking knight directions
        for (int i : NDir){
            pce = brd->pieces[sq + i];
            if (pce == n){
                return true;
            }
        }

        // Checking for rooks and queens
        for (int i : RDir){
            dir = i;
            tSq = sq + dir;
            pce = brd->pieces[tSq];
            while (pce != o){
                if (pce != e){
                    if (pce == r || pce == q){
                        return true;
                    }
                    break;
                }
                tSq += dir;
                pce = brd->pieces[tSq];
            }
        }

        // Checking for bishops and queens
        for (int i : BDir){
            dir = i;
            tSq = sq + dir;
            pce = brd->pieces[tSq];
            while (pce != o){
                if (pce != e){
                    if (pce == b || pce == q){
                        return true;
                    }
                    break;
                }
                tSq += dir;
                pce = brd->pieces[tSq];
            }
        }

        // Checking for king
        for (int i : KDir){
            pce = brd->pieces[sq + i];
            if (pce == k){
                return true;
            }
        }
    }
    return false;
}

void printSqAttacked(int side, Board *brd){
    for (int rank = 7; rank >= 0; rank--){
        for (int file = 0; file < 8; file++){
            if (sqAttacked(sq64((rank*8)+file) ,side, brd)){
                cout << "x ";
            }else{
                cout << "- ";
            }
        }
        cout << endl;
    }
}

///// BITBOARD FUNKSJONER \\\\\

void printBitBoard(u64 bitBoard){
    u64 shiftVar = 1;

    for (int rank = 7; rank >= 0; rank--){
        for (int file = 0; file < 8; file++){
            u64 sq = shiftVar << (rank*8 + file);
            if (sq & bitBoard){
                cout << "X ";
            }else{
                cout << "- ";
            }

            if ((rank*8 + file + 1) % 8 == 0){
                cout << endl;
            }
        }
    }
}

u64 setMask[64];
u64 clearMask[64];
void initBitMasks(){
    for (u64 &i : setMask){
        i = 0ULL;
    }

    for (int i = 0; i < 64; i++){
        u64 b = 1ULL << i;
        setMask[i] |= b;
        clearMask[i] = ~setMask[i];
    }
}

void setBit(u64 &bitBoard, short sq){
    bitBoard |= setMask[sq];
}

void clearBit(u64 &bitBoard, short sq){
    bitBoard &= clearMask[sq];
}

