#include <iostream>
#include <cassert>

#define NDEBUG

using namespace std;

struct Node
{
    int data;
    struct Node *prior, *next;
};

typedef struct Node node;
typedef struct Node *DLinkList;

bool init_list(DLinkList &L)
{
    L = (node *)malloc(sizeof(node));
    assert(L != NULL);

    L->prior = NULL;
    L->next = NULL;

    return true;
}

bool node_insert(node *p, node *s)
{
    assert(p != NULL || s != NULL);

    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

bool node_prior_insert(node *p,node *s)
{
    assert(p != NULL || s != NULL);

    s->next = p;
    if (p->prior) p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;

    return true;
}

bool delete_node(node *p)
{
    assert(p != NULL);

    node *s = p->next;
    if (!s) return false;

    p->next = s->next;
    if (p->next) p->next->prior = p;

    free(s);

    return true;
}

void destroyList(DLinkList &L)
{
    while (L->next)
    {
        delete_node(L->next);
    }

    free(L);
    L = NULL;
}

bool isEmpty(DLinkList L) { return (!L->next); }

int length(DLinkList L)
{
    int len = 0;
    node *p = L;

    while (p)
    {
        p = p->next;
        len++;
    }

    return len;
}

void printList(DLinkList &L)
{
    int len = 0;
    node *p = L;

    while(p)
    {
        printf("The %d node's data is %d \n", len, p->data);
        p = p->next;
        len++;
    }
}

int main()
{
    cin.get();
}