#include <iostream>
#include <string>
#include <ctype.h>

/* 
Source files map :
    - engine.cpp
    The core of this program, will interpret the program.
    - main.cpp
    The interpreter, contains the program where you can type commands and your program.
    - utils.cpp
    Contains some general purpose useful commands.
    - libs/fileman.cpp
    Contains function to manage BASIC program files (save/load/delete).
    - libs/stringadd.cpp
    Contains simple string manipulation.
    - libs/stringcond.cpp
    Contains the condition system.
    -libs/stringop.cpp
    Contains simple math eval functions.
*/
#include "engine.h"
#include "utils.h"

#include "libs/stringop.h"
#include "libs/fileman.h"

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
    string co;
    int o;
    while (true) {
        getline(cin, cmd);
        string cmdu = to_upper(cmd);
        if (cmdu == "EXIT")
            break;
        else if (is_number(trimString(cmd, 0, searchChar(' ', cmd) - 1))) {
            string a = trimString(cmd, 0, searchChar(' ', cmd));
            int linnum = evalString(a, new int[26], false);  // Lmao I can't code :D
            PrgmMem[linnum] = cmd.erase(0, a.size());
        } else if (cmdu == "LIST") {
            for (int i = 0; i < 999999; ++i) {
                if (PrgmMem[i] != "")
                    cout << to_string(i) << " " << PrgmMem[i] << endl;
            }
        } else if (cmdu == "NEW") {
            for (int i = 0; i < 999999; ++i) {
                PrgmMem[i] = "";
            }
        }
        else if (starts_with(cmdu, "SAVE")) {
            co = cmdu.erase(0, 4);

            if (co == "")
                cout << "!!SYNTAX ERROR" << endl;
            else
                saveFile(co + ".BAS", PrgmMem, true);
        } else if (starts_with(cmdu, "LOAD")) {
            co = cmdu.erase(0, 4);

            if (co == "")
                cout << "!!SYNTAX ERROR" << endl;
            else
                loadFile(co + ".BAS", PrgmMem);
        }
        else if (cmdu == "RUN") {
            ExecuteCode(PrgmMem);
        }
        else
            o = ExecuteLine(cmd, -1);
        //Making it an endless loop
    }

    return 0;
 }