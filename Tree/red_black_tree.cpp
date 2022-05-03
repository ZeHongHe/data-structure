#include <iostream>

#define	RB_RED		0
#define	RB_BLACK	1

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

rb_node *right_rotate(rb_node *node)
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

    node->par = left;

    return node;
}

rb_node *left_rotate(rb_node *node)
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

    node->par = right;

    return node;
    
}

void check_color(rb_node *node)
{
    /* 1. if node is root,
        RB property is intact */
    if (node->par == NULL)
    {
        // node->color = RB_BLACK;
        return;
    }

    /* 2. if node or it's parent is black node,
        RB property is intact */
    if (node->color == RB_BLACK || node->par->color == RB_BLACK)
    {
        return;
    }

    /* 3. if node and its parent are red nodes,
        check for uncle */
    rb_node *parent = node->par;
    rb_node *grand_parent = parent->par;

    if (grand_parent)
    {
        parent->color = RB_BLACK;
    }

    if (grand_parent->left && grand_parent->left->color == RB_RED &&
        grand_parent->right && grand_parent->right->color == RB_RED)
    {
        grand_parent->color = RB_RED;
        grand_parent->left->color = grand_parent->right->color = RB_BLACK;
        return;
    }
    else
    {
        rb_node *great_grand_parent = grand_parent->par;

        /* right case */
        if (grand_parent->left = parent)
        {
            /* right right case */
            if (parent->left = node)
            { 
                left_rotate(grand_parent);

                parent->color = RB_BLACK;
                grand_parent->color = RB_RED;
            }

            /* right left case */
            else
            {
                right_rotate(grand_parent);

                left_rotate(great_grand_parent);

                node->color = RB_BLACK;
                grand_parent = RB_RED;
            }
        }
        /* left case */
        else
        {
            /* left left case */
            if (parent->right = node)
            {
                right_rotate(grand_parent);

                parent->color = RB_BLACK;
                grand_parent->color = RB_RED;
            }

            /* left right case */
            else
            {
                left_rotate(grand_parent);

                right_rotate(great_grand_parent);

                node->color = RB_BLACK;
                grand_parent = RB_RED;
            }
        }
    }
}

void insert_node(int val, rb_node *root)
{
    rb_node *buffer_node = root;

    while (buffer_node)
    {
        if (val < buffer_node->val)
        {
            if (buffer_node->left)
            {
                buffer_node = buffer_node->left;
            }
            else
            {
                rb_node *temp = create_node(val, buffer_node);
                buffer_node->left = temp;
                buffer_node = temp;

                break;
            }
        }
        else
        {
            if (buffer_node->right)
            {
                buffer_node = buffer_node->right;
            }
            else
            {
                rb_node *temp = create_node(val, buffer_node);
                buffer_node->right = temp;
                buffer_node = temp;

                break;
            }
        }
    }

    while (buffer_node != root)
    {
        /* adjusted it's RB property */
        check_color(buffer_node);

        /* if buffer_node is root after adjusted */
        if (buffer_node->par == NULL)
        {
            root = buffer_node;
            break;
        }

        /* if buffer_node isn't root */
        buffer_node = buffer_node->par;

        if (buffer_node == root)
        {
            buffer_node->color = RB_BLACK;
        }
    }
}

rb_node *delete_node(rb_node *root, int querykey);

int main()
{
    cin.get();
}
