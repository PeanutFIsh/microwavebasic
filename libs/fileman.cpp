#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "fileman.h"
using namespace std;

inline bool file_exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

// File managing functions to save/load BAS Files
int saveFile(string name, string* prgmArray, bool overwrite) {
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

    cout << "Done!" << endl;
    ofstream basfile;
    basfile.open(fpname);

    for (int i = 0; i < 999999; ++i) {
        if (prgmArray[i] == "")
            continue;
        
        basfile << to_string(i) << " " << prgmArray[i] << "\n";
    }

    return 0;
}