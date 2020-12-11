
#include "defenitions.h"

int mainEval(Board *brd){
    int score = brd->material[white] - brd->material[black];


    if (brd->side == white){
        return score;
    }
    return -score;
}


