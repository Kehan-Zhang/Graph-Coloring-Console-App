//
//  output_result.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/20/21.
//

#include "output_result.hpp"
#include "vertex.hpp"
#include <iostream>
#include <fstream>
#include <string>

void outputResult(string orderType, int n, VertexNode * adjList) {
    string prefix = "/Users/kehanzhang/Documents/CS7350 Project/";
    string suffix = ".txt";
    string filePath =  prefix + orderType + suffix;
    
    ofstream outfile;
    outfile.open(filePath, ios::out);
    if(!outfile.is_open()) {
        exit(1);
    }
    
    for(int i = 0; i < n ; i++) {
        outfile << i << ',' << adjList[i].color << endl;
    }
    
    outfile.close();
}
