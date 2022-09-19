/* stack implementation using linklist */

#include <iostream>
#include <cassert>
#define NDEBUG

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
        assert(S != NULL);

        S->data = e;
        S->next = NULL;
    }
    else
    {
        node *new_node = (node *)malloc(sizeof(node));
        assert(new_node != NULL);

        new_node->data = e;
        new_node->next = S;
        S = new_node;
    }
}

void pop(stack S, int e)
{
    if (!isEmpty(S))
    {
        node *delete_node = S;

        e = delete_node->data;
        
        S = delete_node->next;

        free(delete_node);
    }
}

int main()
{
    cin.get();
}