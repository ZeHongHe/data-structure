/* Adjacency Matrix Representation */

#include "graph.h"
#include "queue.h"
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

/* queue */
struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    node *head;
    node *tail;
};


void visit(graph G, int v)
{
    printf("%d", v);
}

/* v is start vertex on a bfs process */
void bfs(graph G, int v, queue Q, bool *visited)
{
    visit(G, v);
    visited[v] = true;

    en_queue(Q, v);

    while(!isEmpty(Q))
    {
        /* visited vertex will be removed from queue */
        de_queue(Q);

        for (int w = first_neighbor(G, v); w >= 0; w = next_neighbor(G, v, w))
        {
            if (!visited[w])
            {
                visit(G, w);
                visited[w] = true;
                en_queue(Q, w);
            }
        }
    }
}

void bfs_traverse(graph G)
{
    /* Marks vertices that have been visited */
    bool *visited = (bool *)malloc(G->nV * sizeof(bool));

    for (int i = 0; i < G->nV; i++)
    {
        visited[i] = false;
    }
    
    queue Q;
    init_queue(Q);

    for (int i = 0; i < G->nV; i++)
    {
        if (!visited[i]) bfs(G, i, Q, visited);
    }
}

int main()
{
    cin.get();
}

/* graph */
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

/* queue */
void init_queue(queue Q)
{
    Q = (queue)malloc(sizeof(queue));
    assert(Q != NULL);

    Q->head = NULL;
    Q->tail = NULL;
}

void en_queue(queue Q, int e)
{
    node *new_node = (node *)malloc(sizeof(node));
    assert(new_node != NULL);

    new_node->data = e;
    if (Q->head == NULL)
    {
        Q->head = new_node;
        Q->tail = new_node;
    }
    else
    {
        Q->tail->next = new_node;
        Q->tail = new_node;
    }
}

int de_queue(queue Q)
{
    assert(isEmpty(Q));

    node *delete_node = Q->head;

    int e = delete_node->data;

    if (Q->tail == delete_node)
    {
        Q->head = NULL;
        Q->tail = NULL;
    }
    else
    {
        Q->head = delete_node->next;
    }

    free(delete_node);

    return e;
}

bool isEmpty(queue Q) { return (Q->head == NULL); }