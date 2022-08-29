//
//  complete_graph_generator.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/17/21.
//

#include "complete_graph_generator.hpp"
#include "vertex.hpp"
#include "write_file.hpp"
#include <iostream>
using namespace std;

void completeGraph(int n) {
    clock_t start, end;
    start = clock();
    
    // Create adjacency list
    VertexNode adjList[n];
    for(int i = 0; i < n; i++) {
        adjList[i].index = i;
        adjList[i].firstAdjNode = NULL;
        
        for(int j = 0; j < n; j++) {
            if(j != i) {
                AdjNode * adjNode = new AdjNode;
                adjNode -> index = j;
                adjNode -> next = adjList[i].firstAdjNode;
                adjList[i].firstAdjNode = adjNode;
            }
        }
    }
    
    end = clock();
    writeFile("CompleteGraph", n, 0, adjList);
    cout << "Generate Complete Graph Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
