#include <iostream>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T){
    *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=1;
    (*T)->left=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->right=(BiTNode*)malloc(sizeof(BiTNode));
  
    (*T)->left->data=2;
    (*T)->left->left=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->left->right=(BiTNode*)malloc(sizeof(BiTNode));

    (*T)->left->right->data=5;
    (*T)->left->right->left=NULL;
    (*T)->left->right->right=NULL;

    (*T)->right->data=3;
    (*T)->right->left=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->right->left->data=6;
    (*T)->right->left->left=NULL;
    (*T)->right->left->right=NULL;
    (*T)->right->right=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->right->right->data=7;
    (*T)->right->right->left=NULL;
    (*T)->right->right->right=NULL;
    (*T)->left->left->data=4;
    (*T)->left->left->left=NULL;
    (*T)->left->left->right=NULL;
}
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

void PrintNode(BiTNode *BiT){
    printf("%d ", (*BiT).data);
}

// 先序遍历
void PreOrder(BiTNode *BiT) {
    if (BiT != NULL) {
        PrintNode(BiT);
        PreOrder((*BiT).left);
        PreOrder((*BiT).right);
    }
}

// 中序遍历
void InOrder(BiTNode *BiT) {
    if (BiT != NULL) {
        InOrder((*BiT).left);
        PrintNode(BiT);
        InOrder((*BiT).right);
    }
}

// 后序遍历
void PostOrder(BiTNode *BiT) {
    if (BiT != NULL) {
        PostOrder((*BiT).left);
        PostOrder((*BiT).right);
        PrintNode(BiT);
    }
}

int main() {
    BiTree root;
    CreateBiTree(&root);

    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;

    cin.get();
}