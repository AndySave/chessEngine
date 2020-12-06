
typedef unsigned long long u64;

// Undo move structure
typedef struct{
    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    u64 posKey;
} Undo;

// Board structure
typedef struct{
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

} Board;

// Board methods
extern void printBoard120(Board *brd);




enum pieceValues : short {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};
extern Board board;

