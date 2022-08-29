//
//  coloring.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/18/21.
//

#include "coloring.hpp"
#include <iostream>

using namespace std;

void coloring(VertexNode * adjList, int * order, int n) {
    for(int i = 0; i < n; i++) {
        // Init color array
        int *color = new int[n]();
        
        // Find all the color that have been used by the vetices that have an edge with this node
        AdjNode *q;
        for(q = adjList[order[i]].firstAdjNode; q != NULL ; q = q -> next) {
            color[adjList[q -> index].color] = 1;
        }
        
        for(int j = 0; j < n; j++) {
            if(color[j] == 0) {
                adjList[order[i]].color = j;
                break;
            }
        }
        
        // Free the memeory
        delete [] color;
    }
}
