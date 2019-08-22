// Simple string arithmetic interpreter by h34
// Originally designed for my MicrowaveBASIC interpreter

#include <iostream>
#include <string>
#include <ctype.h>
#include "stringop.h"
using namespace std;

bool isoperator(char c) {
    return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}

int* moveArrayLeft(int* arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        arr[i - 1] = arr[i];
    }

    return arr;
}

int evalString(std::string o, const int* vars, bool dev) {
    /* the vars array is the array where variables are stored.
       This has been made for being able to make arithmetics with
       variables of the BASIC Interpreter. If you don't need that, 
       just put an empty array.*/

    int* numbers = new int[100];
    int* ops = new int[99];  // 0 = Nothing | 1 = + | 2 = - | 3 = * | 4 = /
    // Supported operators : * / + -
    // Parentheses aren't supported.
    char c;
    int previousType = 0;    // O = Nothing | 1 = Number | 2 = Operator | 3 = Variable
    int ptr = 0;             // Pointer
    int endline;             // Position of the array where it ends

    //Step 1 - Sorting out stuff and put them in arrays
    for (int i = 0; i < o.size(); ++i) {
        if (ptr > 98) {
            cout << "[stringop.cpp] Syntax Error! (Pointer out of range)" << endl;
            return 0;
        }
        c = o.at(i);
        if (previousType == 0) {
            if (isoperator(c)) {
                cout << "[stringop.cpp] Syntax Error! (Misplaced operator)" << endl;
                return 0;
            } else if (isdigit(c)) {
                previousType = 1;
                numbers[ptr] = c - '0';
                continue;
            } else if (isalpha(c)) {
                previousType = 3;
                numbers[ptr] = vars[toupper(c) - 'A'];
                continue;
            } else if (c == ' ')
                continue;
            else {
                cout << "[stringop.cpp] Syntax Error! (Unknown character)" << endl;
                return 0;
            }

        } else if (previousType == 1) {
            if (isoperator(c)) {
                previousType = 2;
                if (c == '+')
                    ops[ptr] = 1;
                if (c == '-')
                    ops[ptr] = 2;
                if (c == '*')
                    ops[ptr] = 3;
                if (c == '/')
                    ops[ptr] = 4;
                
                ++ptr;
                continue;
            } else if (isdigit(c)) {
                numbers[ptr] = numbers[ptr] * 10 + (c - '0');
                continue; // No need to change the previous type since it's still the same
            } else if (isalpha(c)) {
                cout << "[stringop.cpp] Syntax Error! (Misplaced variable)" << endl;
                return 0;
            } else if (c == ' ')
                continue;
            else {
                cout << "[stringop.cpp] Syntax Error! (Unknown character)" << endl;
                return 0;
            }
        } else if (previousType == 2) {
            if (isoperator(c)) {
                cout << "[stringop.cpp] Syntax Error! (Misplaced operator)" << endl;
                return 0;
            } else if (isdigit(c)) {
                previousType = 1;
                numbers[ptr] = c - '0';
                continue;
            } else if (isalpha(c)) {
                previousType = 3;
                numbers[ptr] = vars[toupper(c) - 'A'];
                continue;
            } else if (c == ' ')
                continue;
            else {
                cout << "[stringop.cpp] Syntax Error! (Unknown character)" << endl;
                return 0;
            }
        } else if (previousType == 3) {
            if (isoperator(c)) {
                previousType = 2;
                if (c == '+')
                    ops[ptr] = 1;
                if (c == '-')
                    ops[ptr] = 2;
                if (c == '*')
                    ops[ptr] = 3;
                if (c == '/')
                    ops[ptr] = 4;
                
                ++ptr;
                continue;
            } else if (isalpha(c)) {
                cout << "[stringop.cpp] Syntax Error! (Misplaced variable)" << endl;
                return 0;
            } else if (c == ' ')
                continue;
            else {
                cout << "[stringop.cpp] Syntax Error! (Unknown character)" << endl;
                return 0;
            }
        }
    }

    endline = ptr + 1;
    if (dev) {
        cout << "Array variables data (from numbers and ops arrays)" << endl;
        for (int i = 0; i < endline; ++i) {
            cout << to_string(numbers[i]) << " ";
        }
        cout << endl;
        for (int i = 0; i < endline - 1; ++i) {
            cout << to_string(ops[i]);
        }
        cout << endl << endl;
    }

    // Step 2 - Make the calculation

    // Priority 1 - * and /
    for (int i = 0; i < endline - 1; ++i) {
        if ((ops[i] == 3) || (ops[i] == 4)) {
            if (ops[i] == 3)
                numbers[i + 1] = numbers[i] * numbers[i + 1];
            else
                numbers[i + 1] = numbers[i] / numbers[i + 1];
            
            numbers = moveArrayLeft(numbers, i + 1, endline);
            ops = moveArrayLeft(ops, i + 1, endline);
            --i;
            --endline;
            continue;
        } else
            continue;
    }

    // Priority 2 - + and -
    for (int i = 0; i < endline - 1; ++i) {
        if ((ops[i] == 1) || (ops[i] == 2)) {
            if (ops[i] == 1)
                numbers[i + 1] = numbers[i] + numbers[i + 1];
            else
                numbers[i + 1] = numbers[i] - numbers[i + 1];
            
            numbers = moveArrayLeft(numbers, i + 1, endline);
            ops = moveArrayLeft(ops, i + 1, endline);
            --i;
            --endline;
            continue;
        } else
            continue;
    }

    return numbers[0];
}
