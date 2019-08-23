#include <iostream>
#include <string>
#include "stringadd.h"
#include "stringop.h"
#include "stringcond.h"
using namespace std;

string trimStr(string s, int start, int end) {
    string o = "";
    for (int i = start; i <= end; ++i) {
        o += s.at(i);
    }

    return o;
}

// To eval strings
bool evalStrCondition(string condition, std::string* vars) {
    char c;
    int ops = 0;
    int operatorPos = 0;
    char op;
    string expA, expB;

    if (condition == "TRUE")
        return true;
    else if (condition == "FALSE")
        return false;

    // Those lines of code are there to control the number of operators
    // (It must have only one)
    for (int i = 0; i < condition.size(); ++i) {        // Must check if there is only one operator
        c = condition.at(i);
        if (c == '=' || c == '!')
            ++ops;
        // Operator at the first character
        if (i == 0 && ops == 1) {
            cout << "[stringcond.cpp] Syntax Error! (Misplaced operator)" << endl;
            return false;
        }

        if (ops == 1 && operatorPos == 0) {
            operatorPos = i;
            op = c;
        }

        // Too many operators
        if (ops > 1) {
            cout << "[stringcond.cpp] Syntax Error! (Too many operators)" << endl;
            return false; 
        }

        // Operator at the end of the string
        if (ops == 1 && operatorPos == condition.size() - 1) {
            cout << "[stringcond.cpp] Syntax Error! (Misplaced operator)" << endl;
            return false;
        }
    }

    // No operators
    if (ops == 0) {
        cout << "[stringcond.cpp] Syntax Error! (No operators)" << endl;
        return false;
    }

    expA = trimStr(condition, 0, operatorPos - 1);
    expB = trimStr(condition, operatorPos + 1, condition.size() - 1);

    if (op == '=') {
        if (evalStringAddition(expA, vars) == evalStringAddition(expB, vars))
            return true;
        else
            return false;
    } else {
        if (evalStringAddition(expA, vars) != evalStringAddition(expB, vars))
            return true;
        else
            return false;
    }

    return false;
}


bool evalIntCondition(string condition, int* vars) {
    char c;
    int ops = 0;
    int operatorPos = 0;
    char op;
    string expA, expB;

    if (condition == "TRUE")
        return true;
    else if (condition == "FALSE")
        return false;

    // Those lines of code are there to control the number of operators
    // (It must have only one)
    for (int i = 0; i < condition.size(); ++i) {        // Must check if there is only one operator
        c = condition.at(i);
        if (c == '=' || c == '!' || c == '>' || c == '<')
            ++ops;
        // Operator at the first character
        if (i == 0 && ops == 1) {
            cout << "[stringcond.cpp] Syntax Error! (Misplaced operator)" << endl;
            return false;
        }

        if (ops == 1 && operatorPos == 0) {
            operatorPos = i;
            op = c;
        }

        // Too many operators
        if (ops > 1) {
            cout << "[stringcond.cpp] Syntax Error! (Too many operators)" << endl;
            return false; 
        }

        // Operator at the end of the string
        if (ops == 1 && operatorPos == condition.size() - 1) {
            cout << "[stringcond.cpp] Syntax Error! (Misplaced operator)" << endl;
            return false;
        }
    }

    // No operators
    if (ops == 0) {
        cout << "[stringcond.cpp] Syntax Error! (No operators)" << endl;
        return false;
    }

    expA = trimStr(condition, 0, operatorPos - 1);
    expB = trimStr(condition, operatorPos + 1, condition.size() - 1);

    if (op == '=') {
        if (evalString(expA, vars, false) == evalString(expB, vars, false))
            return true;
        else
            return false;
    } else if (op == '!') {
        if (evalString(expA, vars, false) != evalString(expB, vars, false))
            return true;
        else
            return false;
    } else if (op == '>') {
        if (evalString(expA, vars, false) > evalString(expB, vars, false))
            return true;
        else
            return false;
    } else if (op == '<') {
        if (evalString(expA, vars, false) > evalString(expB, vars, false))
            return true;
        else
            return false;
    }

    return false;
}