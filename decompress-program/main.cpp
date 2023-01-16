//
//  main.cpp
//
//  Created by Beril Gürer
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // Initialize variables
    const int arraySize = 4096;
    int code = 255;
    int c;
    string decompinArray[arraySize] = {""};
    string p;

    int i = 0;
    while (i <= code) { // array is initialized for the first 256 singles character strings
        decompinArray[i] = string(1, char(i));
        i++;
    }
    
    ifstream compoutFile("compout"); //opening compressed file
    ofstream decompoutFile("decompout"); //opening compressed out file

    compoutFile >> c; // first value, write it to the output file
    decompoutFile << decompinArray[c];
    p = decompinArray[c];
    
    while (compoutFile >> c) { //decompress the value and add it to the array
        if (decompinArray[c] == "") {  // if not in array add it
            decompinArray[++code] = p + p[0];
            decompoutFile << decompinArray[code]; //write the value in compoutFile
        }
        else { // if in the array decompress it and add new value
            decompoutFile << decompinArray[c];
            decompinArray[++code] = p + decompinArray[c][0];
        }
        p = decompinArray[c];
    }
    decompoutFile.close();
    compoutFile.close();

    return 0;
}
