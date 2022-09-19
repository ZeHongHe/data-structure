/* queue(with head node) ADT implementation */
#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

struct node 
{
    int data;
    struct node *next;
};

struct Queue
{
    node *head;
    node *tail;
};

typedef struct node node;
typedef struct Queue *queue;

void init_queue(queue Q)
{
    Q->head = Q->tail = (node *)malloc(sizeof(node));

    Q->head->next = NULL;
}

bool is_empty(queue Q) { return (Q->head == Q->tail); }

void en_queue(queue Q, int e)
{
    node *new_node = (node *)malloc(sizeof(node));

    assert(new_node != NULL);

    new_node->data = e;
    new_node->next = NULL;

    Q->tail->next = new_node;
    Q->tail = new_node;
}

void de_queue(queue Q, int &e)
{   
    assert(Q->head != Q->tail);

    node *delete_node = Q->head->next;

    e = delete_node->data;
    Q->head->next = delete_node->next;

    if (Q->tail == delete_node) Q->tail = Q->head;

    free(delete_node);
}

int main()
{
    cin.get();
}