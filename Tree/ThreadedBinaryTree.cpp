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

// pre is used for chasing somenode's precursor
ThreadNode *pre = NULL;

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

void CreateInThread(ThreadNode) {

}

// 
void visitNode(ThreadNode *T) {
    printf("%d\n", T->data);
}


int main() {
    ThreadTree root;
    InitTree(root);

    cin.get();
}