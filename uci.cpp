#include "definitions.h"
#include <stdio.h>
#include <string.h>
#define INPUTBUFFER 400 * 6
string NAME = "B_0-t";

Board* board;
Searchinfo *info;

void ParseGo(char* line, searchInfo *info, Board *brd) {
}
void ParsePosition(char* lineIn, Board *brd) {
}

void Uci_Loop() {

    setbuf(stdin, nullptr);
    setbuf(stdout, nullptr);

    char line[INPUTBUFFER]; //Input line
    printf("id name %s\n",NAME);
    printf("id author B_0-t\n");
    printf("uciok\n");


    while (true) {
        memset(&line[0], 0, sizeof(line));
        fflush(stdout);
        if (!fgets(line, INPUTBUFFER, stdin))
            continue;

        if (line[0] == '\n')
            continue;

        if (!strncmp(line, "isready", 7)) {
            printf("readyok\n");
            continue;
        } else if (!strncmp(line, "position", 8)) {
            ParsePosition(line, board);
        } else if (!strncmp(line, "ucinewgame", 10)) {
            ParsePosition("position startpos\n", pos);
        } else if (!strncmp(line, "go", 2)) {
            ParseGo(line, info, board);
        } else if (!strncmp(line, "quit", 4)) {
            info->quit = true;
            break;
        } else if (!strncmp(line, "uci", 3)) {
            printf("id name %s\n",NAME);
            printf("id author B_0-t\n");
            printf("uciok\n");
        }
        if(info->quit) break;
    }
}



