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

int *dist;

int *path;

int find_min_dist(graph G, bool *vset, int *dist)
{
    int min_val = INT_MAX;
    int min_vertex = -1;

    for (int i = 0; i < G->nV; i++)
    {
        if (vset[i] == false && dist[i] < min_val)
        {
            min_val = dist[i];
            min_vertex = i;
        }
    }

    return min_vertex;
}

void dijkstra(graph G, int v)
{
    bool *vset = (bool *)malloc(G->nV * sizeof(bool));

    dist = (int *)malloc(G->nV * sizeof(int));

    path = (int *)malloc(G->nV * sizeof(int));

    for (int i = 0; i < G->nV; i++)
    {
        dist[i] = INT_MAX;
        vset[i] = false;
    }

    dist[v] = 0;

    for (int i = 0; i < G->nV; i++)
    {
        int w = find_min_dist(G, vset, dist);

        vset[w] = true;

        for (int i = 0; i < G->nV; i++)
        {
            if (!vset[i] && G->edges[w][i] != INT_MAX 
                && dist[w] + G->edges[w][i] < dist[i])
            {
                dist[i] = dist[w] + G->edges[w][i];
            }
        }
    }
}

int main()
{
    cin.get();
}
