
#include "defenitions.h"

void printMove(int move){
    cout << fromsq(move) << endl;
    cout << tosq(move) << endl;
    cout << promoted(move) << endl;
}
