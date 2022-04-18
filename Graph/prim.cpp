#include <iostream>
#include <climits>
#include <cassert>
#include "graph.h"
#define NDEBUG

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
    int v;
    int w;
};

int find_min_dist(graph G, bool *is_join, int *low_cost)
{
    int min_vertex;
    int min_dist = INT_MAX;

    for (int i = 0; i < G->nV; i++)
    {
        if (is_join[i] == false && low_cost[i] != 0 && low_cost[i] < min_dist)
        {
            min_dist = low_cost[i];
            min_vertex = i;
        }
    }

    return min_vertex;
}

void update_low_cost(graph G, int v, bool *is_join, int *low_cost)
{
    for (int i = 0; i < G->nV; i++)
    {
        /* if w is an adjacent vertex of v and w is't in the minimum spanning tree */
        if (is_join[i] == false && low_cost[i] != 0 && G->edges[v][i] < INT_MAX ) 
        {
            if ( G->edges[v][i] < low_cost[i]) 
            {
                low_cost[i] = G->edges[v][i];
            }
        }
    }
}

void prim(graph G, int v)
{
    /*----------------init-------------------*/
    // is_join: marks whether each node has been added to the minimum spanning tree
    bool *is_join = (bool *)calloc(G->nV, sizeof(bool));
    assert(is_join != NULL);

    is_join[v] = true;

    // low_cost: minimum cost for each node to join in the tree
    int *low_cost = (int *)malloc(G->nV * sizeof(int));
    assert(low_cost != NULL);

    // Assume no edge on graph, the minimum cost to join is infinity.
    for (int i = 0; i < G->nV; i++)
    {
        if (G->edges[v][i])
        {
            low_cost[i] = G->edges[v][w];
        }
        else
        {
            low_cost[i] = INT_MAX;
        }
    }
    /*----------------execute-------------------*/
    int flag = 0;

    while (flag < G->nV - 1)
    {
        int min_vertex = find_min_dist(G, is_join, low_cost);

        is_joinp[min_vertex] = true;

        update_low_cost(G, min_vertex, is_join, low_cost);

        flag++;
    }
}

int main()
{
    cin.get();
}

/*----------------graph api-------------------*/
void init_graph(graph G, int V)
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
        assert(G->edges[i] != NULL);
    }

    G->is_vertex_exist = (bool *)malloc(V * sizeof(bool));
    for (int i = 0; i < G->nV; i++)
    {
        G->is_vertex_exist[i] = true;
    }
}

bool valid_vertex(graph G, Vertex v) { return (G != NULL && v > 0 && G->is_vertex_exist[v] == true); }

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