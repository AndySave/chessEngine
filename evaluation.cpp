
#include "defenitions.h"

void mainEval(Board *brd){
    int score = brd->material[white] - brd->material[black];


    if (brd->side == black){
        return -score;
    }
    return score;
}
