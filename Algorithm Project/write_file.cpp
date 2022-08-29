//
//  write_file.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/18/21.
//

#include "write_file.hpp"
#include "vertex.hpp"
#include <iostream>
#include <fstream>

void writeFile(string graphType, int n, int m, VertexNode * adjList) {
    string prefix = "/Users/kehanzhang/Documents/CS7350 Project/";
    string suffix = ".txt";
    string filePath =  prefix + graphType + suffix;
    
    ofstream outfile;
    outfile.open(filePath, ios::out);
    if(!outfile.is_open()) {
        exit(1);
    }
    
    if(graphType == "CompleteGraph") {
        // Create output array whose length is
        // 1(number of vertices) + n(length of P[]) + 2 * n * (n - 1) / 2(length of E[])
        // = n * n + 1
        int *output = new int[n * n + 1];
        output[0] = n;
        int e = n + 1, p = 1;
        for(int i = 0; i < n ; i++) {
            output[p++] = e;
            AdjNode *q;
            for(q = adjList[i].firstAdjNode; q != NULL ; q = q -> next) {
                output[e++] = q -> index;
            }
        }
        for(int i = 0; i < n * n + 1; i ++) {
            outfile << output[i] << endl;
        }
        delete [] output;
    } else if(graphType == "CircleGraph") {
        // Create output array whose length is
        // 1(number of vertices) + n(length of P[]) + 2 * n(length of E[])
        // = 3 * n + 1
        int *output = new int[3 * n + 1];
        output[0] = n;
        int e = n + 1, p = 1;
        for(int i = 0; i < n ; i++) {
            output[p++] = e;
            AdjNode *q;
            for(q = adjList[i].firstAdjNode; q != NULL ; q = q -> next) {
                output[e++] = q -> index;
            }
        }
        for(int i = 0; i < 3 * n + 1; i ++) {
            outfile << output[i] << endl;
        }
        delete [] output;
    } else {
        // Create output array whose length is
        // 1(number of vertices) + n(length of P[]) + 2 * m(length of E[])
        // = n + 2 * m + 1
        int *output = new int[n + 2 * m + 1];
        output[0] = n;
        int e = n + 1, p = 1;
        for (int i = 0; i < n ; i++) {
            output[p++] = e;
            AdjNode *q;
            for(q = adjList[i].firstAdjNode; q != NULL ; q = q -> next) {
                output[e++] = q -> index;
            }
        }
        for (int i = 0; i < n + 2 * m + 1; i ++) {
            outfile << output[i] << endl;
        }
        delete [] output;
    }
    
    outfile.close();
}
