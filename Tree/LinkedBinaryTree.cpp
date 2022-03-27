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
void InitTree(Tree &BiT) {
    BiT = (TreeNode *)malloc(sizeof(TreeNode));
    (*BiT).data = 0;
    (*BiT).left = NULL;
    (*BiT).right = NULL;
}

// 插入节点
void InsertNode(TreeNode *BiT, int e) {
    TreeNode * pNode = (TreeNode *)malloc(sizeof(TreeNode));
    pNode->data = e;
    pNode->left = NULL;
    pNode->right = NULL;
    if ((*BiT).left == NULL)
        (*BiT).left = pNode;
    else if ((*BiT).right == NULL)
        (*BiT).right = pNode;
    else 
        return;
}

void PrintNode(TreeNode BiT){
    printf("%d ", BiT->data);
}

// 先序遍历
void PreOrder(TreeNode BiT) {
    if (BiT != NULL) {
        PrintNode(BiT);
        PreOrder(BiT->left);
        PreOrder(BiT->right);
    }
}

// 中序遍历
void InOrder(TreeNode BiT) {
    if (BiT != NULL) {
        InOrder(BiT->left);
        PrintNode(BiT);
        InOrder(BiT->right);
    }
}

// 后序遍历
void PostOrder(TreeNode *BiT) {
    if (BiT != NULL) {
        PostOrder(BiT->left);
        PostOrder(BiT->right);
        PrintNode(BiT);
    }
}

int main() {
    Tree root;

    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;

    cin.get();
}