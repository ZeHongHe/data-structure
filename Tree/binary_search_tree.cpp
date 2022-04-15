#include <iostream>
#define ElemType int
using namespace std;

struct node 
{
    int data;
    struct node *left, *right;
};

typedef struct node node;
typedef struct node *tree;

node *create_node(ElemType data) 
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void init_tree(tree T) 
{
    T = (node *)malloc(sizeof(node));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
}

node *search(tree T, ElemType key) 
{
    while (T != NULL && key != T->data) {
        if (key < T->data) T = T->left;
        else T = T->right;
    }
    return T;
}

node *search_recursion(tree T, ElemType key) 
{
    if (T == NULL)
        return NULL;
    if (key == T->data)
        return T;
    else if (key < T->data)
        return search_recursion(T->left, key);
    else
        return search_recursion(T->right, key);
}

bool insert(tree T, ElemType key) 
{
    while (T != NULL && key != T->data) 
    {
        if (key < T->data) 
            T = T->left;
        else if (key > T->data)
            T = T->right;
        else 
            return false;
    }

    T = create_node(key);

    return true;
}

bool insert_recursion(tree T, ElemType key) 
{
    if (T == NULL) 
    {
        T = create_node(key);
        return true;
    }
    else if (key == T->data)
        return false;

    else if (key < T->data)
        return insert_recursion(T->left, key);

    else if (key > T->data)
        return insert_recursion(T->right, key);
}

int main() 
{

    cin.get();
}