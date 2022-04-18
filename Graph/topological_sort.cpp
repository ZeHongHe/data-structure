/* Topological Sort Implementation */
/* using graph with adjacency list */

#include <iostream>
#include <cassert>`
#include "graph.h"
#include "stack.h"
#define NDEBUG

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
{
    indegree = (int *)calloc(G->nV, sizeof(int));
    assert(indegree != NULL);

    int i = 0;
    for (node *temp = G->nodes[i].first; i < G->nV; i++)
    {
        while (temp != NULL)
        {
            temp = temp->next;
            indegree[i]++;
        }
    }
}

int *topological_sort(graph G)
{
    /*----------------init-------------------*/
    /* use a array "indegree" to recording the indegree of vertices in every loop */
    int *indegree;
    find_indegree(G, indegree);

    /* use a stack to storing all vertices with zero indegree */
    stack S;
    init_stack(S);

    /* use a array "print" to recording the topological sequence */
    int *print = (int *)malloc(G->nV * sizeof(int));
    for (int i = 0; i < G->nV; i++)
    {
        print[i] = -1;
    }

    /*----------------sort-------------------*/
    for (int i = 0; i < G->nV; i++)
    {
        /* if one vertex's indegree is zero, push it into stack for first loop. */
        if (!indegree[i])
        {
            push(S, i);
        }
    }

    /* marked vertexses have been print */
    int count = 0;

    while (!isEmpty(S))
    {
        int i;
        pop(S, i);
        print[count++] = i;

        for (int p = first_neighbor(G, i); p; p = next_neighbor(G, i, p))
        {
            /* if k's indegree turns zero, push it into stack.
             * (then it become the first on next loop)
             */
            if (!(--indegree[p]))
            {
                push(S, p);
            }
        }
    }

    /* if count not equal to the numbers of vertexes,
     * which means this graph is an directed graph with loop.
     * So topological sort failed.
     */
    assert(count == G->nV);

    return print;
}

int main()
{
    cin.get();
}

/*----------------graph api-------------------*/
void init_graph(graph G, Vertex V)
{
    assert(V > 0);

    G = (GraphRep *)malloc(sizeof(GraphRep));
    assert(G != NULL);

    G->nodes = (node *)malloc(V * sizeof(node));
    assert(G->nodes != NULL);

    int i = 0;
    node now_node = G->nodes[i];
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
        if (temp->w == w && temp->next != NULL) return temp->next->w;
        temp = temp->next;
    }

    return -1;
}

bool valid_vertex(graph G, Vertex v)
{
    return (G != NULL && v > 0 && G->is_vertex_exist[v] == true);
}

/*----------------stack api-------------------*/
void init_stack(stack S) { S = NULL; }

bool isEmpty(stack S) { return (S == NULL); }

void push(stack S, int e)
{
    if (isEmpty(S))
    {
        S = (node *)malloc(sizeof(node));
        assert(S != NULL);

        S->data = e;
        S->next = NULL;
    }
    else
    {
        node *new_node = (node *)malloc(sizeof(node));
        assert(new_node != NULL);

        new_node->data = e;
        new_node->next = NULL;

        S->next = new_node;
    }
}

void pop(stack S, int e)
{
    assert(!isEmpty(S));

    node *delete_node = S->next;

    e = delete_node->data;
    S->next = delete_node->next;

    free(delete_node);
}