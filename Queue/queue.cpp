/* queue ADT implementation */
#include <iostream>
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
    Q = (queue)malloc(sizeof(Queue));

    Q->head = NULL;
    Q->tail = NULL;
}

bool isEmpty(queue Q) { return (Q->head == NULL);}

void en_queue(queue Q, int e)
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = e;
    new_node->next = NULL;

    if (isEmpty(Q))
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

void de_queue(queue Q, int &e)
{
    if (isEmpty(Q)) printf("Queue is empty!");

    node *delete_node = Q->head;
    e = delete_node->data;

    if (Q->tail == delete_node)
    {
        Q->head = NULL;
        Q->tail =NULL;
    }
    else
    {
        Q->head = delete_node->next;
    }

    free(delete_node);
}

int main() 
{
    cin.get();
}