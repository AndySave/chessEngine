
#include "defenitions.h"

int getTime(){
    struct timeval t;
    mingw_gettimeofday(&t, NULL);
    return t.tv_sec*1000 + t.tv_usec/1000;
}


void playerMenu(Board *brd, Searchinfo *info){
    int mv;
    Movelist lst[1];

    printBoard(brd);
    while (true) {
        string ins;
        cout << "\nEnter move: ";
        cin >> ins;

        if (ins == "q") {
            break;
        } else if (ins == "t") {
            undoMove(brd);
            printBoard(brd);
        } else if (ins == "s") {
            searchPosition(brd, info);
        }else if (ins == "ms"){
            int d;
            cout << "depth: ";
            cin >> d;
            info->depth = d;
            makeMove(brd, searchPosition(brd, info));
            printBoard(brd);
        }else if (ins == "p"){
            perftTest(info->depth, brd);
        }else if (ins == "c"){
            bool legal;
            while (true){
                legal = false;
                makeMove(brd, searchPosition(brd, info));
                printBoard(brd);

                generateLegalMoves(brd, lst);
                for (int i = 0; i < lst->count; i++){
                    if (!makeMove(brd, lst->moves[i].move)){
                        continue;
                    }
                    undoMove(brd);
                    legal = true;
                }
                if (!legal){
                    if (sqAttacked(brd->kingSq[brd->side], brd->side^1, brd)){
                        cout << "CHECKMATE" << "\n";
                    }else{
                        cout << "STALEMATE" << "\n";
                    }
                    break;
                }
            }
        }else {
            mv = parseMove(brd, ins);
            makeMove(brd, mv);
            printBoard(brd);
        }
    }
}