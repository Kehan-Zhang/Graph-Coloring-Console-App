//
//  smallest_original_degree_last_ordering.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/19/21.
//

#include "smallest_original_degree_last_ordering.hpp"
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

void smallestOriginalDegreeLastOrdering(string graphType) {
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
    int count = n - 1;
    for(int i = 0; i < n; i++) {
        DegreeNode *q;
        for(q = degreeList[i].firstDegreeNode; q != NULL ; q = q -> next) {
            order[count] = q -> index;
            count--;
        }
    }

    end = clock();
    coloring(adjList, order, n);
    output(order, n, adjList);
//    outputResult("Smallest Original Degree Last Ordering", n, adjList);
    delete [] order;
    cout << "Smallest Original Degree Last Ordering Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
