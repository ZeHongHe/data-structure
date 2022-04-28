#include <iostream>
#include <cassert>
#define NDEBUG
using namespace std;

struct rb_node
{
    int val;
    struct rb_node *par;
    struct rb_node *left;
    struct rb_node *right;

    /* 1 -> red, 0 -> black */
    int color;
};

rb_node *create_node(int val, rb_node *par)
{
    rb_node *node = (rb_node *)malloc(sizeof(rb_node));
    assert(node != NULL);
    
    node->val = val;
    node->par = par;
    node->left = NULL;
    node->right = NULL;
    node->color = 1;

    return node;
}

rb_node *right_rotate(rb_node *y)
{
    rb_node *x = y->left;
    rb_node *T2 = x->right;

    y->left = T2;
    x->right = y;

    return x;
}

rb_node *left_rotate(rb_node *x)
{
    rb_node *y = x->right;
    rb_node *T2 = y->left;

    x->right = T2;
    y->left = x;

    return y;
}

rb_node *insert_node(rb_node *root, int key);

rb_node *delete_node(rb_node *root, int querykey);

int main()
{
    cin.get();
}
