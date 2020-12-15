
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long u64;

#define standardFen "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define maxdepth 64

#define fromsq(m) (m & 0x7F)
#define tosq(m) ((m >> 7) & 0x7F)
#define captured(m) ((m >> 14) & 0xF)
#define promoted(m) ((m >> 20) & 0xF)


#define epFlag 0x40000
#define pwnStartFlag 0x80000
#define castleFlag 0x1000000

#define captureFlag 0x7C000
#define promotedFlag 0xF00000

#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) )

/// Searchinfo structure
struct Searchinfo{

    int starttime;
    int stoptime;
    int depth;
    int depthset;
    int timeset;
    int movestogo;
    int infinite;

    long nodes;

    bool quit;
    bool stopped;

    float fh;
    float fhf;
};

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
    int material[2];  // Material

    int ply; //Number of halfmoves.
    int hisPly;

    int castlePerm; // 0 0 0 0 --> BQCA BKCA WQCA WKCA, 0/1 : Al

    u64 posKey; //Unique key corresponding to each unique position.

    int pceNum[13]; //Stores the number of pieces on the board. Empty 0 -> Black King 12.

    Undo history[2048]; //Used to storing the history of the game.

    //Tracks the position of pieces. 13: Pieces, 10: Max number of pieces for each type.
    //Example of use: pieceList[whiteKnight ID][index not already occupied] = POSITION
    int pieceList[13][10];

    double midMultiplier = 1;
    double endMultiplier = 0;

    unordered_map<u64, int> pvTable;
    int pvArray[maxdepth];

    int searchHistory[13][120];
    int searchKillers[2][maxdepth];

};

/// Board metoder
extern int sq64(int sq);  // Converting a sq64 to sq120
extern int sq120(int sq);  // Converting a sq120 to sq64
extern void printBoard(Board *brd);  // printing the board to the console
extern void printBoard120(Board *brd);  // printing the 120 board to the console
extern int algebraicTo64(std::string square);  // turns a sq like a4 to 3
extern string sq64ToAlgebraic(int sq);  // turns a sq like 3 to a4
extern bool sqAttacked(int sq, int side, Board *brd);  // return true if a sq is attacked by a side
extern void printSqAttacked(int side, Board *brd);  // prints all sq's that are attacked by a side


/// Bit board metoder
extern void printBitBoard(u64 bitBoard);  // prints the bitBoard to the console
extern void setBit(u64 &bitBoard, int sq);  // sets a specific bit in the bitboard to 1
extern void clearBit(u64 &bitBoard, int sq);  // sets a specific bit in the bitboard to 0


/// Hashkey metoder
extern u64 rand64();  // generates a random 64 bit number
extern u64 generateHash(Board *brd);    // Generates a unique key for a position. Only run once when board is init

/// Hashkey containers
// These arrays store random numbers used to generate the key and update the key
extern u64 pieceKeys[13][64];
extern u64 sideKey;
extern u64 castleKeys[16];

/// Move metoder
extern void printMove(int move);  // takes in a move (32 bit number) and prints it in this format: a2a3
extern void generateLegalMoves(Board *brd, Movelist *lst);  // generates all legal moves for a position
extern void generateLegalCaptures(Board *brd, Movelist *lst);
extern bool makeMove(Board *brd, int move);  // Makes the move and updates board info
extern void undoMove(Board *brd);  // Takes the move back and reverts board info
extern void makeNullMove(Board *brd);
extern void undoNullMove(Board *brd);
extern int parseMove(Board *brd, const string& move);
extern bool isRepetition(Board *brd);
extern void initMvvLva();

/// Search metoder
extern int searchPosition(Board *brd, Searchinfo *info);

/// Evalutaion metoder
extern int mainEval(Board *brd);  // The main eval, all minor eval functions goes here
extern void initFilesRanksBrd();
extern void initEvalMasks();

/// Inits
// This isn't really used yet
extern void allInits(Board *brd);
extern void resetBoard(Board *brd);
extern void initBitMasks();
extern void initHashkeys();
extern void FENBoardUpdater(Board *brd, const std::string& fen=standardFen);

/// pvTable metoder
extern void storePVMove(Board *brd, int move);
extern int probePVTable(Board *brd);
extern int getPVLine(int depth, Board *brd);

/// Misc metoder
extern int getTime();
extern void playerMenu(Board *brd, Searchinfo *info);

/// Piece directions
// initializing piece direction arrays
extern const int NDir[8];
extern const int RDir[4];
extern const int BDir[4];
extern const int KDir[8];

///Test methods
extern void sq64ToAlgebraicTEST();
extern void printMoveList(const Movelist *lst);  // Prints every move in the movelist

/// Perft test methods
extern void perft(int depth, Board *brd);  // Used in perftTest
extern void perftTest(int depth, Board *brd);  // Finds out how many positions you can reach from a position to a depth


enum sideToMove : short {white, black};
enum castlingRights : short {WKC = 1, WQC = 2, BKC = 4, BQC = 8};
enum pieceValues : short {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};
enum files : short {FA, FB, FC, FD, FE, FF, FG, FH};
enum ranks : short {R1, R2, R3, R4, R5, R6, R7, R8};


extern const int pceMat[13];

/// UCI
void uciCommunication();
