#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "fileman.h"
#include "../utils.h"
#include "stringop.h"
using namespace std;

inline bool file_exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

// File managing functions to save/load BAS Files
int saveFile(const string name, const string* prgmArray, const bool overwrite) {
    string fpname = "programs/" + name;
    

    if (file_exists(fpname)) {
        if (overwrite) {
            cout << "[fileman.cpp] " << name << " exists! Overwriting it..." << endl;
            int rem = remove(fpname.c_str());

            if (rem != 0) {
                cout << "[fileman.cpp] File Error! " << name << "Couldn't be deleted/overwritten." << endl;
                return 1;
            }
        } else {
            cout << "[fileman.cpp] " << name << " exists! Program couldn't be saved." << endl;
            return 1;
        }
    }

    cout << "[fileman.cpp] Done!" << endl;
    ofstream basfile;
    basfile.open(fpname);

    if (basfile.is_open()) {
        for (int i = 0; i < 999999; ++i) {
            if (prgmArray[i] == "")
                continue;
            
            basfile << to_string(i) << " " << prgmArray[i] << "\n";
        }
        basfile.close();
    } else {
        cout << "[fileman.cpp] File Error! " << "Unable to open file." << endl;
        return 1;
    }
    return 0;
}

int loadFile(const string name, string* prgmArray) {
    string fpname = "programs/" + name;
    if (!file_exists(fpname)) {
        cout << "[fileman.cpp] File Error! " << name << "doesn't exist." << endl;
        return 1;
    }

    string line;
    ifstream basfile;
    basfile.open(fpname);

    string tmp;
    int linenum;
    while (getline(basfile, line)) {
        if (is_number(trimString(line, 0, searchChar(' ', line) - 1))) {
            tmp = trimString(line, 0, searchChar(' ', line));
            int linnum = evalString(tmp, new int[26], false);  // Lmao I can't code :D
            prgmArray[linnum] = line.erase(0, tmp.size());
        }
    }

    return 0;
}