//
//  uniform_random_graph_generator.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/17/21.
//

#include "uniform_random_graph_generator.hpp"
#include "vertex.hpp"
#include "write_file.hpp"
#include <iostream>
using namespace std;

void uniformRandomGraph(int n, int m) {
    clock_t start, end;
    start = clock();
    
    // Init adjacency list
    VertexNode adjList[n];
    for (int i = 0; i < n; i++) {
        adjList[i].index = i + 1;
        adjList[i].firstAdjNode = NULL;
        adjList[i].originalDegree = 0;
    }
    
    // Create 2-dimentional array and make it random later
    int **random = new int *[n];
    for (int i = 0; i < n; i++)
        random[i] = new int[n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            random[i][j] = 0;
    
    int count = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            random[i][j] = count++;
   
    // Shuffle the array row by row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int pos = rand() % i;
            int temp = random[i][j];
            random[i][j] = random[i][pos];
            random[i][pos] = temp;
        }
    }
    
    // Shuffle the array column by column
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            int pos = rand() % (n - i - 1) + i + 1;
            int temp = random[j][i];
            random[j][i] = random[pos][i];
            random[pos][i] = temp;
        }
    }
    
    // Generate edges according to the shuffled 2-dimentional array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (random[i][j] <= m) {
                AdjNode * adjNode1 = new AdjNode;
                adjNode1 -> index = j;
                adjNode1 -> next = adjList[i].firstAdjNode;
                adjList[i].firstAdjNode = adjNode1;

                AdjNode * adjNode2 = new AdjNode;
                adjNode2 -> index = i;
                adjNode2 -> next = adjList[j].firstAdjNode;
                adjList[j].firstAdjNode = adjNode2;
            }
        }
    }

    end = clock();
    writeFile("UniformRandomGraph", n, m, adjList);
    cout << "Generate Uniform Random Graph Runtime: " << (double)(end - start)/CLOCKS_PER_SEC << endl;
    
    // Free the space of 2-dimentional array
    for (int i = 0; i < n; i++)
        delete[] random[i];
    delete[] random;
}
