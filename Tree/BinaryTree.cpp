#include <iostream>
#define ElemType int
using namespace std;

/* TreeNode, the basic data structure of the tree
 * include:
 *  left: left child pointer
 *  right: right child pointer
 */
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode, *Tree;

// 初始化
void InitTree(Tree T) {
    T = (TreeNode *)malloc(sizeof(TreeNode));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
}

// 创造并返回一个树节点
TreeNode *CreateNode(ElemType data) {
    TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// 插入节点
bool InsertNode(TreeNode *T, ElemType e) {
    TreeNode *newNode = CreateNode(e);
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

void Visit(TreeNode *T) { }

// 中序遍历
void InOrder(Tree T) {
    if (T != NULL) {
        InOrder(T->left);
        Visit(T);
        InOrder(T->right);
    }
}

// 中序遍历：非递归版
void InOrderNonRecursion(Tree T) { }

// 先序遍历
void PreOrder(Tree T) {
    if (T != NULL) {
        Visit(T);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

// 先序遍历：非递归版
void PreOrderNonRecursion(Tree T) { }

// 后序遍历
void PostOrder(Tree T) {
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        Visit(T);
    }
}

// 后序遍历：非递归版
void PostOrderNonRecursion(Tree T) { }

// 层序遍历
void LevelOrder(Tree T) { }

int main() {
    Tree root;
    InitTree(root);

    cin.get();
}