//
//  largest_first_ordering.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/19/21.
//

#include "largest_first_ordering.hpp"
#include "read_file.hpp"
#include "vertex.hpp"
#include "create_adjacency_list.hpp"
#include "coloring.hpp"
#include "output_result.hpp"
#include "output.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void largestFirstOrdering(string graphType) {
    // Read graph from file
    vector<int> input;
    readFile(graphType, input);
 
    // Create adjacency list
    int n = input[0];
    VertexNode adjList[n];
    createAdjacencyList(adjList, input);
    
    // Create degree list according to adjacency list
    Degree degreeList[n];
    for(int i = 0; i < n; i++) {
        degreeList[i].countNode = 0;
        degreeList[i].firstDegreeNode = NULL;
    }
    
    for(int i = 0; i < n; i++) {
        int degree = adjList[i].originalDegree;
        DegreeNode * degreeNode = new DegreeNode;
        if(degreeList[degree].firstDegreeNode) {
            degreeList[degree].firstDegreeNode -> prior = degreeNode;
        }
        degreeNode -> index = i;
        degreeNode -> prior = NULL;
        degreeNode -> next = degreeList[degree].firstDegreeNode;
        degreeList[degree].firstDegreeNode = degreeNode;
        degreeList[degree].countNode++;
        adjList[i].degreeNode = degreeNode;
    }
    
    clock_t start, end;
    start = clock();
    
    // Ordering
    int *order = new int[n];
    int count = 0;
    while(count < n) {
        for(int i = n - 1; i >= 0; i--) {
            if(degreeList[i].countNode != 0) {
                // Delete this node from degree list
                int nodeIndex = degreeList[i].firstDegreeNode -> index;
                order[count] = nodeIndex;
                count++;
                degreeList[i].firstDegreeNode = degreeList[i].firstDegreeNode -> next;
                if(degreeList[i].firstDegreeNode) {
                    degreeList[i].firstDegreeNode -> prior = NULL;
                }
                degreeList[i].countNode--;
                adjList[nodeIndex].isDeleted = -1;
                // Each node that have an edge with this node degree minus 1
                AdjNode *q;
                for(q = adjList[nodeIndex].firstAdjNode; q != NULL ; q = q -> next) {
                    if(adjList[q -> index].isDeleted == 0) {
                        DegreeNode * degreeNode = new DegreeNode;
                        degreeNode = adjList[q -> index].degreeNode;
                        int currentNodeDegree = adjList[q -> index].currentDegree;
                        if(!degreeNode -> prior && !degreeNode -> next) {
                            degreeList[currentNodeDegree].firstDegreeNode = NULL;
                        } else if(!degreeNode -> prior) {
                            degreeList[currentNodeDegree].firstDegreeNode = degreeNode -> next;
                            degreeNode -> next -> prior = NULL;
                        } else if(!degreeNode -> next){
                            degreeNode -> prior -> next = NULL;
                        } else {
                            degreeNode -> prior -> next = degreeNode -> next;
                            degreeNode -> next -> prior = degreeNode -> prior;
                        }
                        adjList[q -> index].currentDegree--;
                        degreeList[currentNodeDegree].countNode--;
                        
                        currentNodeDegree = adjList[q -> index].currentDegree;
                        if(degreeList[currentNodeDegree].firstDegreeNode) {
                            degreeList[currentNodeDegree].firstDegreeNode -> prior = degreeNode;
                        }
                        degreeNode -> next = degreeList[currentNodeDegree].firstDegreeNode;
                        degreeNode -> prior = NULL;
                        degreeList[currentNodeDegree].firstDegreeNode = degreeNode;
                        degreeList[currentNodeDegree].countNode++;
                    }
                }
                break;
            }
        }
    }
    
    end = clock();
    coloring(adjList, order, n);
    output(order, n, adjList);
//    outputResult("Largest First Ordering", n, adjList);
    delete [] order;
    cout << "Largest First Ordering Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
