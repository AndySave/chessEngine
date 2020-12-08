
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long u64;

#define standardFen "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

// Undo move structure
struct Undo{
    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    u64 posKey;
};

// Board structure
struct Board{
    int pieces[120];
    u64 pawns[3];

    int kingSq[2];

    int side;
    int enPas;
    int fiftyMove;
    int material[2];

    int ply;
    int hisPly;

    int castlePerm;

    u64 posKey;

    int pceNum[13];
    int bigPce[3];
    int majPce[3];
    int minPce[3];

    Undo history[2048];

    int pieceList[13][10];

};

// Board metoder
extern int sq64(int sq);
extern void printBoard(Board *brd);
extern void printBoard120(Board *brd);
extern int algebraicTo64(std::string square);
extern bool sqAttacked(int sq, int side, Board *brd);
extern void printSqAttacked(int side, Board *brd);


// Bit board metoder
extern void printBitBoard(u64 bitBoard);
extern void setBit(u64 &bitBoard, short sq);
extern void clearBit(u64 &bitBoard, short sq);


// Hashkey metoder
extern u64 rand64();
extern u64 generateHash(Board *brd);
extern void FENBoardUpdater(Board *brd, std::string fen=standardFen);

// Inits
extern void allInits(Board *brd);
extern void resetBoard(Board *brd);
extern void initBitMasks();
extern void initHashkeys();


enum sideToMove : short {white, black};
enum castlingRights : short {WKC = 1, WQC = 2, BKC = 4, BQC = 8};
enum pieceValues : short {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};

extern const int pceMat[13];

// Piece directions
extern const int NDir[8];
extern const int RDir[4];
extern const int BDir[4];
extern const int KDir[8];


