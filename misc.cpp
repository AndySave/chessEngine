
#include "defenitions.h"
#include <fstream>

#ifdef WIN32
#include "windows.h"
#else
#include "sys/time.h"
#include "sys/select.h"
#include "unistd.h"
#include "string.h"
#endif

int getTime(){ //i Millisekunder?
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
// http://home.arcor.de/dreamlike/chess/
int InputWaiting()
{
#ifndef WIN32
    fd_set readfds;
  struct timeval tv;
  FD_ZERO (&readfds);
  FD_SET (fileno(stdin), &readfds);
  tv.tv_sec=0; tv.tv_usec=0;
  select(16, &readfds, 0, 0, &tv);

  return (FD_ISSET(fileno(stdin), &readfds));
#else
    static int init = 0, pipe;
    static HANDLE inh;
    DWORD dw;

    if (!init) {
        init = 1;
        inh = GetStdHandle(STD_INPUT_HANDLE);
        pipe = !GetConsoleMode(inh, &dw);
        if (!pipe) {
            SetConsoleMode(inh, dw & ~(ENABLE_MOUSE_INPUT|ENABLE_WINDOW_INPUT));
            FlushConsoleInputBuffer(inh);
        }
    }
    if (pipe) {
        if (!PeekNamedPipe(inh, NULL, 0, NULL, &dw, NULL)) return 1;
        return dw;
    } else {
        GetNumberOfConsoleInputEvents(inh, &dw);
        return dw <= 1 ? 0 : dw;
    }
#endif
}

void ReadInput(Searchinfo *info) {
    int             bytes;
    char            input[256] = "", *endc;

    if (InputWaiting()) {
        info->stopped = true;
        do {
            bytes = read(fileno(stdin),input,256);
        } while (bytes<0);
        endc = strchr(input,'\n');
        if (endc) *endc=0;

        if (strlen(input) > 0) {
            if (!strncmp(input, "quit", 4))    {
                info->quit = true;
            }
        }
        return;
    }
}


