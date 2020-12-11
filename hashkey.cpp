
#include "defenitions.h"

u64 rand64(){
    u64 n = (u64)rand() + ((u64)rand() << 15) + ((u64)rand() << 30) + ((u64)rand() << 45) + (((u64)rand() & 0xf) << 60);
    return n;
}

u64 pieceKeys[13][64];
u64 sideKey;
u64 castleKeys[16];

void initHashkeys(){

    for (int pce = 0; pce < 13; pce++){
        for (int sq = 0; sq < 64; sq++){
            pieceKeys[pce][sq] = rand64();
        }
    }

    sideKey = rand64();

    for (int i = 0; i < 16; i++){
        castleKeys[i] = rand64();
    }
}


u64 generateHash(Board *brd){
    u64 key = 0;
    int piece;

    for (int i = 0; i < 64; i++){
        piece = brd->pieces[sq64(i)];
        if (piece != e){
            key ^= pieceKeys[piece][i];
        }
    }

    if (brd->side == white){
        key ^= sideKey;
    }

    if (brd->enPas != e){
        key ^= pieceKeys[e][sq64(brd->enPas)];
    }

    key ^= castleKeys[brd->castlePerm];

    return key;
}

