//
//  uniform_random_ordering.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/19/21.
//

#include "uniform_random_ordering.hpp"
#include "vertex.hpp"
#include "read_file.hpp"
#include "create_adjacency_list.hpp"
#include "coloring.hpp"
#include "output_result.hpp"
#include "output.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void uniformRandomOrdering(string graphType) {
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
    int *order = new int[n];
    for(int i = 0; i < n; i++) {
        order[i] = i;
    }
    
    // Shuffle the order array, and the sequence after shuffling is the order sequence
    for (int i = 0; i < n; i++) {
        int pos = rand() % n;
        int temp = order[i];
        order[i] = order[pos];
        order[pos] = temp;
    }

    end = clock();
    coloring(adjList, order, n);
    output(order, n, adjList);
//    outputResult("Uniform Random Ordering", n, adjList);
    delete [] order;
    cout << "Uniform Random Ordering Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

