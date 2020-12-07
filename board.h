
typedef long long ll;
typedef unsigned long long u64;

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

    int ply;
    int hisPly;

    u64 posKey;

    int pceNum[13];
    int bigPce[3];
    int majPce[3];
    int minPce[3];

    Undo history[2048];

    int pieceList[13][10];

};

// Board metoder
extern void printBoard(Board *brd, bool betterPieces);
extern void printBoard120(Board *brd);
extern void resetBoard(Board *brd);


// Bit board metoder
extern void initBitBoard(Board *brd);
extern void printBitBoard(u64 bitBoard);
extern void initBitMasks();
extern void setBit(u64 &bitBoard, short sq);
extern void clearBit(u64 &bitBoard, short sq);


enum pieceValues : short {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};


