/* stack implementation using linklist */

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
typedef struct node *stack;

void init_stack(stack S) { S = NULL; }

bool isEmpty(stack S) { return (S == NULL); }

void destroy_stack(stack S)
{
    while(!isEmpty(S))
    {
        node *delete_node = S;
        
        S = delete_node->next;

        free(delete_node);
    }
}

void push(stack S, int e)
{
    if (isEmpty(S))
    {
        S = (node *)malloc(sizeof(node));

        if (S == NULL) printf("Out of space!");

        S->data = e;
        S->next = NULL;
    }
    else
    {
        node *new_node = (node *)malloc(sizeof(node));

        if (new_node == NULL) printf("Out of space!");

        new_node->data = e;
        new_node->next = s->next;

        S->next = new_node;
    }
}

void pop(stack S, int e)
{
    if (isEmpty(S)) printf("stack is empty!");

    node *delete_node = S->next;

    e = delete_node->data;
    S->next = delete_node->next;

    free(delete_node);
}

int main()
{
    cin.get();
}