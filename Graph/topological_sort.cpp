/* topological sort implementation */

#include <iostream>
#include "graph.h"
#include "stack.h"

using namespace std;

/* graph */
struct Edge
{
    Vertex w;
    struct Edge *next;
};

struct Node
{
    Vertex v;
    struct Edge *first;
};

struct GraphRep
{
    struct Node *nodes;
    int nV;
    int nE;
    bool *is_vertex_exist;
};

/* stack */
struct LNode
{
    int data;
    struct LNode *next;
};

void find_indegree(graph G, int *indegree)

bool topological_sort(graph G)
{
    int *indegree;
    find_indegree(G, indegree);

    stack S;
    init_stack(S);

    for (int i = 0; i < G->nV; i++)
    {
        if (!indegree[i])
        {
            push()
        }
    }
}

int main()
{
    cin.get();
}