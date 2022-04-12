/* Binary tree implement using link list*/

#include <iostream>
#include <cassert>
#define NDEBUG

#define ElemType int

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

typedef struct Node node;
typedef struct Node *tree;

void init_tree(tree T) 
{
    T = (node *)malloc(sizeof(node));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
}

node *create_node(ElemType data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

bool insert_node(node *T, ElemType e) {
    node *newNode = create_node(e);
    if (T->left == NULL)
    {
        T->left = newNode;
        return true;
    }
    else if (T->right == NULL)
    {
        T->right = newNode;
        return true;
    }
    else
    {
        return false;
    }
}

void visit(node *T) { }

void inorder(tree T)
{
    if (T != NULL)
    {
        inorder(T->left);
        visit(T);
        inorder(T->right);
    }
}

void inorder_no_recursion(tree T) { }

void preorder(tree T)
{
    if (T != NULL)
    {
        visit(T);
        preorder(T->left);
        preorder(T->right);
    }
}

void preorder_no_recursion(tree T) { }

void postorder(tree T)
{
    if (T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        visit(T);
    }
}

void postorder_no_recursion(tree T) { }

void LevelOrder(tree T) { }

int main()
{
    cin.get();
}