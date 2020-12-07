//TODO 120sq brett
//TODO 120sq til 64 sq brett
//TODO printBoard, 1 faktiske verdier, en med brikker (boolean for aa velge.)
//TODO enum brikke til navn
#include <bits/stdc++.h>
#include "defenitions.h"

using namespace std;

#define sq64(sq) sq64sq120[sq]  // bruker sq64sq120 arrayen og produserer en 120 sq
short sq64sq120[64] = {21, 22, 23, 24, 25, 26, 27, 28,
                31, 32, 33, 34, 35, 36, 37, 38,
                41, 42, 43, 44, 45, 46, 47, 48,
                51, 52, 53, 54, 55, 56, 57, 58,
                61, 62, 63, 64, 65, 66, 67, 68,
                71, 72, 73, 74, 75, 76, 77, 78,
                81, 82, 83, 84, 85, 86, 87, 88,
                91, 92, 93, 94, 95, 96, 97, 98};


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

