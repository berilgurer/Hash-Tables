//
//  main.cpp
//
//  Created by Beril Gürer
//

#include <iostream>
#include <string>
#include <fstream>
#include "Hashtable.cpp"

using namespace std;

int main()
{
    //Initialize variables
    bool tableIsFull = false;
    char letter;
    int code = 0;
    string temp = "";
    string p = "";
    string c = "";
    string pc = "";
    ifstream compinFile("compin");// we will compress this
    ofstream compoutFile("compout");// compressed version of compin
    
    HashTable<string> myTable("default", 4096); //creating the table with size of 4096 and default value
    
    while(code <= 255){ // hash table is initialized for the first 256 singles character strings
        temp = char(code);
        myTable.insert(temp, code);
        code++;
    }
    
    while (compinFile.get(letter))
    {
        c = letter;
        pc = p + c;
        if (myTable.find(pc) != 0)
            p = pc;
        else if(!myTable.hashtableFull()){ //if table is not full
            myTable.insert(pc, code);
            code++;
            compoutFile << myTable.find(p) << " ";
            p = c;
        }
        else if(myTable.hashtableFull()){ //if table is full
            tableIsFull = true;
            compoutFile << myTable.find(p) << " ";
            p = c;
        }
        else{
            compoutFile << myTable.find(p) << " ";
            p = c;
        }
    }
    compoutFile << myTable.find(p); //write the last piece

    compinFile.close();
    compoutFile.close();

    return 0;
}
