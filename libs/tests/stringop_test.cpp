#include <iostream>
#include <string>
#include "../stringop.h"
using namespace std;
//stringop.cpp string arithmetic evaluator test program
//This program is not meant to be compiled with the interpreter

//Making an array
int* vars = new int[26];

int main() {
    // Storing some test variables
    vars[0] = 22;   // Variable A = 22
    vars[1] = 48;   // Variable B = 48
    int result;

    string ari;
    getline(cin, ari);
    result = evalString(ari, vars, true);

    cout << endl << "=========" << endl << "Result : " << to_string(result) << endl;
    return 0;
}