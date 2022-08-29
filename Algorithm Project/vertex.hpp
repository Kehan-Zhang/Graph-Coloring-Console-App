//
//  vertex.hpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/17/21.
//

#ifndef vertex_hpp
#define vertex_hpp

#include <stdio.h>

struct AdjNode {
    int index;
    AdjNode * next;
};

struct DegreeNode {
    int index;
    DegreeNode * prior;
    DegreeNode * next;
};

struct Degree {
    int countNode;
    DegreeNode * firstDegreeNode;
};

struct VertexNode {
    int index;
    int countAdjNode;
    int originalDegree;
    int currentDegree;
    int isDeleted;
    int color;
    AdjNode * firstAdjNode;
    DegreeNode * degreeNode;
};

#endif /* vertex_hpp */
