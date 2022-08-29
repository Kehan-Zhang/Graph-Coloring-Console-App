//
//  skewed_random_graph_generator.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/17/21.
//

#include "skewed_random_graph_generator.hpp"
#include "vertex.hpp"
#include "write_file.hpp"
#include <iostream>
#include <cmath>
using namespace std;

void skewedRandomGraph(int n, int m) {
    clock_t start, end;
    start = clock();
    int edges = m;
    
    // Init adjacency list
    VertexNode adjList[n];
    for(int i = 0; i < n; i++) {
        adjList[i].index = i + 1;
        adjList[i].countAdjNode = 0;
        adjList[i].firstAdjNode = NULL;
    }
    
    // Create adjacency matrix and use it to quick check if an edge is generated repeatly
    int **adjMatrix = new int *[n];
    for(int i = 0; i < n; i++)
        adjMatrix[i] = new int[n]();

    // Generate random edges and create adjacency list
    while(edges != 0) {
        double slope = - 2;
        double max = 1;
        double min = 0;
        double a = 0.5 * slope;
        double b = (1 - 0.5 * slope * (pow(max, 2) - pow(min, 2)))/(max - min);
        double c1 = - 0.5 * slope * pow(min, 2) - b * min - (rand() * 1.0f / RAND_MAX);
        double c2 = - 0.5 * slope * pow(min, 2) - b * min - (rand() * 1.0f / RAND_MAX);
        int vertex1 = (-b + sqrt(pow(b, 2) - 4 * a * c1))/(2 * a) * n;
        int vertex2 = (-b + sqrt(pow(b, 2) - 4 * a * c2))/(2 * a) * n;

        if(vertex1 < 0 || vertex2 < 0 || vertex1 >= n || vertex2 >= n)
            continue;
        if(vertex1 == vertex2)
            continue;
        if(adjList[vertex1].countAdjNode == n - 1 || adjList[vertex2].countAdjNode == n - 1)
            continue;
        if(adjMatrix[vertex1][vertex2] == 1)
            continue;

        AdjNode * adjNode1 = new AdjNode;
        adjNode1 -> index = vertex2;
        adjNode1 -> next = adjList[vertex1].firstAdjNode;
        adjList[vertex1].firstAdjNode = adjNode1;
        adjList[vertex1].countAdjNode++;

        AdjNode * adjNode2 = new AdjNode;
        adjNode2 -> index = vertex1;
        adjNode2 -> next = adjList[vertex2].firstAdjNode;
        adjList[vertex2].firstAdjNode = adjNode2;
        adjList[vertex2].countAdjNode++;

        adjMatrix[vertex1][vertex2] = 1;
        adjMatrix[vertex2][vertex1] = 1;
        edges--;
    }
    
    end = clock();
    writeFile("SkewedRandomGraph", n, m, adjList);
    cout << "Generate Skewed Random Graph Runtime:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
    
    // Free the space of 2-dimentional array
    for (int i = 0; i < n; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}
