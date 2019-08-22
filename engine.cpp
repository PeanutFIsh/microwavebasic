#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>

#include "engine.h"
#include "utils.h"
#include "libs/stringadd.h"
#include "libs/stringop.h"
#include "libs/stringcond.h"
using namespace std;

// This cpp file contains the whole engine to run code.
// Version of the software
string VERSION = "0.1.0-alpha";
string* stringvars = new string[128];
int* intvars = new int[128];

//Boot screen. Displays useless info
void BootScreen() {
    cout<<"MicrowaveBASIC " << VERSION << " by h34ting4ppliance \nCopyright (C) Microwave Micro-computers Co."<<endl;
    //Display shit lol
}

//Will execute an entire code.
void ExecuteCode(std::string* code) {
    int o = 0;
    for (int i = 0; i < 99999; ++i) {
        if (code[i] != "")
            o = ExecuteLine(code[i], i);
        if (o == -1) {
            cout << "!STOP AT " << to_string(i) << endl;
            break;
        }

        if (o >= 1)
            i = o - 1;
        
        o = 0;
    }
}

//Will execute only a single line.
int ExecuteLine(std::string line, int pptr) {
    if (boost::starts_with(line, "P ")) {               // " PRINT command
        string o = line.erase(0, 2);
        if (o == "") {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        }
        else
            cout << evalStringAddition(o, stringvars) << endl;
        
        return 0;
    } else if (boost::starts_with(line, "//"))          // Comment
        return 0;
    else if (boost::starts_with(line, "p ")) {           // ' PRINT command
        string o = line.erase(0, 2);
        if (o == "") {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        }
        else
            cout << evalStringAddition(o, stringvars);
        return 0;
    } else if (boost::starts_with(line, "?* ")) {
        string o = line.erase(0, 3);
        string inp = "";
        if (o == "" || !isalpha(o.at(0))) {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        }
        else {
            getline(cin, inp);
            if (!is_number(inp)) {
                cout << "!INPUT ERROR" << endl;
                return -1;
            }
            intvars[toupper(o.at(0)) - 'A'] = evalString(inp, intvars, false);
        }
        return 0;
    } else if (boost::starts_with(line, "?$ ")) {
        string o = line.erase(0, 3);
        string inp = "";

        if (o == "" || !isalpha(o.at(0))) {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        } else {
            getline(cin, inp);
            stringvars[toupper(o.at(0)) - 'A'] = inp;
        }

        return 0;
    } else if (boost::starts_with(line, "* ")) {
        string o = line.erase(0, 2);

        if (o == "" || !isalpha(o.at(0))) {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        } else {
            cout << to_string(intvars[toupper(o.at(0)) - 'A']);
            return 0;
        }
    } else if (boost::starts_with(line, "=* ")) {
        string o = line.erase(0, 3);
        string oa = line.erase(0, 1);
        if (o == "" || !isalpha(o.at(0)) || oa == "") {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        } else {
            intvars[toupper(o.at(0)) - 'A'] = evalString(oa, intvars, false);
            return 0;
        }
    } else if (boost::starts_with(line, "G ")) {
        if (pptr == -1) {
            cout << "!PROGRAM ERROR" << endl;
            return -1;
        }
        string o = line.erase(0, 2);
        if (!is_number(o)) {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        }
        pptr = evalString(o, intvars, false) - 1;
        if (pptr <= 0) {
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        }
        return pptr;
    } else if (boost::starts_with(line, "I* ")) {
        string o = line.erase(0, 3);
        int sepPos = searchChar(':', o);
        if (sepPos == -1) {                 // If sepPos = -1, that means not any separator has been detected
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        }

        string argA = trimString(o, 0, sepPos - 1);
        string argB = trimString(o, sepPos + 1, line.size() - 1);

        bool condi = evalIntCondition(argA, intvars);
        if (condi) {
            int a = ExecuteLine(argB, pptr);
            if (a == -1)
                return -1;
            else
                return 0;
        } else {
            return -1;
        }
    } else if (boost::starts_with(line, "I$ ")) {
        string o = line.erase(0, 3);
        int sepPos = searchChar(':', o);
        if (sepPos == -1) {                 // If sepPos = -1, that means not any separator has been detected
            cout << "!SYNTAX ERROR" << endl;
            return -1;
        }

        string argA = trimString(o, 0, sepPos - 1);
        string argB = trimString(o, sepPos + 1, line.size() - 1);

        bool condi = evalStrCondition(argA, stringvars);
        if (condi) {
            int a = ExecuteLine(argB, pptr);
            if (a == -1)
                return -1;
            else
                return a;
        } else {
            return 0;
        }
    }

    else if (line != "") {
        cout << "!SYNTAX ERROR" << endl;
        return -1;
    }

    return 0;
}