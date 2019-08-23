#include <iostream>
#include <string>
#include <sstream>
#include "utils.h"

using namespace std;
// This file contains many useful commands to be globally used which
// most of them come from Stack Overflow lol

// To check if a string is a number
bool is_number(const std::string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool starts_with(const std::string s, const std::string t) {
    if (s == "")
        return false;

    for (int i = 0; i < t.size(); ++i) {
        if (s.at(i) != t.at(i))
            return false;
    }

    return true;
}

string to_upper(const std::string s) {
    string o = "";

    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s.at(i)))
            o += toupper(s.at(i));
    }

    return o;
}

// search a specific character
int searchChar(char target, string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == target)
            return i;
    }

    return -1;  // Returns -1 if nothing has been found
}

// To split spaces and put every words into a string array
std::string* splitSpaces(std::string line)
{
    string* arr = new string[20];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 20){
        if (arr[i] == "")
            break;
        ssin >> arr[i];
        ++i;
    }

    return arr;
}

string trimString(string s, int start, int end) {
    string o = "";
    for (int i = start; i <= end; ++i) {
        o += s.at(i);
    }

    return o;
}