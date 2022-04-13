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

// 创建并返回节点
node *create_node(ElemType data) 
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// 初始化
void init_tree(tree T) 
{
    T = (node *)malloc(sizeof(node));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
}

// 查找
node *search(tree T, ElemType key) 
{
    while (T != NULL && key != T->data) {
        if (key < T->data) T = T->left;
        else T = T->right;
    }
    return T;
}

// 递归实现查找
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

// 按排序插入节点
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

// 递归实现按排序插入节点
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

// 构造二叉排序树
void create_bst(tree &T, int str[], int n)
{
    T = NULL;
    for (int i = 0; i < n; i++) insert(T, str[i]);
}


int main() 
{

    cin.get();
}