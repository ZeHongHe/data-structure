#include <iostream>
#include <cassert>
#define NDEBUG
using namespace std;

struct Node
{
    int val;
    struct Node *par;
    struct Node *left;
    struct Node *right;

    /* 1 -> red, 0 -> black */
    int color;
};

typedef struct Node node;

node *create_node(int val, node *par)
{
    node *new_node = (node *)malloc(sizeof(node));

    assert(new_node != NULL);

    new_node->val = val;
    new_node->par = par;
    new_node->left = NULL;
    new_node->right = NULL;

    new_node->color = 1;
}

node *right_rotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    y->left = T2;
    x->right = y;

    return x;
}

node *left_rotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    x->right = T2;
    y->left = x;

    return y;
}

node *left_right_rotate(node *z);

node *right_left_rotate(node *z);

node *insert_node(node *root, int key);

node *delete_node(node *root, int querykey);

int main()
{
    cin.get();
}
