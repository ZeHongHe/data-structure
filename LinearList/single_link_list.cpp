/* single link list without head node */

#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;
typedef struct Node *LinkList;

bool init_list(LinkList &L)
{
    L = (node *)malloc(sizeof(node));
    assert(L != NULL);

    L->next = NULL;

    return true;
};

LinkList list_tail_insert(LinkList &L)
{
    init_list(L);

    node *p, *r = L;

    int e;
    scanf("%d", &e);

    while (e != 9999)
    {
        p = (node *)malloc(sizeof(node));
        assert(p != NULL);

        p->data = e;
        r->next = p;
        r = p; 

        scanf("%d", &e);
    }

    r->next = NULL;
    return L;
}

LinkList list_head_insert(LinkList &L) 
{
    init_list(L);

    node *p;

    int e;
    scanf("%d", &e);

    while ( e != 9999)
    {
        p = (node *)malloc(sizeof(node));
        assert(p != NULL);

        p->data = e;
        p->next = L->next;
        L->next = p;

        scanf("%d", &e);
    }
    return L;
}

node *locate_elem(LinkList &L, int e)
{
    node *p = L->next;

    while (p != NULL && p->data != e)
    {
        p = p->next;
    }

    return p;
}

node *get_elem(LinkList L, int i) {
    if (i < 1) return L;

    node *p;
    int j = 0;    // j 为 p 指向节点的位序
    p = L;        // 令 p 指向第 0 个节点

    while (j < i && p)
    {
        p = p->next;
        j++;
    }

    return p;
}

bool node_insert(node *p, int e)
{
    if (p == NULL) return false;

    node *insert_node = (node *)malloc(sizeof(node));
    assert(insert_node);

    insert_node->data = e;
    insert_node->next = p->next;
    p->next = insert_node;

    return true;
}

bool node_prior_insert(node *p, int e)
{
    if (p == NULL) return false;

    node *insert_node = (node *)malloc(sizeof(node));
    assert(insert_node != NULL);

    insert_node->next = p->next;
    p->next = insert_node;
    insert_node->data = p->data;
    p->data = e;

    return true;
}

// 插入：按指定位序 i 前插
bool list_insert(LinkList &L, int i, int e)
{
    node * p = get_elem(L, i - 1);
    return node_insert(p, e);
}

// 删除：按指定位序 i
bool list_delete(LinkList &L, int i, int &e)
{
    node *p = get_elem(L, i - 1);
    if (!p) return false;

    if (!p->next) return false;

    node *delete_node = p->next;
    e = delete_node->data;
    p->next = delete_node->next;
    
    free(delete_node);

    return true;
}

// 删除：按指定节点 delete_node
bool nodeDelete(node *delete_node)
{
    if (delete_node == NULL) return false;

    node *p = delete_node->next;
    delete_node->data = delete_node->next->data;
    delete_node->next = p->next;

    free(delete_node);

    return true;
}

bool isEmpty(LinkList L) { return (L->next == NULL); }

int length(LinkList L)
{
    node *p = L;
    int len = 0;

    while (p->next)
    {
        p = p->next;
        len++;
    }

    return len;
}

void printList(LinkList L)
{
    int len = 1;
    node *p = L->next;

    while(p)
    {
        printf("The %d node's data is %d \n", len, p->data);
        p= p->next;
        len++;
    }
}

int main()
{
    cin.get();
}