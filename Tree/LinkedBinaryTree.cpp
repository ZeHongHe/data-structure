#include <iostream>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

// 初始化
void InitTree(BiTree &BiT) {
    BiT = (BiTNode *)malloc(sizeof(BiTNode));
    (*BiT).data = 0;
    (*BiT).left = NULL;
    (*BiT).right = NULL;
}

// 插入节点
void InsertNode(BiTNode *BiT, int e) {
    BiTNode * pNode = (BiTNode *)malloc(sizeof(BiTNode));
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

void PrintNode(BiTNode BiT){
    printf("%d ", BiT->data);
}

// 先序遍历
void PreOrder(BiTNode BiT) {
    if (BiT != NULL) {
        PrintNode(BiT);
        PreOrder(BiT->left);
        PreOrder(BiT->right);
    }
}

// 中序遍历
void InOrder(BiTNode BiT) {
    if (BiT != NULL) {
        InOrder(BiT->left);
        PrintNode(BiT);
        InOrder(BiT->right);
    }
}

// 后序遍历
void PostOrder(BiTNode *BiT) {
    if (BiT != NULL) {
        PostOrder(BiT->left);
        PostOrder(BiT->right);
        PrintNode(BiT);
    }
}

int main() {
    BiTree root;

    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;

    cin.get();
}