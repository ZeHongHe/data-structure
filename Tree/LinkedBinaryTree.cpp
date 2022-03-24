#include <iostream>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

// 初始化
void InitTree(BiTree &BiT) {
    BiT = (BiTNode *)malloc(sizeof(BiTNode));
    BiT->data = 0;
    BiT->left = NULL;
    BiT->right = NULL;
}

// 插入节点
void InsertNode(BiTNode &BiT, int e) {
    BiTNode * pNode = (BiTNode *)malloc(sizeof(BiTNode));
    pNode->data = e;
    pNode->left = NULL;
    pNode->right = NULL;
    if (BiT->left == NULL)
        BiT->left = pNode;
    else 
        BiT->right = pNode;
}

int main() {
    BiTree root;
    InitTree(root);

    cin.get();
}