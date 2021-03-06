#include "defenitions.h"

const int Mirror64[64] = {
        56	,	57	,	58	,	59	,	60	,	61	,	62	,	63	,
        48	,	49	,	50	,	51	,	52	,	53	,	54	,	55	,
        40	,	41	,	42	,	43	,	44	,	45	,	46	,	47	,
        32	,	33	,	34	,	35	,	36	,	37	,	38	,	39	,
        24	,	25	,	26	,	27	,	28	,	29	,	30	,	31	,
        16	,	17	,	18	,	19	,	20	,	21	,	22	,	23	,
        8	,	9	,	10	,	11	,	12	,	13	,	14	,	15	,
        0	,	1	,	2	,	3	,	4	,	5	,	6	,	7
};

const int allTables[13][64][3] = {
        {//Pawn
                {0, 0}, {0 , 0}, {0, 0}, {0 , 0}, {0, 0}, {0 , 0}, {0, 0}, {0 , 0}
                ,{3,  -10}, {3,    -6}, {10,  10}, {19,   0}, {16,  14}, {19,   7}, {7,   -5}, {-5, -19}
                ,{-9, -10}, {-15, -10}, {11, -10}, {15,   4}, {32,   4}, {22,   3}, {5,   -6}, {-22, -4}
                ,{-4,   6}, {-23,  -2}, {6,   -8}, {20,  -4}, {40, -13}, {17, -12}, {4,  -10}, {-8,  -9}
                ,{13,  10}, {0,     5}, {-13,  4}, {1,   -5}, {11,  -5}, {-2,  -5}, {-13, 14}, {5,    9}
                ,{5,   28}, {-12,  20}, {-7,  21}, {22,  28}, {-8,  30}, {-5,   7}, {-15,  6}, {-8,  13}
                ,{-7,   0}, {7,   -11}, {-3,  12}, {-13, 21}, {5,   25}, {-16, 19}, {10,   4}, {-8,   7}
        },
        {//Pawn
            {0, 0}, {0 , 0}, {0, 0}, {0 , 0}, {0, 0}, {0 , 0}, {0, 0}, {0 , 0}
            ,{3,  -10}, {3,    -6}, {10,  10}, {19,   0}, {16,  14}, {19,   7}, {7,   -5}, {-5, -19}
            ,{-9, -10}, {-15, -10}, {11, -10}, {15,   4}, {32,   4}, {22,   3}, {5,   -6}, {-22, -4}
            ,{-4,   6}, {-23,  -2}, {6,   -8}, {20,  -4}, {40, -13}, {17, -12}, {4,  -10}, {-8,  -9}
            ,{13,  10}, {0,     5}, {-13,  4}, {1,   -5}, {11,  -5}, {-2,  -5}, {-13, 14}, {5,    9}
            ,{5,   28}, {-12,  20}, {-7,  21}, {22,  28}, {-8,  30}, {-5,   7}, {-15,  6}, {-8,  13}
            ,{-7,   0}, {7,   -11}, {-3,  12}, {-13, 21}, {5,   25}, {-16, 19}, {10,   4}, {-8,   7}
        },
        {//Knight
                {-175,  -96}, {-92, -65}, {-74, -49}, {-73, -21}, {-73, -21}, {-74, -49}, {-92, -65}, {-175,  -96}
                ,{-77,   -67}, {-41, -54}, {-27, -18}, {-15,   8}, {-15,   8}, {-27, -18}, {-41, -54}, {-77,   -67}
                ,{-61,   -40}, {-17, -27}, {6,    -8}, {12,   29}, {12,   29}, {6,    -8}, {-17, -27}, {-61,   -40}
                ,{-35,   -35}, {8,    -2}, {40,   13}, {49,   28}, {49,   28}, {40,   13}, {8,    -2}, {-35,   -35}
                ,{-34,   -45}, {13,  -16}, {44,    9}, {51,   39}, {51,   39}, {44,    9}, {13,  -16}, {-34,   -45}
                ,{-9,    -51}, {22,  -44}, {58,  -16}, {53,   17}, {53,   17}, {58,  -16}, {22,  -44}, {-9,    -51}
                ,{-67,   -69}, {-27, -50}, {4,   -51}, {37,   12}, {37,   12}, {4,   -51}, {-27, -50}, {-67,   -69}
                ,{-201, -100}, {-83, -88}, {-56, -56}, {-26, -17}, {-26, -17}, {-56, -56}, {-83, -88}, {-201, -100}
        }, {//Bishop
                {-53, -57}, {-5, -30}, {-8,  -37}, {-23, -12}, {-23, -12}, {-8,  -37}, {-5, -30}, {-53, -57}
                ,{-15, -37}, {8,  -13}, {19,  -17}, {4,     1}, {4,     1}, {19,  -17}, {8,  -13}, {-15, -37}
                ,{-7,  -16}, {21,  -1}, {-5,   -2}, {17,   10}, {17,   10}, {-5,   -2}, {21,  -1}, {-7,  -16}
                ,{-5,  -20}, {11,  -6}, {25,    0}, {39,   17}, {39,   17}, {25,    0}, {11,  -6}, {-5,  -20}
                ,{-12, -17}, {29,  -1}, {22,  -14}, {31,   15}, {31,   15}, {22,  -14}, {29,  -1}, {-12, -17}
                ,{-16, -30}, {6,    6}, {1,     4}, {11,    6}, {11,    6}, {1,     4}, {6,    6}, {-16, -30}
                ,{-17, -31}, {-14,-20}, {5,    -1}, {0,     1}, {0,     1}, {5,    -1}, {-14,-20}, {-17, -31}
                ,{-48, -46}, {1,  -42}, {-14, -37}, {-23, -24}, {-23, -24}, {-14, -37}, {1,  -42},{-48, -46}
        }, { //Rook
                {-31, -9}, {-20, -13}, {-14, -10}, {-5, -9}, {-5, -9}, {-14, -10}, {-20, -13}, {-31, -9}
                ,{-21,-12}, {-13,  -9}, { -8,  -1}, {6, -2 }, {6, -2 }, { -8,  -1}, {-13,  -9}, {-21,-12}
                ,{-25,  6}, {-11,  -8}, {-1,   -2}, { 3, -6}, { 3, -6}, {-1,   -2}, {-11,  -8}, {-25,  6}
                ,{-13, -6}, {-5,    1}, {-4,   -9}, {-6, 7 }, {-6, 7 }, {-4,   -9}, {-5,    1}, {-13, -6}
                ,{-27, -5}, {-15,   8}, {-4,    7}, {3, -6 }, {3, -6 }, {-4,    7}, {-15,   8}, {-27, -5}
                ,{-22,  6}, {-2,    1}, {6,    -7}, {12, 10}, {12, 10}, {6,    -7}, {-2,    1}, {-22,  6}
                ,{-2,   4}, {12,    5}, {16,   20}, {18, -5}, {18, -5}, {16,   20}, {12,    5}, {-2,   4}
                ,{-17, 18}, {-19,   0}, {-1,   19}, {9, 13 }, {9, 13 }, {-1,   19}, {-19,   0}, {-17, 18}
        }, {//Queen
                { 3,-69}, {-5,-57}, {-5,-47}, { 4,-26}, { 4,-26}, {-5,-47}, {-5,-57}, { 3,-69}
                ,{-3,-55}, { 5,-31}, { 8,-22}, {12, -4}, {12, -4}, { 8,-22}, { 5,-31}, {-3,-55}
                ,{-3,-39}, { 6,-18}, {13, -9}, { 7,  3}, { 7,  3}, {13, -9}, { 6,-18}, {-3,-39}
                ,{ 4,-23}, { 5, -3}, { 9, 13}, { 8, 24}, { 8, 24}, { 9, 13}, { 5, -3}, { 4,-23}
                ,{ 0,-29}, { 14, -6}, {12,  9}, { 5, 21}, { 5, 21}, {12,  9}, { 14, -6}, { 0,-29}
                ,{-4,-38}, { 10,-18}, { 6,-12}, { 8,  1}, { 8,  1}, { 6,-12}, { 10,-18}, {-4,-38}
                ,{-5,-50}, { 6, -27}, {10,-24}, { 8, -8}, { 8, -8}, {10,-24}, { 6, -27}, {-5,-50}
                ,{-2,-75}, {-2, -52}, { 1,-43}, {-2,-36}, {-2,-36}, { 1,-43}, {-2, -52},{-2,-75}
        }, {//King
                {271,  1}, {327, 45}, {271, 85}, {198, 76}, {198, 76}, {271, 85}, {327, 45}, {271,  1}
                ,{278, 53}, {303,100}, {234,133}, {179,135}, {179,135}, {234,133}, {303,100}, {278, 53}
                ,{195, 88}, {258,130}, {169,169}, {120,175}, {120,175}, {169,169}, {258,130}, {195, 88}
                ,{164,103}, {190,156}, {138,172}, { 98,172}, { 98,172}, {138,172}, {190,156}, {164,103}
                ,{154, 96}, {179,166}, {105,199}, { 70,199}, { 70,199}, {105,199}, {179,166}, {154, 96}
                ,{123, 92}, {145,172}, { 81,184}, { 31,191}, { 31,191}, { 81,184}, {145,172}, {123, 92}
                ,{ 88, 47}, {120,121}, { 65,116}, { 33,131}, { 33,131}, { 65,116}, {120,121}, { 88, 47}
                ,{ 59, 11}, { 89, 59}, { 45, 73}, { -1, 78}, { -1, 78}, { 45, 73}, { 89, 59}, { 59, 11}
        },
        {//Pawn
                {0, 0}, {0 , 0}, {0, 0}, {0 , 0}, {0, 0}, {0 , 0}, {0, 0}, {0 , 0}
                ,{3,  -10}, {3,    -6}, {10,  10}, {19,   0}, {16,  14}, {19,   7}, {7,   -5}, {-5, -19}
                ,{-9, -10}, {-15, -10}, {11, -10}, {15,   4}, {32,   4}, {22,   3}, {5,   -6}, {-22, -4}
                ,{-4,   6}, {-23,  -2}, {6,   -8}, {20,  -4}, {40, -13}, {17, -12}, {4,  -10}, {-8,  -9}
                ,{13,  10}, {0,     5}, {-13,  4}, {1,   -5}, {11,  -5}, {-2,  -5}, {-13, 14}, {5,    9}
                ,{5,   28}, {-12,  20}, {-7,  21}, {22,  28}, {-8,  30}, {-5,   7}, {-15,  6}, {-8,  13}
                ,{-7,   0}, {7,   -11}, {-3,  12}, {-13, 21}, {5,   25}, {-16, 19}, {10,   4}, {-8,   7}
        },
        {//Knight
                {-175,  -96}, {-92, -65}, {-74, -49}, {-73, -21}, {-73, -21}, {-74, -49}, {-92, -65}, {-175,  -96}
                ,{-77,   -67}, {-41, -54}, {-27, -18}, {-15,   8}, {-15,   8}, {-27, -18}, {-41, -54}, {-77,   -67}
                ,{-61,   -40}, {-17, -27}, {6,    -8}, {12,   29}, {12,   29}, {6,    -8}, {-17, -27}, {-61,   -40}
                ,{-35,   -35}, {8,    -2}, {40,   13}, {49,   28}, {49,   28}, {40,   13}, {8,    -2}, {-35,   -35}
                ,{-34,   -45}, {13,  -16}, {44,    9}, {51,   39}, {51,   39}, {44,    9}, {13,  -16}, {-34,   -45}
                ,{-9,    -51}, {22,  -44}, {58,  -16}, {53,   17}, {53,   17}, {58,  -16}, {22,  -44}, {-9,    -51}
                ,{-67,   -69}, {-27, -50}, {4,   -51}, {37,   12}, {37,   12}, {4,   -51}, {-27, -50}, {-67,   -69}
                ,{-201, -100}, {-83, -88}, {-56, -56}, {-26, -17}, {-26, -17}, {-56, -56}, {-83, -88}, {-201, -100}
        }, {//Bishop
                {-53, -57}, {-5, -30}, {-8,  -37}, {-23, -12}, {-23, -12}, {-8,  -37}, {-5, -30}, {-53, -57}
                ,{-15, -37}, {8,  -13}, {19,  -17}, {4,     1}, {4,     1}, {19,  -17}, {8,  -13}, {-15, -37}
                ,{-7,  -16}, {21,  -1}, {-5,   -2}, {17,   10}, {17,   10}, {-5,   -2}, {21,  -1}, {-7,  -16}
                ,{-5,  -20}, {11,  -6}, {25,    0}, {39,   17}, {39,   17}, {25,    0}, {11,  -6}, {-5,  -20}
                ,{-12, -17}, {29,  -1}, {22,  -14}, {31,   15}, {31,   15}, {22,  -14}, {29,  -1}, {-12, -17}
                ,{-16, -30}, {6,    6}, {1,     4}, {11,    6}, {11,    6}, {1,     4}, {6,    6}, {-16, -30}
                ,{-17, -31}, {-14,-20}, {5,    -1}, {0,     1}, {0,     1}, {5,    -1}, {-14,-20}, {-17, -31}
                ,{-48, -46}, {1,  -42}, {-14, -37}, {-23, -24}, {-23, -24}, {-14, -37}, {1,  -42},{-48, -46}
        }, { //Rook
                {-31, -9}, {-20, -13}, {-14, -10}, {-5, -9}, {-5, -9}, {-14, -10}, {-20, -13}, {-31, -9}
                ,{-21,-12}, {-13,  -9}, { -8,  -1}, {6, -2 }, {6, -2 }, { -8,  -1}, {-13,  -9}, {-21,-12}
                ,{-25,  6}, {-11,  -8}, {-1,   -2}, { 3, -6}, { 3, -6}, {-1,   -2}, {-11,  -8}, {-25,  6}
                ,{-13, -6}, {-5,    1}, {-4,   -9}, {-6, 7 }, {-6, 7 }, {-4,   -9}, {-5,    1}, {-13, -6}
                ,{-27, -5}, {-15,   8}, {-4,    7}, {3, -6 }, {3, -6 }, {-4,    7}, {-15,   8}, {-27, -5}
                ,{-22,  6}, {-2,    1}, {6,    -7}, {12, 10}, {12, 10}, {6,    -7}, {-2,    1}, {-22,  6}
                ,{-2,   4}, {12,    5}, {16,   20}, {18, -5}, {18, -5}, {16,   20}, {12,    5}, {-2,   4}
                ,{-17, 18}, {-19,   0}, {-1,   19}, {9, 13 }, {9, 13 }, {-1,   19}, {-19,   0}, {-17, 18}
        }, {//Queen
                { 3,-69}, {-5,-57}, {-5,-47}, { 4,-26}, { 4,-26}, {-5,-47}, {-5,-57}, { 3,-69}
                ,{-3,-55}, { 5,-31}, { 8,-22}, {12, -4}, {12, -4}, { 8,-22}, { 5,-31}, {-3,-55}
                ,{-3,-39}, { 6,-18}, {13, -9}, { 7,  3}, { 7,  3}, {13, -9}, { 6,-18}, {-3,-39}
                ,{ 4,-23}, { 5, -3}, { 9, 13}, { 8, 24}, { 8, 24}, { 9, 13}, { 5, -3}, { 4,-23}
                ,{ 0,-29}, { 14, -6}, {12,  9}, { 5, 21}, { 5, 21}, {12,  9}, { 14, -6}, { 0,-29}
                ,{-4,-38}, { 10,-18}, { 6,-12}, { 8,  1}, { 8,  1}, { 6,-12}, { 10,-18}, {-4,-38}
                ,{-5,-50}, { 6, -27}, {10,-24}, { 8, -8}, { 8, -8}, {10,-24}, { 6, -27}, {-5,-50}
                ,{-2,-75}, {-2, -52}, { 1,-43}, {-2,-36}, {-2,-36}, { 1,-43}, {-2, -52},{-2,-75}
        }, {//King
                {271,  1}, {327, 45}, {271, 85}, {198, 76}, {198, 76}, {271, 85}, {327, 45}, {271,  1}
                ,{278, 53}, {303,100}, {234,133}, {179,135}, {179,135}, {234,133}, {303,100}, {278, 53}
                ,{195, 88}, {258,130}, {169,169}, {120,175}, {120,175}, {169,169}, {258,130}, {195, 88}
                ,{164,103}, {190,156}, {138,172}, { 98,172}, { 98,172}, {138,172}, {190,156}, {164,103}
                ,{154, 96}, {179,166}, {105,199}, { 70,199}, { 70,199}, {105,199}, {179,166}, {154, 96}
                ,{123, 92}, {145,172}, { 81,184}, { 31,191}, { 31,191}, { 81,184}, {145,172}, {123, 92}
                ,{ 88, 47}, {120,121}, { 65,116}, { 33,131}, { 33,131}, { 65,116}, {120,121}, { 88, 47}
                ,{ 59, 11}, { 89, 59}, { 45, 73}, { -1, 78}, { -1, 78}, { 45, 73}, { 89, 59}, { 59, 11}
        }
};

const int mobilityBonus[6][28][2] = {
        {}, {},
        { {-75,-76}, {-56,-54}, {-9,-26}, {-2,-10}, {6,  5}, {15, 11}, // Knights
                {22, 26}, {30, 28}, {36, 29} },

        { {-48,-58}, {-21,-19}, {16, -2}, {26, 12}, {37, 22}, {51, 42}, // Bishops
                {54, 54}, {63, 58}, {65, 63}, {71, 70}, {79, 74}, {81, 86},
                {92, 90}, {97, 94} },

        { {-56,-78}, {-25,-18}, {-11, 26}, {-5, 55}, {-4, 70}, {-1, 81}, // Rooks
                {8,109}, {14,120}, {21,128}, {23,143}, {31,154}, {32,160},
                {43,165}, {49,168}, {59,169} },

        { {-40,-35}, {-25,-12}, {2,  7}, {4, 19}, {14, 37}, {24, 55}, // Queens
                {25, 62}, {40, 76}, {43, 79}, {47, 87}, {54, 94}, {56,102},
                {60,111}, {70,116}, {72,118}, {73,122}, {75,128}, {77,130},
                {85,133}, {94,136}, {99,140}, {108,157}, {112,158}, {113,161},
                {118,174}, {119,177}, {123,191}, {128,199} }
};


const int pceMat[13] = {0, 150, 781, 825, 1276, 2538, 60000, 150, 781, 825, 1276, 2538, 60000};
const int totMat = 19004;  // Total material from beginning (excluding kings)
const int bishopPairValue = 50;
const int passedPawnBonus[8] = {0, 50, 50, 50, 78, 96, 122, 176}; //Indexed by file number.
const int batteryBonus = 50;  // A small bonus if bishop+queen or rook+queen forms a battery.
const int pawnIsolated = -30;
int pawnShieldBonus[7] = {-10, 0, 40, 100, 110, 110, 110};
int openFileToKingPenalty = -50;
int semiOpenFilePenalty[4] = {0, -30, -60, -90};
int openFilePenalty[4] = {0, -50, -100, -150};

const int rookOpenFile = 10;
const int rookSemiOpenFile = 5;
const int queenOpenFile = 5;
const int queenSemiOpenFile = 3;

int FilesBrd[120];
int RanksBrd[120];
u64 FileBBMask[8] = {0x0101010101010101, 0x0202020202020202, 0x0404040404040404, 0x0808080808080808,
                     0x1010101010101010, 0x2020202020202020, 0x4040404040404040, 0x8080808080808080};
u64 RankBBMask[8];
u64 BlackPassedMask[64];
u64 WhitePassedMark[64];
u64 IsolatedMask[64];
u64 whitePawnShieldBB[47];
u64 blackPawnShieldBB[47];

void initFilesRanksBrd() {

    int index = 0;
    int file = FA;
    int rank = R1;
    int sq = 21;
    int sq64 = 0;

    for(index = 0; index < 120; ++index) {
        FilesBrd[index] = o;
        RanksBrd[index] = o;
    }

    for(rank = R1; rank <= R8; ++rank) {
        for(file = FA; file <= FH; ++file) {
            sq = FR2SQ(file,rank);
            FilesBrd[sq] = file;
            RanksBrd[sq] = rank;
        }
    }
}
void initEvalMasks() {

    int sq, tsq, r, f;

    for(sq = 0; sq < 8; ++sq) {
        //FileBBMask[sq] = 0ULL;
        RankBBMask[sq] = 0ULL;
    }

    for(r = R8; r >= R1; r--) {
        for (f = FA; f <= FH; f++) {
            sq = r * 8 + f;
            //FileBBMask[f] |= (1ULL << sq);
            RankBBMask[r] |= (1ULL << sq);
        }
    }

    for(sq = 0; sq < 64; ++sq) {
        IsolatedMask[sq] = 0ULL;
        WhitePassedMark[sq] = 0ULL;
        BlackPassedMask[sq] = 0ULL;
    }

    for(sq = 0; sq < 64; ++sq) {
        tsq = sq + 8;

        while(tsq < 64) {
            WhitePassedMark[sq] |= (1ULL << tsq);
            tsq += 8;
        }

        tsq = sq - 8;
        while(tsq >= 0) {
            BlackPassedMask[sq] |= (1ULL << tsq);
            tsq -= 8;
        }

        if(FilesBrd[sq64(sq)] > FA) {
            IsolatedMask[sq] |= FileBBMask[FilesBrd[sq64(sq)] - 1];

            tsq = sq + 7;
            while(tsq < 64) {
                WhitePassedMark[sq] |= (1ULL << tsq);
                tsq += 8;
            }

            tsq = sq - 9;
            while(tsq >= 0) {
                BlackPassedMask[sq] |= (1ULL << tsq);
                tsq -= 8;
            }
        }

        if(FilesBrd[sq64(sq)] < FH) {
            IsolatedMask[sq] |= FileBBMask[FilesBrd[sq64(sq)] + 1];

            tsq = sq + 9;
            while(tsq < 64) {
                WhitePassedMark[sq] |= (1ULL << tsq);
                tsq += 8;
            }

            tsq = sq - 7;
            while(tsq >= 0) {
                BlackPassedMask[sq] |= (1ULL << tsq);
                tsq -= 8;
            }
        }
    }
}

static int evalPassedPawns(Board *brd) {
    int evaluation = 0;
    //White first
    for (int i = 0; i<brd->pceNum[P]; i++) {
        if ((WhitePassedMark[sq120(brd->pieceList[P][i])] & brd->pawns[black]) == 0) {
            evaluation += passedPawnBonus[RanksBrd[brd->pieceList[P][i]]];
        }
    }
    for (int i = 0; i<brd->pceNum[p]; i++) {
        if ((BlackPassedMask[sq120(brd->pieceList[p][i])] & brd->pawns[white]) == 0) {
            evaluation -= passedPawnBonus[RanksBrd[brd->pieceList[p][i]]];
        }
    }
    return evaluation;
}

static int evalIsolatedPawns(Board *brd) {
    int evaluation = 0;
    //White first
    for (int i = 0; i<brd->pceNum[P]; i++) {
        if ((IsolatedMask[sq120(brd->pieceList[P][i])] & brd->pawns[white]) == 0) {
            evaluation += pawnIsolated;
        }
    }
    for (int i = 0; i<brd->pceNum[p]; i++) {
        if ((IsolatedMask[sq120(brd->pieceList[p][i])] & brd->pawns[black]) == 0) {
            evaluation -= pawnIsolated;
        }
    }
    return evaluation;
}

static int evalBishopPair(Board *brd) {
    int evaluation = 0;
    //enum pieceValues : short {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};
    //int pceNum[13]; Stores the number of pieces on the board. Empty 0 -> Black King 12.
    if (brd->pceNum[3] > 1) evaluation += bishopPairValue;
    if (brd->pceNum[9] > 1) evaluation -= bishopPairValue;
    return evaluation;
}

void initPceTableScore(Board *brd){
    brd->whiteMidPceTableScore = 0;
    brd->whiteEndPceTableScore = 0;
    brd->blackMidPceTableScore = 0;
    brd->blackEndPceTableScore = 0;

    for (int i = 1; i<7; i++) {
        for (int q = 0; q<brd->pceNum[i]; q++) {
            brd->whiteMidPceTableScore += allTables[i][sq120(brd->pieceList[i][q])][0];
            brd->whiteEndPceTableScore += allTables[i][sq120(brd->pieceList[i][q])][1];
        }
    }
    for (int i = 7; i<13; i++) {
        for (int q = 0; q<brd->pceNum[i]; q++) {
            brd->blackMidPceTableScore += allTables[i][Mirror64[sq120(brd->pieceList[i][q])]][0];
            brd->blackEndPceTableScore += allTables[i][Mirror64[sq120(brd->pieceList[i][q])]][1];
        }
    }
}

static int evalPieceTables(Board *brd){
    int evaluation = 0;

    evaluation += brd->whiteMidPceTableScore * brd->midMultiplier;
    evaluation += brd->whiteEndPceTableScore * brd->endMultiplier;

    evaluation -= brd->blackMidPceTableScore * brd->midMultiplier;
    evaluation -= brd->blackEndPceTableScore * brd->endMultiplier;

    return evaluation;
}


static int evalMobilityBonus(Board *brd){
    int evaluation = 0;
    evaluation += brd->whiteMidMobility * brd->midMultiplier;
    evaluation += brd->whiteEndMobility * brd->endMultiplier;
    evaluation -= brd->blackMidMobility * brd->midMultiplier;
    evaluation -= brd->blackEndMobility * brd->endMultiplier;

    if (brd->whiteBattery){
        evaluation += batteryBonus;
    }
    if (brd->blackBattery){
        evaluation -= batteryBonus;
    }

    return evaluation;
}

void initPawnShieldBB(){
    for (int sq = 0; sq < 47; sq++){
        u64 bb = 0;
        int rank = sq / 8;

        if ((sq+7) / 8 == rank+1){
            setBit(bb, sq+7);
            setBit(bb, sq+15);
        }
        if ((sq+9) / 8 == rank+1){
            setBit(bb, sq+9);
            setBit(bb, sq+17);
        }

        setBit(bb, sq+8);
        setBit(bb, sq+16);
        whitePawnShieldBB[sq] = bb;

        bb = 0;
        rank = (63-sq) / 8;
        if ((56 - sq) / 8 == rank-1){
            setBit(bb, 56 - sq);
            setBit(bb, 48 - sq);
        }
        if ((54 - sq) / 8 == rank-1){
            setBit(bb, 54 - sq);
            setBit(bb, 46 - sq);
        }

        setBit(bb, 55 - sq);
        setBit(bb, 47 - sq);
        blackPawnShieldBB[sq] = bb;
    }
}

static int pawnShield(Board *brd){
    int evaluation = 0;

    int sq = sq120(brd->kingSq[white]);

    if (sq < 8){
        evaluation += pawnShieldBonus[countBit(whitePawnShieldBB[sq] & brd->pawns[white])];
    }else if (sq < 16){
        evaluation += pawnShieldBonus[countBit(whitePawnShieldBB[sq] & brd->pawns[white])] / 3;
    }

    sq = 63 - sq120(brd->kingSq[black]);
    if (sq < 8){
        evaluation -= pawnShieldBonus[countBit(blackPawnShieldBB[sq] & brd->pawns[black])];
    }else if (sq < 16){
        evaluation -= pawnShieldBonus[countBit(blackPawnShieldBB[sq] & brd->pawns[black])] / 3;
    }

    return evaluation * brd->midMultiplier;
}

static int openFilesNearKing(Board *brd){
    int evaluation = 0;
    int smallPenaltyCt = 0;
    int bigPenaltyCt = 0;
    int whiteKingFile = brd->kingSq[white] % 8;

    if(!(FileBBMask[whiteKingFile] & brd->pawns[white])){
        if (!(FileBBMask[whiteKingFile] & brd->pawns[black])){
            bigPenaltyCt += 1;
        }else{
            smallPenaltyCt += 1;
        }
        evaluation += openFileToKingPenalty;
    }

    if (whiteKingFile + 1 < 8) {
        if (!(FileBBMask[whiteKingFile+1] & brd->pawns[white])) {
            if (!(FileBBMask[whiteKingFile+1] & brd->pawns[black])) {
                bigPenaltyCt += 1;
            } else {
                smallPenaltyCt += 1;
            }
        }
    }

    if (whiteKingFile - 1 >= 0) {
        if (!(FileBBMask[whiteKingFile-1] & brd->pawns[white])) {
            if (!(FileBBMask[whiteKingFile-1] & brd->pawns[black])) {
                bigPenaltyCt += 1;
            } else {
                smallPenaltyCt += 1;
            }
        }
    }

    evaluation += semiOpenFilePenalty[smallPenaltyCt];
    evaluation += openFilePenalty[bigPenaltyCt];

    smallPenaltyCt = 0;
    bigPenaltyCt = 0;
    int blackKingFile = brd->kingSq[black] % 8;

    if(!(FileBBMask[blackKingFile] & brd->pawns[black])){
        if (!(FileBBMask[blackKingFile] & brd->pawns[white])){
            bigPenaltyCt += 1;
        }else{
            smallPenaltyCt += 1;
        }
        evaluation += openFileToKingPenalty;
    }

    if (whiteKingFile + 1 < 8) {
        if (!(FileBBMask[blackKingFile+1] & brd->pawns[black])) {
            if (!(FileBBMask[blackKingFile+1] & brd->pawns[white])) {
                bigPenaltyCt += 1;
            } else {
                smallPenaltyCt += 1;
            }
        }
    }

    if (whiteKingFile - 1 >= 0) {
        if (!(FileBBMask[blackKingFile-1] & brd->pawns[black])) {
            if (!(FileBBMask[blackKingFile-1] & brd->pawns[white])) {
                bigPenaltyCt += 1;
            } else {
                smallPenaltyCt += 1;
            }
        }
    }

    evaluation -= semiOpenFilePenalty[smallPenaltyCt];
    evaluation -= openFilePenalty[bigPenaltyCt];

    return evaluation * brd->midMultiplier;
}

int mainEval(Board *brd){

    brd->midMultiplier = (double)(brd->material[white] + brd->material[black] - 120000) / totMat;
    brd->endMultiplier = 1.0 - brd->midMultiplier;

    int score = brd->material[white] - brd->material[black];

    score += evalPieceTables(brd);

    score += evalBishopPair(brd);

    score += evalPassedPawns(brd);
    score += evalIsolatedPawns(brd);

    //score += evalMobilityBonus(brd);

    /// King safety
    score += pawnShield(brd);
    score += openFilesNearKing(brd);

    if (brd->side == white){
        return score;
    }
    return -score;
}

