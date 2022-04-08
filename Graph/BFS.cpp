// BFS
// Adjacency Matrix Representation

#include "queue.h"
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

bool visited[MaxVertexNum];

void bfs_traverse(Graph G)
{
    for (int i = 0; i < G.vexNum; ++i)
        visited[i] = false;
    
}

int main()
{

    cin.get();
}