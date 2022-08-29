//
//  main.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/15/21.
//

#include <iostream>
#include <fstream>
#include "vertex.hpp"
#include "complete_graph_generator.hpp"
#include "circle_graph_generator.hpp"
#include "uniform_random_graph_generator.hpp"
#include "skewed_random_graph_generator.hpp"
#include "normal_random_graph_generator.hpp"
#include "smallest_last_ordering.hpp"
#include "smallest_original_degree_last_ordering.hpp"
#include "uniform_random_ordering.hpp"
#include "smallest_index_first_ordering.hpp"
#include "largest_first_ordering.hpp"
#include "bfs_ordering.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    completeGraph(n);
    circleGraph(n);
    uniformRandomGraph(n, m);
    skewedRandomGraph(n, m);
    normalRandomGraph(n, m);
    smallestLastOrdering("UniformRandomGraph");
    smallestOriginalDegreeLastOrdering("UniformRandomGraph");
    uniformRandomOrdering("UniformRandomGraph");
    smallestIndexFirstOrdering("UniformRandomGraph");
    largestFirstOrdering("UniformRandomGraph");
    bfsOrdering("UniformRandomGraph");
    return 0;
}








