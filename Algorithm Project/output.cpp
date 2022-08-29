//
//  output.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/20/21.
//

#include "output.hpp"
#include "vertex.hpp"
#include <iostream>

using namespace std;

void output(int * order, int n, VertexNode * adjList) {
    int maxColor = 0;
    int sumDegree = 0;
    for(int i = 0; i < n; i++) {
        if(adjList[order[i]].color > maxColor) {
            maxColor = adjList[order[i]].color;
        }
        sumDegree += adjList[order[i]].originalDegree;
        cout << "Vertex: " << order[i]
             << ", Color: " << adjList[order[i]].color
             << ", Original degree: " << adjList[order[i]].originalDegree << endl;
    }
    cout << "Number of colors: " << maxColor + 1 << endl;
    cout << "Average original degree: " << sumDegree / n << endl;
}
