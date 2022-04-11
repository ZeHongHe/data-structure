/* Graph implement using adjacency list */

#include "graph.h"
#define NDEBUG
#include <iostream>
#include <cassert>

#define Vertex int

using namespace std;

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

void init_graph(graph G, Vertex V)
{
    assert(V > 0);

    G = (GraphRep *)malloc(sizeof(GraphRep));
    assert(G != NULL);

    G->nodes = (node *)malloc(V * sizeof(node));
    assert(G->nodes != NULL);
    G->nV = V;
    G->nE = 0;

    G->is_vertex_exist = (bool *)malloc(G->nV * sizeof(bool));
    for (int i = 0; i < G->nV; i++)
    {
        G->is_vertex_exist[i] = true;
    }
}

bool valid_vertex(graph G, Vertex v)
{
    assert(G != NULL && v > 0 && G->is_vertex_exist[v] == true);
}

bool Adjacent(graph G, Vertex v, Vertex w)
{
    assert(G != NULL && valid_vertex(G, v) && valid_vertex(G, w));
    
    for (edge *now_vertex = G->nodes[v].first; now_vertex != NULL; now_vertex = now_vertex->next)
    {
        if (now_vertex->w == w) return true;
    }

    for (edge *now_vertex = G->nodes[w].first; now_vertex != NULL; now_vertex = now_vertex->next)
    {
        if (now_vertex->w == v) return true;
    }

    return false;
}

int *Neighbors(graph G, Vertex v)
{   
    int *neighbors_edges = (int *)calloc(G->nV, sizeof(int));

    assert(neighbors_edges != NULL);

    for (int i = 0; i < G.nv; i++)
    {
        for (edge *now_vertex = G->nodes[i].first; now_vertex != NULL; now_vertex = now_vertex->next)
        {   
            if (i == v)
            {
                neighbors_edges[now_vertex->w] = 1;
            }
            else
            {
                if (now_vertex->w == v) neighbors_edges[now_vertex->w] = 1;
            }
            
        }
    }

    return neighbors_edges;
}

void insert_vertex(graph, Vertex)
{
    
}

void delete_vertex(graph, Vertex);

void insert_edge(graph, edge);
void delete_edge(graph, edge);

int first_neighbor(graph, Vertex);
int next_neighbor(graph, Vertex, Vertex);

int main() 
{
    cin.get();
}