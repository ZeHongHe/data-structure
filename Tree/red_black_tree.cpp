#include <iostream>

#define RB_RED   1
#define RB_BLACK 0

using namespace std;

struct rb_node
{
    int val;
    struct rb_node *par;
    struct rb_node *left;
    struct rb_node *right;
    int color;
};

rb_node *create_node(int val, rb_node *par)
{
    rb_node *node = (rb_node *)malloc(sizeof(rb_node));
    
    node->val = val;
    node->par = par;
    node->left = NULL;
    node->right = NULL;
    node->color = RB_RED;

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

rb_node *insert_node(int val, rb_node *root)
{
    rb_node *buffer = root;

    while (buffer)
    {
        if (val < buffer->val)
        {
            if (buffer->left)
            {
                buffer = buffer->left;
            }
            else
            {
                rb_node *temp = create_node(val, buffer);
                buffer->left = temp;
                buffer = temp;

                break;
            }
        }
        else
        {
            if (buffer->right)
            {
                buffer = buffer->right;
            }
            else
            {
                rb_node *temp = create_node(val, buffer);
                buffer->right = temp;
                buffer = temp;

                break;
            }
        }
    }
}

rb_node *delete_node(rb_node *root, int querykey);

int main()
{
    cin.get();
}
