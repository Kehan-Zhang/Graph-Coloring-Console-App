//
//  smallest_index_first_ordering.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/19/21.
//

#include "smallest_index_first_ordering.hpp"
#include "vertex.hpp"
#include "read_file.hpp"
#include "create_adjacency_list.hpp"
#include "coloring.hpp"
#include "output_result.hpp"
#include "output.hpp"
#include <iostream>
#include <string>
#include <vector>

void smallestIndexFirstOrdering(string graphType) {
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
    
    end = clock();
    coloring(adjList, order, n);
    output(order, n, adjList);
//    outputResult("Smallest Index First Ordering", n, adjList);
    delete [] order;
    cout << "Smallest Index First Ordering Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
