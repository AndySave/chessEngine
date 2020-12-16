#include "defenitions.h"

string engineName = "B_0-t";
string authors = "AndySave & Miizu";

bool isPositionInput(string s) {
    string positionCheck = s.substr(0, 8);
    if (positionCheck == "position") return true;
    return false;
}

void uciCommunication() {
    Board board{};
    Searchinfo info{};
    info.depth = 7;

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

        } else if (input.length() > 10 && isPositionInput(input)) {
            if (input.find("fen") != input.npos) {
                //what to do
            } else if (input.find("startpos") != input.npos) {
                FENBoardUpdater(&board, standardFen);
            }

            if (input.find("moves") != input.npos) {
                cout << "Debugger: in moves found!" << endl;
                int startPos = input.find("moves") + 6;

                while (startPos < input.length()-1) {
                    string move = input.substr(startPos, 5);
                    cout << move << endl;
                    int newMove = parseMove(&board, move);
                    makeMove(&board, newMove);

                    startPos += 5;
                }
            }

        } else if (input == "go") {
            //start calculating on the current position set up with the "position" command.

            //her maa vi threade i tilfelle vi mottar stop command

        } else if (input == "help") {
            cout << "Command: uci" << endl;
            cout << "Command: isready" << endl;
            cout << "Command: ucinewgame" << endl;
            cout << "Command: position" << endl;
            cout << "Command: go" << endl;
            cout << "Command: print" << endl;
        } else if (input == "print") {
            printBoard(&board);
        }
        else {
            cout << "Unknown command, type help to view all commands." << endl;
        }
        if (engineName == "22") break;


    }
}