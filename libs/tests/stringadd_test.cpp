#include <iostream>
#include <string>
#include "../stringadd.h"
using namespace std;
//stringop.cpp string arithmetic evaluator test program
//This program is not meant to be compiled with the interpreter

//Making an array
string* vars = new string[26];
int* ivars = new int[26];
int main() {
    // Storing some test variables
    vars[0] = "beanos";   // Variable A = "beanos"
    vars[1] = "shrek";   // Variable B = "shrek"

    ivars[0] = 11;
    ivars[1] = 22;
    string result;

    string ari;
    getline(cin, ari);
    result = evalStringAddition(ari, vars, ivars);

    cout << endl << "=========" << endl << "Result : \"" << result << "\"" << endl;
    return 0;
}