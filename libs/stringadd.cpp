#include <iostream>
#include <string>
#include <ctype.h>
#include "stringadd.h"
using namespace std;
// This code allows to perform string addition

std::string evalStringAddition(std::string o, const string* vars) {
    string* strings = new string[50];
    string outputStr = "";

    char c;                 // Current character
    int previousType = 0;   // Previous type  
    int ptr = 0;            // Array pointer
    int endline;            // End of array. Variable for optimization purposes.
    bool isInQuotes = false;

    for (int i = 0; i < o.size(); ++i) {
        if (ptr > 48) {     // To avoid out of range error
            cout << "[stringadd.cpp] Syntax Error! (Pointer out of range)" << endl;
            return 0;
        }
        c = o.at(i);

        if (isInQuotes == true) {
            if (c == '\"') {
                previousType = 1;
                isInQuotes = false;
                continue;
            } else {
                strings[ptr] += c;
                continue;
            }

            continue;
        }
        // The code isn't going further than that as long at there isn't another quote to close it.
        if (previousType == 0 || previousType == 3) {
            if (c == '\"') {
                isInQuotes = true;
                continue;
            } else if (isalpha(c)) {
                strings[ptr] = vars[toupper(c) - 'A'];
                previousType = 2;
                ++ptr;
                continue;
            } else if (c == '+') {
                cout << "[stringadd.cpp] Syntax Error! (Misplaced operator)" << endl;
                return "ERR";
            } else if (c == ' ') {
                continue;
            } else {
                cout << "[stringadd.cpp] Syntax Error! (Unknown character)" << endl;
                return "ERR";
            }
        } else if (previousType == 1 || previousType == 2) {
            if (c == '"') {
                cout << "[stringadd.cpp] Syntax Error! (Misplaced quote)" << endl;
                return "ERR";
            } else if (isalpha(c)) {
                cout << "[stringadd.cpp] Syntax Error! (Misplaced variable)" << endl;
                return "ERR";
            } else if (c == '+') {
                previousType = 3;
                ++ptr;
                continue;
            } else if (c == ' ') {
                continue;
            } else {
                cout << "[stringadd.cpp] Syntax Error! (Unknown character)" << endl;
                return "ERR";
            }
        }
    }

    endline = ptr + 1;
    for (int i = 0; i < endline; ++i) {
        outputStr += strings[i];
    }

    return outputStr;
}