//
//  circle_graph_generator.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/17/21.
//

#include "circle_graph_generator.hpp"
#include "vertex.hpp"
#include "write_file.hpp"
#include <iostream>
using namespace std;

void circleGraph(int n) {
    clock_t start, end;
    start = clock();
    
    // Create adjacency list
    VertexNode adjList[n];
    for(int i = 0; i < n; i++) {
        adjList[i].index = i;
        adjList[i].firstAdjNode = NULL;
        
        AdjNode * adjNode1 = new AdjNode;
        if (i + 1 >= n)
            adjNode1 -> index = 0;
        else
            adjNode1 -> index = i + 1;
        adjNode1 -> next = adjList[i].firstAdjNode;
        adjList[i].firstAdjNode = adjNode1;
        
        AdjNode * adjNode2 = new AdjNode;
        if(i - 1 < 0)
            adjNode2 -> index = n - 1;
        else
            adjNode2 -> index = i - 1;
        adjNode2 -> next = adjList[i].firstAdjNode;
        adjList[i].firstAdjNode = adjNode2;
    }
    
    end = clock();
    writeFile("CircleGraph", n, 0, adjList);
    cout << "Generate Circle Graph Runtime: " << (double)(end - start)/CLOCKS_PER_SEC << endl;
}
