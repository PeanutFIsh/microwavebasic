#include <iostream>
#include <string>
#include <ctype.h>
#include <boost/algorithm/string.hpp>
#include "engine.h"
#include "utils.h"
#include "libs/stringop.h"
using namespace std;

/*
/=============================\
|        MicrowaveBASIC       |
\=============================/

C++ version. Cus I want this shit to be cross-platform
and native.

The purpose is to make a retro computer simulation of
those 80s micro-computers. It will work with BASIC and
will have some basic commands like PRINT, DIM, INPUT, etc.

This is a very simple program not designed to make you a
developer.
 */

 string* PrgmMem = new string[999999];

 int main() {
    BootScreen();
    cout << endl;
    string cmd;
    int o;
    int* dummylol = new int[26];
    while (true) {
        getline(cin, cmd);
        
        string cmdu = cmd;
        boost::to_upper(cmdu);

        if (cmdu == "EXIT")
            break;
        else if (is_number(trimString(cmd, 0, searchChar(' ', cmd) - 1))) {
            string a = trimString(cmd, 0, searchChar(' ', cmd));
            int linnum = evalString(a, dummylol, false);  // Lmao I can't code :D
            PrgmMem[linnum] = cmd.erase(0, a.size());
        } else if (cmdu == "LIST") {
            for (int i = 0; i < 999999; ++i) {
                if (PrgmMem[i] != "")
                    cout << to_string(i) << " " << PrgmMem[i] << endl;
            }
        } else if (cmdu == "NEW") {
            for (int i = 0; i > 999999; ++i) {
                PrgmMem[i] = "";
            }
        } else if (cmdu == "RUN") {
            ExecuteCode(PrgmMem);
        }
        else
            o = ExecuteLine(cmd, -1);
        //Making it an endless loop
    }

    return 0;
 }