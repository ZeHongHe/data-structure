#include <iostream>
#define ElemType int
using namespace std;

/* ThreadNode, the special data structure of the tree
 * includes:
 *  data: stores the data
 *  left: left child pointer
 *  right: right child pointer
 *  lTag: a flag identifies whether the pointer points to its left child or its precursor
 *  rTag: a flag identifies whether the pointer points to its right child or its successor
 * notes:
 *  while lTag = 0, left points to its left child, and ltag = 1, left points to its precursor
 *  while rTag = 0, right points to its right child, and rtag = 1, right points to its successor
 */
typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *left;     
    struct ThreadNode *right;    
    int lTag;                  
    int rTag;                  
} ThreadNode, *ThreadTree;

// creates a new node and return its pointer
ThreadNode *CreateNode(ElemType data) {
    ThreadNode *ptr = (ThreadNode *)malloc(sizeof(ThreadNode));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// inits a threaded tree
void InitTree(ThreadTree T) {
    T = (ThreadNode *)malloc(sizeof(ThreadNode));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
    T->lTag = 0;
    T->rTag = 0;
}

// inserts node after T 
void InsertNode(ThreadNode *T, ElemType e) {
    ThreadNode *newNode = CreateNode(e);
    if (T->left == NULL) 
        T->left = newNode;
    else if (T->right == NULL)
        T->right = newNode;
    else return;
}

// Traverse T in middle order and convert it
void InThread(ThreadTree T, ThreadNode *pre) {
    if (T != NULL) {
        InThread(T->left, pre);
        if (T->left == NULL) {    // if T node has not left child, change its left ptr pointes to pre node; 
            T->left = pre;
            T->lTag = 1;
        }
        if (pre != NULL && pre->right == NULL) {    // if pre node has not right child, change its right ptr pointes to T node; 
            pre->right = T;
            pre->rTag = 1;
        }
        pre = T;
        InThread(T->right, pre);
    }
}

// converts T into a thread tree
void CreateInThread(ThreadTree T) {
    ThreadNode *pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->right == NULL;
        pre->rTag = 1;
    }
}

int main() {
    ThreadTree root;
    InitTree(root);

    cin.get();
}