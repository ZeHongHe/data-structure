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

    /* if color equals 1 means red. */
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

node *right_rotate(node *y);

node *left_rotate(node *x);

node *left_right_rotate(node *z);

node *right_left_rotate(node *z);

node *insert_node(node *root, int key);

node *delete_node(node *root, int querykey);

int main()
{
    cin.get();
}
