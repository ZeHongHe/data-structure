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
    struct ThreadNode *left, *right;
    int lTag, rTag;
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
bool InsertNode(ThreadNode *T, ElemType e) {
    ThreadNode *newNode = CreateNode(e);
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

// pre ptr points to node's precursor
ThreadNode *pre = NULL;

// add precursor and successor pointer for T node
void Visit(ThreadNode *T) {
    if (T->left == NULL) {    // if T node has not left child, change its left ptr pointes to pre node; 
            T->left = pre;
            T->lTag = 1;
    }
    if (pre != NULL && pre->right == NULL) {    // if pre node(Previous T node) has not right child, change its right ptr pointes to T node; 
        pre->right = T;
        pre->rTag = 1;
    }
    pre = T;
}

// Traverse T in middle order and convert it
void InThread(ThreadTree T, ThreadNode *pre) {
    if (T != NULL) {
        InThread(T->left, pre);
        Visit(T);
        InThread(T->right, pre);
    }
}

// converts T into a thread tree
void CreateInThread(ThreadTree T) {
    ThreadNode *pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->right = NULL;
        pre->rTag = 1;
    }
}

// Traverse T in pre order and convert it
void PreThread(ThreadTree T, ThreadNode *pre) {
    if (T != NULL) {
        Visit(T);
        if (T->lTag == 0)
            PreThread(T->left, pre);
        PreThread(T->right, pre);
    }
}

// converts T into a thread tree
void CreatePreThread(ThreadTree T) {
    ThreadNode *pre = NULL;
    if (T != NULL) {
        PreThread(T, pre);
        pre->right = NULL;
        pre->rTag = 1;
    }
}

// Traverse T in post order and convert it
void PostThread(ThreadTree T, ThreadNode *pre) {
    if (T != NULL) {
        PostThread(T->left, pre);
        PostThread(T->right, pre);
        Visit(T);
    }
}

// converts T into a thread tree
void CreatePostThread(ThreadTree T) {
    ThreadNode *pre = NULL;
    if (T != NULL) {
        PostThread(T, pre);
        if (pre->right == NULL)
            pre->rTag = 1;
    }
}

// 找到以 p 为根的子树中，第一个被中序遍历的节点
ThreadNode *FirstNodeInOrder(ThreadNode *p) {
    while (p->lTag == 0)
        p = p->left;
    return p;
}

// 找到以 p 为根的子树中，最后一个被中序遍历的节点
ThreadNode *LastNodeInOrder(ThreadNode *p) {
    while (p->rTag == 0)
        p = p->right;
    return p;
}

// 找到 p 的中序后继节点
ThreadNode *NextNodeInOrder(ThreadNode *p) {
    if (p->rTag == 0) return FirstNode(p->right);
    else return p->right;
}

// 找到 p 的中序前驱节点
ThreadNode *PreNodeInOrder(ThreadNode *p) { 
    if (p->lTag == 0) return LastNode(p->left);
    else return p->left;
}

// 线索二叉树的中序遍历的非递归实现
void InOrderNonRecursion(ThreadTree T) {
    for(ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
        Visit(p);
}

// 线索二叉树的逆中序遍历的非递归实现
void InReverseOrderNonRecursion(ThreadTree T) {
    for(ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
        Visit(p);
}

// 找到以 p 为根的子树中，第一个被先序遍历的节点
ThreadNode *FirstNodePreOrder(ThreadNode *p) {
    return p;    // 原地 TP
}

// 找到以 p 为根的子树中，最后一个被先序遍历的节点
ThreadNode *FirstNodePreOrder(ThreadNode *p) {
    if (p->left == NULL && p->right == NULL) return p;
    // 未完成
}

// 找到 p 的先序后继节点
ThreadNode *NextNodePreOrder(ThreadNode *p) {
    if (p->rTag == 1 || p->lTag == 1) return p->right;
    else return p->left;
}

// 找到 p 的先序前驱节点
ThreadNode *PreNodePreOrder(ThreadNode *p) {
    if (p->lTag == 1) return p->left;
    else return p;   // 若 lTag == 0，则无法找到 p 的先序前驱节点，除非是改用三叉链表找到父节点或从根节点开始遍历
}

// 找到 p 的后序后继节点
ThreadNode *NextNodePostOrder(ThreadNode *p) {
    if (p->rTag == 1) return p->right;
    else return p;   // 若 rTag == 0，则无法找到 p 的后序后续节点，除非是改用三叉链表找到父节点或从根节点开始遍历
}

// 找到 p 的后序前驱节点
ThreadNode *PreNodePostOrder(ThreadNode *p) {
    if (p->lTag == 1) return p->lTag;
    else if (p->rTag == 0 && p->right != NULL) return p->right;
    else return p->left;
}

int main() {
    ThreadTree root;
    InitTree(root);

    cin.get();
}