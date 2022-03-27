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
 *  while lTag = 0, left points to left child, and ltag = 1, left points to precursor
 *  while rTag = 0, right points to right child, and rtag = 1, right points to successor
 */
typedef struct ThreadedNode {
    ElemType data;
    struct TreeNode *left;     
    struct TreeNode *right;    
    int lTag;                  
    int rTag;                  
} ThreadedNode, *ThreadedTree;

// creates a new node and return its pointer
TreeNode *CreateNode(ElemType data) {
    TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}


int main() {
    Tree root;

    cin.get();
}