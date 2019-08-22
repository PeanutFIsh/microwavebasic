#include <iostream>
#include <string>
#include "../stringcond.h"
using namespace std;
//stringop.cpp string arithmetic evaluator test program
//This program is not meant to be compiled with the interpreter

//Making an array
string* vars = new string[26];
int* varsi = new int[26];
string boolToStr(bool b) {
    if (b)
        return "true";
    else
        return "false";
}

void eint() {
    // Storing some test variables
    varsi[0] = 22;   // Variable A = 22
    varsi[1] = 48;   // Variable B = 48
    int result;

    string ari;
    getline(cin, ari);
    result = evalIntCondition(ari, varsi);

    cout << endl << "=========" << endl << "Result : " << boolToStr(result) << endl;
}

void estr() {
    // Storing some test variables
    vars[0] = "beanos";   // Variable A = "beanos"
    vars[1] = "shrek";   // Variable B = "shrek"
    bool result;

    string ari;
    getline(cin, ari);
    result = evalStrCondition(ari, vars);

    cout << endl << "=========" << endl << "Result : \"" << boolToStr(result) << "\"" << endl;
}

int main() {
    cout << "Type 'shrek' to get in int mode and 'beanos' to get in string mode";
    string choice;
    getline(cin, choice);

    cout << endl << ">>";
    if (choice == "shrek") {
        eint();
    } else if (choice == "beanos") {
        estr();
    }
}