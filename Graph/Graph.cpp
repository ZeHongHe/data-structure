/* Graph implement using adjacency Matrix */

#include "graph.h"
#define NDEBUG
#include <iostream>
#include <cassert>

#define Vertex int

using namespace std;

struct GraphRep
{
    int **edges;
    int nV;
    int nE;
    bool *is_vertex_exist;
};

struct Edge
{
    Vertex v;
    Vertex w;
};

void init_graph(graph G, int V)
{
    assert(V > 0);

    G = (GraphRep *)malloc(sizeof(GraphRep));
    assert(G != NULL);
    G->nV = V;
    G->nE = 0;

    G->edges = (int **)malloc(V * sizeof(int *));
    assert(G->edges != NULL);

    int i;
    for (int i = 0; i < G->nV; i++)
    {
        G->edges[i] = (int *)calloc(V, sizeof(int));
        assert(G.edges[i] != NULL);
    }

    G->is_vertex_exist = (bool *)malloc(V * sizeof(bool));
    for (int i = 0; i < G->nV; i++)
    {
        G->is_vertex_exist[i] = true;
    }
}

bool valid_vertex(graph G, Vertex v) { return (G != NULL && v > 0 && G->is_vertex_exist[v] == true;); }

bool Adjacent(graph G, Vertex v, Vertex w)
{
    assert(G != NULL && valid_vertex(G, v) && valid_vertex(G, w));

    return (G->edges[v][w] != 0);
}

int *Neighbors(graph G, Vertex v)
{
    int *neighbor_edges = (int *)calloc(G->nV, sizeof(int));

    assert(neighbor_edges != NULL);

    for (int i = 0; i < G->nV; i++)
    {
        if (G->edges[v][i] != 0) neighbor_edges[i] = 1;
    }

    return neighbor_edges;
}

void insert_vertex(graph G, Vertex v)
{
    graph new_G;
    init_graph(new_G, G->nV + 1);

    for (int i = 0; i < G->nV; i++)
    {
        for (int j = 0; j < G->nV; j++)
        {
            new_G->edges[i][j] = G->edges[i][j];
        }
    }
}

void delete_vertex(graph G, Vertex v)
{
    for (int i = 0; i < G->nV; i++)
    {
        G->edges[v][i] = 0;
        G->edges[i][v] = 0;
    }

    G->is_vertex_exist[v] = false;
}

void insert_edge(graph G, edge e)
{
    assert(G != NULL && valid_vertex(G, e.v) && valid_vertex(G, e.w));

    if (!G->edges[e.v][e.w])
    {
        G->edges[e.v][e.w] = 1;
        G->edges[e.w][e.v] = 1;
        G->nE++;
    }
}
void delete_edge(graph G, edge e)
{
    assert(G != NULL && valid_vertex(G, e.v) && valid_vertex(G, e.w));
    
    if (G->edges[e.v][e.w])
    {
        G->edges[e.v][e.w] = 0;
        G->edges[e.w][e.v] = 0;
        G->nE--;
    }
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

int main()
{
    cin.get();
}