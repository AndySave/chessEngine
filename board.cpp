//TODO 120sq brett
//TODO 120sq til 64 sq brett
//TODO printBoard, 1 faktiske verdier, en med brikker (boolean for aa velge.)
//TODO enum brikke til navn
#include <bits/stdc++.h>
#include "board.h"

using namespace std;

#define sq64(sq) sq64sq120[sq]  // bruker sq64sq120 arrayen og produserer 120 sq
short sq64sq120[64] = {21, 22, 23, 24, 25, 26, 27, 28,
                31, 32, 33, 34, 35, 36, 37, 38,
                41, 42, 43, 44, 45, 46, 47, 48,
                51, 52, 53, 54, 55, 56, 57, 58,
                61, 62, 63, 64, 65, 66, 67, 68,
                71, 72, 73, 74, 75, 76, 77, 78,
                81, 82, 83, 84, 85, 86, 87, 88,
                91, 92, 93, 94, 95, 96, 97, 98};


// Toemmer brettet
// Viktig: Maa kalle denne funksjonen naar man initialiserer brettet for aa
// definere offboard rutene
void resetBoard(Board *brd){
    for (int & piece : brd->pieces){
        piece = o;
    }
    for (int i = 0; i < 64; i++){
        brd->pieces[sq64(i)] = e;
    }
}

// Printer 120 brettet's eksakte verdier
void printBoard120(Board *brd){
    for (int i = 0; i < 120; i++){
        cout << brd->pieces[i] << " ";
        if ((i+1) % 10 == 0){
            cout << endl;
        }
    }
}

