#include <iostream>
#define ElemType int
using namespace std;

struct AVLNode
{
    int key;
    struct AVLNode *left, *right;
    int height;
};

typedef struct AVLNode avlNode;

avlNode *create_node(int key)
{
    avlNode *node = (avlNode *)malloc(sizeof(avlNode));

    if (node == NULL)
        printf("Out of memory!")
    else 
    {
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }

    return node;
}

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int node_height(avlNode *node)
{
    if (node == NULL)
        return 0;
    else 
        return node->height;
}

int height_diff(avlNode *node)
{
    if (node == NULL)
        return 0;
    else
        return (node_height(node->left) - node_height(node->right));
    
}

/* LL & RR balance rotation:
 *    1) T1, T2 and T3 are subtrees of the tree rooted with y (on the left side) or x (on the right side)  

 *        y                                   x
 *       /           Right Rotation          /  
 *      x   T3       - - - - - - - >        T1   y 
 *     /            < - - - - - - -            / 
 *    T1  T2         Left Rotation            T2  T3
 * 
 *   2) Keys in both of the above trees follow the following order:
 *     keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
 */
avlNode *right_rotate(avlNode *y)
{
    avlNode *x = y->left;
    avlNode *T2 = x->right;

    y->left = T2;
    x->right = y;

    y->height = max(node_height(y->left), node_height(y->right)) + 1;
    x->height = max(node_height(x->left), node_height(x->right)) + 1;

    return x;
}

// RR balance rotation
avlNode *left_rotate(avlNode *x)
{
    avlNode *y = x->right;
    avlNode *T2 = y->left;

    x->right = T2;
    y->left = x;

    x->height = max(node_height(x->left), node_height(x->right)) + 1;
    y->height = max(node_height(y->left), node_height(y->right)) + 1;

    return y;
}

/* LR balance rotation:
 *        z                              z                              x
 *       /                             /                              /   
 *     y   T4    Left Rotate (y)     x    T4    Right Rotate(z)       y      z
 *   /         - - - - - - - - ->  /           - - - - - - - ->     /      / 
 *  T1   x                        y    T3                         T1 T2   T3 T4
 *      /                       / 
 *    T2   T3                  T1   T2
 */
avlNode *left_right_rotate(avlNode *z)
{
    avlNode *y = z->left;

    z->left = left_rotate(y);

    return right_rotate(z);
}

/* RL balance rotation:
 *     z                                z                               x
 *    /                               /                               /   
 *  T1   y       Right Rotate (y)    T1   x      Left Rotate(z)      z      y
 *      /       - - - - - - - - ->      /       - - - - - - - ->    /      / 
 *     x   T4                          T2   y                     T1  T2  T3  T4
 *    /                                    /  
 *  T2   T3                               T3   T4
 *
 */
avlNode *right_left_rotate(avlNode *z)
{
    avlNode *y = z->right;

    z->right = right_rotate(y);

    return left_rotate(z);
}

/*
 * Steps to follow for insertion:
 * 1) Perform standard BST insert for w.
 * 2) Starting from w, travel up and find the first unbalanced node.
 * 3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z.
 */
avlNode *insert_node(avlNode *node, int key)
{
    if (node == NULL)
        return create_node(key);

    /* 1) standard BST insert */
    if (key == node->key)
        return node;

    else if (key < node->key)
        node->left = insert_node(node->left, key);

    else if (key > node->key)
        node->right = insert_node(node->right, key);
    

}

int main()
{
    AVLTree T;

    cin.get();
}