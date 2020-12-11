
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long u64;

#define standardFen "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

#define fromsq(m) (m & 0x7F)
#define tosq(m) ((m >> 7) & 0x7F)
#define captured(m) ((m >> 14) & 0xF)
#define promoted(m) ((m >> 20) & 0xF)

#define epFlag 0x40000
#define pwnStartFlag 0x80000
#define castleFlag 0x1000000

#define captureFlag 0x7C000
#define promotedFlag 0xF00000

/// Move structure
struct Move{
    int move;
    int score;
};

/// Movelist structure
struct Movelist{
    Move moves[256];
    int count;
};

/// Undo move structure
struct Undo{
    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    u64 posKey;
};

/// Board structure
struct Board{
    int pieces[120];
    u64 pawns[3]; // Bit 0/1: No pawn/pawn, Index 0,1,2 White Pawns/Black pawns/All pawns

    int kingSq[2]; //Where the white and black queen are located. (pos on 120 board).

    int side; //Current side to move
    int enPas; //In the case of a en Passant square.
    int fiftyMove; //Fifty move rule in chess.
    int material[2];

    int ply; //Number of halfmoves.
    int hisPly;

    int castlePerm; // 0 0 0 0 --> BQCA BKCA WQCA WKCA, 0/1 : Al

    u64 posKey; //Unique key corresponding to each unique position.

    int pceNum[13]; //Stores the number of pieces on the board. Empty 0 -> Black King 12.
    int bigPce[3]; //The number of big pieces (not pawn). Index 0,1,2 White Pawns/Black pawns/All pawns
    int majorPce[3]; //The number of rooks/queens. Index 0,1,2 White Pawns/Black pawns/All pawns.
    int minorPce[3]; //The number of bishops/knights. Index 0,1,2 White Pawns/Black pawns/All pawns.

    Undo history[2048]; //Used to storing the history of the game.

    //Tracks the position of pieces. 13: Pieces, 10: Max number of pieces for each type.
    //Example of use: pieceList[whiteKnight ID][index not already occupied] = POSITION
    int pieceList[13][10];

};

/// Board metoder
extern int sq64(int sq);
extern int sq120(int sq);
extern void printBoard(Board *brd);
extern void printBoard120(Board *brd);
extern int algebraicTo64(std::string square);
extern string sq64ToAlgebraic(int sq);
extern bool sqAttacked(int sq, int side, Board *brd);
extern void printSqAttacked(int side, Board *brd);


/// Bit board metoder
extern void printBitBoard(u64 bitBoard);
extern void setBit(u64 &bitBoard, int sq);
extern void clearBit(u64 &bitBoard, int sq);


/// Hashkey metoder
extern u64 rand64();
extern u64 generateHash(Board *brd);

/// Hashkey containers
extern u64 pieceKeys[13][64];
extern u64 sideKey;
extern u64 castleKeys[16];

/// Move metoder
extern void printMove(int move);
extern void generateLegalMoves(Board *brd, Movelist *lst);
extern bool makeMove(Board *brd, int move);
extern void undoMove(Board *brd);

/// Evalutaion metoder
extern int mainEval(Board *brd);

/// Inits
extern void allInits(Board *brd);
extern void resetBoard(Board *brd);
extern void initBitMasks();
extern void initHashkeys();
extern void FENBoardUpdater(Board *brd, const std::string& fen=standardFen);


enum sideToMove : short {white, black};
enum castlingRights : short {WKC = 1, WQC = 2, BKC = 4, BQC = 8};
enum pieceValues : short {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};

extern const int pceMat[13];

/// Piece directions
extern const int NDir[8];
extern const int RDir[4];
extern const int BDir[4];
extern const int KDir[8];

///Test methods
extern void sq64ToAlgebraicTEST();
extern void printMoveList(const Movelist *lst);

/// Perft test methods
extern void perft(int depth, Board *brd);
extern void perftTest(int depth, Board *brd);


