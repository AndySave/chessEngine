//TODO 120sq brett
//TODO 120sq til 64 sq brett
//TODO printBoard, 1 faktiske verdier, en med brikker (boolean for aa velge.)
//TODO enum brikke til navn
#include <bits/stdc++.h>
#include "board.h"

using namespace std;

void printBoard120(Board *brd){
    for (int i = 0; i < 120; i++){
        cout << brd->pieces[i];
        if ((i+1) % 10 == 0){
            cout << endl;
        }
    }
}

