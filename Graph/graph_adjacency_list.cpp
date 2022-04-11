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

    int i = 0;
    node *now_node = G->nodes[i];
    while (i < G->nV)
    {
        G->nodes[i].v = i;
        now_node = G->nodes[++i];
    }

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
    return (G != NULL && v > 0 && G->is_vertex_exist[v] == true);
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

    for (int i = 0; i < G->nV; i++)
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

void insert_vertex(graph G, Vertex v)
{
    assert(G != NULL && v >= 0 && v <= G->nV);

    if (v < G->nV || G->is_vertex_exist[v] == false)
    {
        G->is_vertex_exist[v] = true;
    }
    else
    {
        G->nodes = (node *)realloc(G->nodes, G->nV + 1);
        assert(G->nodes != NULL);

        G->nodes[v].v = v;
        G->nodes[v].first = NULL;

        G->is_vertex_exist = (bool *)realloc(G->is_vertex_exist, G->nV + 1);
        G->is_vertex_exist[v] = true;
    }

    G->nV++;
}

void delete_vertex(graph G, Vertex v)
{
    assert(G != NULL && valid_vertex(G, v));

    for (edge *now_vertex = G->nodes[v].first; now_vertex != NULL;)
    {
        edge *temp = now_vertex;
        now_vertex = temp->next;
        free(temp);
    }

    G->is_vertex_exist[v] = false;
    G->nV--;
}

void insert_edge(graph G, Vertex v, Vertex w)
{
    assert(G != NULL && valid_vertex(G, v) && valid_vertex(G, v));

    edge *new_edge= (edge *)malloc(sizeof(edge));
    new_edge->w = w;

    edge *temp = G->nodes[v].first;
    while (temp != NULL)
    {
        temp = temp->next; 
    }

    temp->next = new_edge;

    G->nE++;
}

void delete_edge(graph G, Vertex v, Vertex w)
{
    assert(G != NULL && valid_vertex(G, v) && valid_vertex(G, v));

    edge *temp = G->nodes[v].first;
    while (temp != NULL)
    {   
        if (temp->w == w)
        {
            edge *free_edge = temp->next;

            int temp_value = free_edge->w;
            free_edge->w = temp->w;
            temp->w = temp_value;

            temp->next = free_edge->next;

            free(free_edge);
        }

        temp = temp->next;
    }

    G->nE--;
}

int first_neighbor(graph G, Vertex v) 
{ 
    assert(G != NULL && valid_vertex(G, v));

    if (G->nodes[v].first != NULL) return (G->nodes[v].first->w);

    return -1;
}

int next_neighbor(graph G, Vertex v, Vertex w)
{
    assert(G != NULL && valid_vertex(G, v));

    edge *temp = G->nodes[v].first;
    while (temp != NULL)
    {
        if (temp->w = w && temp->next != NULL) return temp->next->w;
        temp = temp->next;
    }

    return -1;
}

int main() 
{
    cin.get();
}