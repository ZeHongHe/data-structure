// Graph
// Adjacency Matrix Representation

#include <iostream>

#define MaxVertexNum 100
#define VextexType char
#define EdgeType int

using namespace std;

struct Graph 
{
    VextexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexNum, edgeNum;
};

typedef struct Graph graph;

int main()
{

    cin.get();
}