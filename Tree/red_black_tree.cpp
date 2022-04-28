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

rb_node *right_rotate(rb_node *node, rb_node *root)
{
    struct rb_node *left = node->left;

    if ((node->left = left->right))
    {
        left->right->par = node;
    }

    left->right = node;

    if ((left->par = node->par))
    {
        if (node == node->par->left)
        {
            node->par->left = left;
        }
        else
        {
            node->par->right = left;
        }
    }
    else
    {
        root = left;
    }

    node->par = left;

    return node;
}

rb_node *left_rotate(rb_node *node, rb_node *root)
{
    struct rb_node *right = node->right;

    if ((node->right = right->left))
    {
        right->left->par = node;
    }

    right->left = node;

    if ((right->par = node->par))
    {
        if (node == node->par->left)
        {
            node->par->left = right;
        }
        else
        {
            node->par->right = right;
        }
    }
    else
    {
        root = right;
    }

    node->par = right;

    return node;
    
}

rb_node *insert_node(rb_node *root, int key);

rb_node *delete_node(rb_node *root, int querykey);

int main()
{
    cin.get();
}
