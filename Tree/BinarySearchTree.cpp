#include <iostream>
#define ElemType int
using namespace std;

// 二叉搜索树
struct BSTNode 
{
    int data;
    struct BSTNode *left, *right;
};

typedef struct BSTNode BSTNode;
typedef struct BSTNode *BSTree;

// 创建并返回节点
BSTNode *CreateNode(ElemType data) 
{
    BSTNode *ptr = (BSTNode *)malloc(sizeof(BSTNode));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// 初始化
void InitTree(BSTree T) 
{
    T = (BSTNode *)malloc(sizeof(BSTNode));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
}

// 查找
BSTNode *SearchKey(BSTree T, ElemType key) 
{
    while (T != NULL && key != T->data) {
        if (key < T->data) T = T->left;
        else T = T->right;
    }
    return T;
}

// 递归实现查找
BSTNode *SearchKeyWithRecursion(BSTree T, ElemType key) 
{
    if (T == NULL)
        return NULL;
    if (key == T->data)
        return T;
    else if (key < T->data)
        return SearchKeyWithRecursion(T->left, key);
    else
        return SearchKeyWithRecursion(T->right, key);
}

// 按排序插入节点
bool InsertKey(BSTree T, ElemType key) 
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

    T = CreateNode(key);

    return true;
}

// 递归实现按排序插入节点
bool InsertKeyWithRecursion(BSTree T, ElemType key) 
{
    if (T == NULL) 
    {
        T = CreateNode(key);
        return true;
    }
    else if (key == T->data)
        return false;

    else if (key < T->data)
        return InsertKeyWithRecursion(T->left, key);

    else if (key > T->data)
        return InsertKeyWithRecursion(T->right, key);
}

// 构造二叉排序树
void CreateBST(BSTree &T, int str[], int n)
{
    T = NULL;
    for (int i = 0; i < n; i++) InsertKey(T, str[i]);
}


int main() 
{
    BSTree T;
    int str[8] = {50, 66, 60, 26, 21, 30, 70, 68};
    CreateBST(T, str, 8);
    SearchKey(T, 26);

    cin.get();
}