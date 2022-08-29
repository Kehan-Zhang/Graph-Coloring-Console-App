//
//  bfs_ordering.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/19/21.
//

#include "bfs_ordering.hpp"
#include "vertex.hpp"
#include "read_file.hpp"
#include "create_adjacency_list.hpp"
#include "coloring.hpp"
#include "output_result.hpp"
#include "output.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

void bfsOrdering(string graphType) {
    // Read graph from file
    vector<int> input;
    readFile(graphType, input);
 
    // Create adjacency list
    int n = input[0];
    VertexNode adjList[n];
    createAdjacencyList(adjList, input);
    
    clock_t start, end;
    start = clock();
    
    // Ordering
    int reached[n];
    for(int i = 0; i < n; i++) {
        reached[i] = 0;
    }
    
    int pos = -1;
    queue<int> frontier;
    for(int i = 0; i < n; i++) {
        if(adjList[i].originalDegree != 0) {
            pos = i;
            break;
        }
    }
    
    int count = 0;
    int *order = new int[n];
    frontier.push(pos);
    reached[pos] = 1;
    while(!frontier.empty()) {
        pos = frontier.front();
        frontier.pop();
        order[count] = pos;
        count++;
        AdjNode * q;
        for(q = adjList[pos].firstAdjNode; q != NULL; q = q -> next) {
            if(reached[q -> index] == 0) {
                frontier.push(q -> index);
                reached[q -> index] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(adjList[i].originalDegree == 0) {
            order[count] = i;
            count++;
        }
    }
    
    end = clock();
    coloring(adjList, order, n);
    output(order, n, adjList);
//    outputResult("BFS Ordering", n, adjList);
    delete [] order;
    cout << "BFS Ordering Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
