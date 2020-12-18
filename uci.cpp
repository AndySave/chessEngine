#include "defenitions.h"

string engineName = "B_0-t";
string authors = "AndySave & Miizu";

bool isPositionInput(string s) {
    string positionCheck = s.substr(0, 8);
    if (positionCheck == "position") return true;
    return false;
}

int makesLifeEasier(string lookingFor, string line, int lookingForLength) {
    lookingForLength++;
    int startIndex = line.find(lookingFor) + lookingForLength;
    string val = "";
    for (int i = startIndex; i<line.length(); i++) {
        if (line[i] == ' ') break;
        val += line[i];
    }
    int res = stoi(val);
    return res;

}
// go depth 6 wtime 180000 btime 100000 binc 1000 winc 1000 movetime 1000 movestogo 40
void uciGO(string line, Searchinfo *info, Board *board) {

    int depth = -1, movestogo = 30,movetime = -1;
    int time = -1, inc = 0;
    info->timeset = false;

    if (line.find("infinite") != line.npos) {
        ;
    }

    if (line.find("binc")  != line.npos && board->side == 1) { //Black to move (1)
        inc = makesLifeEasier("binc", line, 4);
    }

    if (line.find("winc") != line.npos && board->side == 0) { //White to move (0)
        inc = makesLifeEasier("winc", line, 4);
    }

    if (line.find("wtime") != line.npos && board->side == 0) { //White to move (0)
        time = makesLifeEasier("wtime", line, 5);
    }

    if (line.find("btime") != line.npos && board->side == 1) { //Black to move (1)
        time = makesLifeEasier("btime", line, 5);
    }

    if (line.find("movestogo") != line.npos) {
        movestogo = makesLifeEasier("movestogo", line, 9);
    }
    if (line.find("movetime") != line.npos) {
        movetime = makesLifeEasier("movetime", line, 8);
    }
    if (line.find("depth") != line.npos) {
        depth = makesLifeEasier("depth", line, 5);
    }

    if(movetime != -1) {
        time = movetime;
        movestogo = 1;
    }

    info->starttime = getTime(); //Skal vaere i millisekunder!
    info->depth = depth;

    if(time != -1) {
        info->timeset = true;
        time /= movestogo;
        time -= 50;
        info->stoptime = info->starttime + time + inc;
    }

    if(depth == -1) {
        info->depth = 12; //satt til maxdepth av bluefever, valgte her 7.
    }

    printf("time:%d start:%d stop:%d depth:%d timeset:%d\n",
           time,info->starttime,info->stoptime,info->depth,info->timeset);
    searchPosition(board, info);
}

void uciCommunication() {
    Board board{};
    Searchinfo info{};
    info.depth = 12;

    initBitMasks();
    initHashkeys();
    initFilesRanksBrd();
    initEvalMasks();
    initMvvLva();
    FENBoardUpdater(&board, standardFen);

    while (true) {
        string input; getline(cin, input);

        if (input == "uci") {
            /*tell engine to use the uci (universal chess interface),
             *this will be send once as a first command after program boot
             * to tell the engine to switch to uci mode.
             */
            cout << "id name " + engineName << '\n';
            cout << "id author " + authors << '\n';
            cout << "uciok" << endl;
        } else if (input == "isready") {
            /*this is used to synchronize the engine with the GUI. When the GUI has sent a command or
             *multiple commands that can take some time to complete,
             *this command can be used to wait for the engine to be ready again or
             *to ping the engine to find out if it is still alive.
             */
            cout << "readyok" << endl;

        } else if (input == "ucinewgame") {
            /*this is sent to the engine when the next search
             *(started with "position" and "go") will be from a different game.
             */
            initBitMasks();
            initHashkeys();
            initFilesRanksBrd();
            initEvalMasks();
            initMvvLva();

        } else if (input == "quit") {
            break;
        } else if (input.length() > 10 && isPositionInput(input)) {
            if (input.find("fen") != input.npos) {
                //what to do
                int startOfFen = input.find("fen") + 4;
                int endOfFen = input.length()-1;
                if (input.find("moves") != input.npos) {
                    endOfFen = input.find("moves") - 2;
                }
                int fenLength = endOfFen - startOfFen + 1;
                cout << input.substr(startOfFen, fenLength) << endl;
                FENBoardUpdater(&board, input.substr(startOfFen, fenLength));

            } else if (input.find("startpos") != input.npos) {
                FENBoardUpdater(&board, standardFen);
            }

            if (input.find("moves") != input.npos) {
                int startPos = input.find("moves") + 6;

                while (startPos < input.length()-1) {
                    string move = input.substr(startPos, 5);
                    if (move[move.size()-1] == ' ') {
                        move.pop_back();
                    } else {
                        startPos++;
                    }
                    int newMove = parseMove(&board, move);
                    makeMove(&board, newMove);

                    startPos += 5;
                }
                cout << "POSITION" << endl;
            }

        } else if (input.size() > 1 && input[0] == 'g' && input[1] == 'o') {
            //start calculating on the current position set up with the "position" command.
            uciGO(input, &info, &board);
            printf("bestmove ");
            printMove(board.pvArray[0]);
            cout << endl;
            cout << "GO" << endl;


        } else if (input == "eval") {
            cout << "test" << endl;

        }else if (input == "help") {
            cout << "Command: uci" << endl;
            cout << "Command: isready" << endl;
            cout << "Command: ucinewgame" << endl;
            cout << "Command: position" << endl;
            cout << "Command: go" << endl;
            cout << "Command: print" << endl;
        } else if (input == "print") {
            printBoard(&board);
            printBoard120(&board);
        }
        else {
            cout << "Unknown command, type help to view all commands." << endl;
        }


    }
}