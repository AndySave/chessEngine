#include "defenitions.h"

void sq64ToAlgebraicTEST() {
    for (int i = 0; i<64; i++) {
        cout << "input: "<< i << " || output: " << sq64ToAlgebraic(i) << endl;
    }
}

void printMoveList(const Movelist *lst){
    int move;
    int score;

    for (int i = 0; i < lst->count; i++){
        move = lst->moves[i].move;
        score = lst->moves[i].score;

        if (captureFlag & move){
            cout << "C";
        }
        cout << "Move #" << i+1 << ": ";
        printMove(move);
        cout << " Score: " << score << endl;
    }
    cout << "Total moves: " << lst->count;
}

