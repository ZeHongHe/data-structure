#include <iostream>
#define ElemType int
using namespace std;
/* TreeNode, the basic data structure of the tree
 * include:
 *  left: left child pointer
 *  right: right child pointer
 */
typedef struct TreeNode {
    ElemType data;
    struct TreeNode *left;  
    struct TreeNode *right;
} TreeNode, *Tree;

/* ThreadedNode, the special data structure of the tree
 * includes:
 *  left: left child pointer
 *  right: right child pointer
 *  lTag: a flag identifies whether the pointer points to its left child or its precursor
 *  rTag: a flag identifies whether the pointer points to its right child or its successor
 * notes:
 *  while lTag = 0, left points to its left child, and ltag = 1, left points to its precursor
 *  while rTag = 0, right points to its right child, and rtag = 1, right points to itssuccessor
 */
typedef struct ThreadedNode {
    ElemType data;
    struct ThreadedNode *left;     
    struct ThreadedNode *right;    
    int lTag;                  
    int rTag;                  
} ThreadedNode, *ThreadedTree;

// creates a new node and return its pointer
ThreadedNode *CreateNode(ElemType data) {
    ThreadedNode *ptr = (ThreadedNode *)malloc(sizeof(ThreadedNode));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// inits a threaded tree
void InitTree(ThreadedTree &T) {
    T = (ThreadedNode *)malloc(sizeof(ThreadedNode));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
    T->lTag = 0;
    T->rTag = 0;
}



int main() {
    ThreadedTree root;
    InitTree(root);

    cin.get();
}