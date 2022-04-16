/* Graph Using Adjacency Matrix */

#include "graph.h"
#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

/* graph */
struct GraphRep
{
    int **edges;
    int nV;
    int nE;
    bool *is_vertex_exist;
};

struct Edge
{
    int v;
    int w;
};

void visit(graph G, int v)
{
    printf("%d", v);
}

/* v is start vertex on a dfs process */
void dfs(graph G, int v, bool *visited)
{
    visit(G, v);
    visited[v] = true;

    for (int w = first_neighbor(G, v); w >= 0; w = next_neighbor(G, v, w))
    {
        if (!visited[w])
        {
            dfs(G, w, visited);
        }
    }
}

/* dfs for all nodes of the graph */
void dfs_traverse(graph G)
{
    bool *visited = (bool *)malloc(G->nV * sizeof(bool));

    for (int i = 0; i < G->nV; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < G->nV; i++)
    {
        if (!visited[i])
        {
            /* dfs for " i " vertex */
            dfs(G, i, visited);
        }
    }
}

int main()
{
    cin.get();
}

/* graph api */
void init_graph(graph G, Vertex V)
{
    assert(V > 0);

    G = (GraphRep *)malloc(sizeof(GraphRep));
    assert(G != NULL);
    G->nV = V;
    G->nE = 0;

    G->edges = (int **)malloc(V * sizeof(int *));
    assert(G->edges != NULL);

    for (int i = 0; i < G->nV; i++)
    {
        G->edges[i] = (int *)calloc(V, sizeof(int));
        assert(G->edges[i]);
    }

    G->is_vertex_exist = (bool *)malloc(V * sizeof(bool));
    for (int i = 0; i < G->nV; i++)
    {
        G->is_vertex_exist[i] = true;
    }
}

bool valid_vertex(graph G, Vertex v) { return (G != NULL && v > 0 && G->is_vertex_exist[v] == true); }

bool Adjacent(graph G, Vertex v, Vertex w)
{
    assert(G != NULL && valid_vertex(G, v) && valid_vertex(G, w));

    return (G->edges[v][w] != 0);
}

int first_neighbor(graph G, Vertex v)
{
    assert(G != NULL && valid_vertex(G, v));

    for (int i = 0; i < G->nV; i++)
    {
        if (G->edges[v][i]) return i;
    }

    return -1;
}

int next_neighbor(graph G, Vertex v, Vertex w)
{
    assert(G != NULL && valid_vertex(G, v) && valid_vertex(G, w) && Adjacent(G, v, w));

    for (int i = w; i < G->nV; i++)
    {
        if (G->edges[v][i]) return i;
    }

    return -1;
}