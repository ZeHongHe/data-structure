#include <iostream>
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

// 插入节点
void InsertNode(TreeNode *T, int e) {
    TreeNode * pNode = (TreeNode *)malloc(sizeof(TreeNode));
    pNode->data = e;
    pNode->left = NULL;
    pNode->right = NULL;
    if ((*T).left == NULL)
        (*T).left = pNode;
    else if ((*T).right == NULL)
        (*T).right = pNode;
    else 
        return;
}

void PrintNode(TreeNode *T){ }

// 先序遍历
void PreOrder(TreeNode *T) {
    if (T != NULL) {
        PrintNode(T);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

// 中序遍历
void InOrder(TreeNode *T) {
    if (T != NULL) {
        InOrder(T->left);
        PrintNode(T);
        InOrder(T->right);
    }
}

// 后序遍历
void PostOrder(TreeNode *T) {
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        PrintNode(T);
    }
}

int main() {
    Tree root;
    InitTree(root);

    cin.get();
}