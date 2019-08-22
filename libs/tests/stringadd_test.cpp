#include <iostream>
#include <string>
#include "../stringadd.h"
using namespace std;
//stringop.cpp string arithmetic evaluator test program
//This program is not meant to be compiled with the interpreter

//Making an array
string* vars = new string[26];

int main() {
    // Storing some test variables
    vars[0] = "beanos";   // Variable A = "beanos"
    vars[1] = "shrek";   // Variable B = "shrek"
    string result;

    string ari;
    getline(cin, ari);
    result = evalStringAddition(ari, vars);

    cout << endl << "=========" << endl << "Result : \"" << result << "\"" << endl;
    return 0;
}