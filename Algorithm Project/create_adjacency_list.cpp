//
//  create_adjacency_list.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/18/21.
//

#include "create_adjacency_list.hpp"
#include "vertex.hpp"
#include <vector>

using namespace std;

void createAdjacencyList(VertexNode * adjList, vector<int> & input) {
    int n = input[0];
    int p[n + 1];
    for(int i = 0; i < n; i++) {p[i] = input[i + 1];}
    p[n] = (int)input.size();
    
    for(int i = 0; i < n; i++) {
        adjList[i].index = i;
        adjList[i].originalDegree = 0;
        adjList[i].currentDegree = 0;
        adjList[i].color = -1;
        adjList[i].isDeleted = 0;
        adjList[i].firstAdjNode = NULL;
        
        for(int j = p[i]; j < p[i + 1]; j++) {
            AdjNode * adjNode = new AdjNode;
            adjNode -> index = input[j];
            adjNode -> next = adjList[i].firstAdjNode;
            adjList[i].firstAdjNode = adjNode;
            adjList[i].originalDegree++;
            adjList[i].currentDegree++;
        }
    }
}
