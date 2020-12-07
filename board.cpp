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
        brd->pieces[sq64(i)] = e;
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
            cout << pieceChars[brd->pieces[sq64(rank*8 + file)]] << " ";

            if ((file + 1) % 8 == 0){
                cout << endl;
            }
        }
    }
}



///// BITBOARD FUNKSJONER \\\\\

// Finner boender og initialiserer bitBoard
void initBitBoard(Board *brd){
    u64 shiftVar = 1;
    // wp = white pawns | bp = black pawns
    u64 wp = 0;
    u64 bp = 0;

    for (int i = 0; i < 64; i++){
        if (brd->pieces[sq64(i)] == P){
            wp |= shiftVar << i;
        }
        else if (brd->pieces[sq64(i)] == p){
            bp |= shiftVar << i;
        }
    }
    // ap = all pawns
    u64 ap = wp | bp;

    brd->pawns[0] = wp;
    brd->pawns[1] = bp;
    brd->pawns[2] = ap;
}

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

void FENBoardUpdater(Board *board, string fen) {
    //rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
    //rnbqkbnr/pp2pppp/8/2p5/2pPP3/8/PPP2PPP/RNBQK1NR w KQkq - 0 4

    vector<string> elements(6);
    int c = 0;
    for (int i = 0; i<fen.size(); i++) {
        if (fen[i] == ' ') {
            c++;
            continue;
        }
        elements[c] += fen[i];
    }
    for (string s : elements) {
        cout << s << endl;
    }

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
    string SSSSSS = "";
    SSSSSS+= chessBoard.substr(56,8);
    SSSSSS+= chessBoard.substr(48,8);
    SSSSSS+= chessBoard.substr(40,8);
    SSSSSS+= chessBoard.substr(32,8);
    SSSSSS+= chessBoard.substr(24,8);
    SSSSSS+= chessBoard.substr(16,8);
    SSSSSS+= chessBoard.substr(8,8);
    SSSSSS+= chessBoard.substr(0,8);
    cout << SSSSSS.length() << endl;


    int i = 0;
    for (char c : SSSSSS) {
        short v;
        switch (c) {
            case 'e':
                v = e;
                break;
            case 'P':
                v = P;
                break;
            case 'N':
                v = N;
                break;
            case 'B':
                v = B;
                break;
            case 'R':
                v = R;
                break;
            case 'Q':
                v = Q;
                break;
            case 'K':
                v = K;
                break;
            case 'p':
                v = p;
                break;
            case 'n':
                v = n;
                break;
            case 'b':
                v = b;
                break;
            case 'r':
                v = r;
                break;
            case 'q':
                v = q;
                break;
            case 'k':
                v = k;
                break;
            default:
                v = o;
                break;
        }
        board->pieces[sq64sq120[i]] = v;
        i++;
    }
    cout << chessBoard << endl << endl;
}


