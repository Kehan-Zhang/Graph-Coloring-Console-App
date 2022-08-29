//
//  output_slvo.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/20/21.
//

#include "output_slvo.hpp"
#include "vertex.hpp"
#include <iostream>

using namespace std;

void outputSLVO(int * order, int n, VertexNode * adjList) {
    int maxColor = 0;
    int sumDegree = 0;
    int maxDeletedDegree = 0;
    int cliqueSize = 1;
    for(int i = 0; i < n - 1; i++) {
        if(adjList[order[i + 1]].currentDegree - adjList[order[i]].currentDegree == 1) {
            cliqueSize++;
        } else {
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(adjList[order[i]].color > maxColor) {
            maxColor = adjList[order[i]].color;
        }
        if(adjList[order[i]].currentDegree > maxDeletedDegree) {
            maxDeletedDegree = adjList[order[i]].currentDegree;
        }
        sumDegree += adjList[order[i]].originalDegree;
        cout << "Vertex: " << order[i]
             << ", Color: " << adjList[order[i]].color
             << ", Original degree: " << adjList[order[i]].originalDegree
             << ", Degree when deleted: " << adjList[order[i]].currentDegree << endl;
        cout << adjList[order[i]].currentDegree << endl;
    }
    cout << "Number of colors: " << maxColor + 1 << endl;
    cout << "Average original degree: " << sumDegree / n << endl;
    cout << "Maximum degree when deleted: " << maxDeletedDegree << endl;
    cout << "Size of terminal clique: " << cliqueSize << endl;
}
