#include "queue.h"
#include <iostream>
#include <cassert>
using namespace std;

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

void init_queue(queue Q)
{
    Q->head = Q->tail = (node *)malloc(sizeof(node));

    Q->head->next = NULL;
}

bool isEmpty(queue Q) { return (Q->head == Q->tail); }

void en_queue(queue Q, int e)
{
    node *new_node = (node *)malloc(sizeof(node));
    assert(new_node == NULL);

    new_node->data = e;
    new_node->next = NULL;

    Q->tail->next = new_node;
    Q->tail = new_node;
}

void de_queue(queue Q, int &e)
{   
    assert(!isEmpty(Q));

    node *delete_node = Q->head->next;

    e = delete_node->data;
    Q->head = delete_node->next;

    if (Q->tail == delete_node) Q->tail = Q->head;

    free(delete_node);
}

int main()
{
    cin.get();
}