//
//  read_file.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/18/21.
//

#include "read_file.hpp"
#include <fstream>
#include <vector>

using namespace std;

void readFile(string graphType, vector<int> & input) {
    string prefix = "/Users/kehanzhang/Documents/CS7350 Project/";
    string suffix = ".txt";
    string filePath =  prefix + graphType + suffix;
    
    ifstream infile;
    infile.open(filePath, ios::in);
    if(!infile.is_open()) {
        exit(1);
    }
    
    int temp;
    while(infile >> temp) {
        input.push_back(temp);
    }
    
    infile.close();
}
