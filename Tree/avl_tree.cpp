#include <iostream>
#include <cassert>

#define NDEBUG
#define ElemType int

using namespace std;

struct AVLNode
{
    int key;
    struct AVLNode *left, *right;
    int height;
};

typedef struct AVLNode avlNode;
typedef struct AVLNode *avlTree;

avlNode *create_node(int key)
{
    avlNode *node = (avlNode *)malloc(sizeof(avlNode));
    assert(node != NULL);

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;

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

/* find the min key in the sequence traversal */
avlNode *in_order_min(avlNode *node)
{
    if (node != NULL)
    {
        while(node->left != NULL)
            in_order_min(node->left);
    }
    return node;
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
 * 1) Perform standard BST insert for w. (w is the newly inserted node.)
 * 2) Starting from w, travel up and find the first unbalanced node.
 * 3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z.
 */
avlNode *insert_node(avlNode *node, int key)
{
    /* 1) standard BST insert */
    if (node == NULL)
        return create_node(key);

    if (key == node->key)
        return node;

    else if (key < node->key)
        node->left = insert_node(node->left, key);

    else if (key > node->key)
        node->right = insert_node(node->right, key);
    

    /* 2) find the first unbalanced node */
    node->height = max(node_height(node->left), node_height(node->right)) + 1;

    avlNode *unbalanced_node = node;

    while ( 
            (height_diff(unbalanced_node) < -1 
            || height_diff(unbalanced_node) > 1)
            && 
            (height_diff(unbalanced_node->left) < -1
            || height_diff(unbalanced_node->left) > 1
            || height_diff(unbalanced_node->right) < -1
            || height_diff(unbalanced_node->right) > 1)
        )
    {
        if (unbalanced_node > 0)
            unbalanced_node = unbalanced_node->left;
        else if (unbalanced_node < 0)
            unbalanced_node = unbalanced_node->right;
        else 
            break;
    }


    /* 3) Re-balance the tree by rotations */
    int unbalance_number = height_diff(unbalanced_node);

    /* LL Rotation */
    if (unbalance_number > 1 && key < (unbalanced_node->left->key))
        unbalanced_node =  right_rotate(unbalanced_node);
    
    /* RR Rotation */
    if (unbalance_number < 1 && key > (unbalanced_node->left->key))
        unbalanced_node =  left_rotate(unbalanced_node);
    
    /* LR Rotation */
    if (unbalance_number > 1 && key > (unbalanced_node->left->key))
        unbalanced_node =  left_right_rotate(unbalanced_node);

    /* RL Rotation */
    if (unbalance_number < 1 && key < (unbalanced_node->left->key))
        unbalanced_node =  right_left_rotate(unbalanced_node);

    return unbalanced_node;
}


/*
 * Steps to follow for delete:
 * 1) Perform standard BST delete for w. (w is the node to be deleted.)
 * 2) Starting from w, travel up and find the first unbalanced node.
 * 3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z.
 */
avlNode *delete_node(avlNode *node, int querykey)
{
    /* 1) standard BST delete */
    if (node == NULL)
        return node;
    
    if (querykey < node->key)
        node = delete_node(node->left, querykey);

    else if (querykey > node->key)
        node = delete_node(node->right, querykey);
    
    else 
    {
        /* no child or single child */
        if ((node->left == NULL) || (node->right == NULL))
        {
            avlNode *temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                temp = node;
                node = NULL;
            }
            else
            {
                *node = *temp;
            }

            free(temp);
        }
        /* two child */
        else
        {
            avlNode *temp = in_order_min(node->right);

            node->key = temp->key;
            *temp = *(temp->right);

            free(temp->right);
        }
    }

    /*single node in tree*/
    if (node == NULL)
        return node;


    /* 2) Starting from w, travel up and find the first unbalanced node */
    node->height = max(node_height(node->left), node_height(node->right)) + 1;

    avlNode *unbalanced_node = node;

    while ( 
            (height_diff(unbalanced_node) < -1 
            || height_diff(unbalanced_node) > 1)
            && 
            (height_diff(unbalanced_node->left) < -1
            || height_diff(unbalanced_node->left) > 1
            || height_diff(unbalanced_node->right) < -1
            || height_diff(unbalanced_node->right) > 1)
        )
    {
        if (unbalanced_node > 0)
            unbalanced_node = unbalanced_node->left;
        else if (unbalanced_node < 0)
            unbalanced_node = unbalanced_node->right;
        else 
            break;
    }


    /* 3) Re-balance the tree by rotations */
    int unbalance_number = height_diff(unbalanced_node);

    /* LL Rotation */
    if (unbalance_number > 1 && querykey < (unbalanced_node->left->key))
        unbalanced_node =  right_rotate(unbalanced_node);
    
    /* RR Rotation */
    if (unbalance_number < 1 && querykey > (unbalanced_node->left->key))
        unbalanced_node =  left_rotate(unbalanced_node);
    
    /* LR Rotation */
    if (unbalance_number > 1 && querykey > (unbalanced_node->left->key))
        unbalanced_node =  left_right_rotate(unbalanced_node);

    /* RL Rotation */
    if (unbalance_number < 1 && querykey < (unbalanced_node->left->key))
        unbalanced_node =  right_left_rotate(unbalanced_node);

    return unbalanced_node;
}

avlNode *find_node(avlNode *node, int querykey)
{
    if (node != NULL)
    {
        if (querykey < node->key)
            node = find_node(node->left, querykey);
        else if (querykey > node->key)
            node = find_node(node->right, querykey);
    }

    return node;
}

int main()
{
    cin.get();
}