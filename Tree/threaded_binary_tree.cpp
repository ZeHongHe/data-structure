#include <iostream>
#define ElemType int
using namespace std;

struct Node {
    ElemType data;
    struct Node *left, *right;
    int lTag, rTag;
};

typedef struct Node node, *thread_tree;

// creates a new node and return its pointer
node *CreateNode(ElemType data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// inits a threaded tree
void InitTree(thread_tree T)
{
    T = (node *)malloc(sizeof(node));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
    T->lTag = 0;
    T->rTag = 0;
}

// inserts node after T 
bool InsertNode(node *T, ElemType e)
{
    node *newNode = CreateNode(e);
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

node *pre = NULL;

void Visit(node *T)
{
    if (T->left == NULL)
    {    
            T->left = pre;
            T->lTag = 1;
    }

    if (pre != NULL && pre->right == NULL)
    {   
        pre->right = T;
        pre->rTag = 1;
    }

    pre = T;
}


void InThread(thread_tree T, node *pre)
{
    if (T != NULL)
    {
        InThread(T->left, pre);
        Visit(T);
        InThread(T->right, pre);
    }
}


void CreateInThread(thread_tree T)
{
    node *pre = NULL;
    if (T != NULL)
    {
        InThread(T, pre);
        pre->right = NULL;
        pre->rTag = 1;
    }
}


void PreThread(thread_tree T, node *pre)
{
    if (T != NULL)
    {
        Visit(T);
        if (T->lTag == 0)
            PreThread(T->left, pre);
        PreThread(T->right, pre);
    }
}


void CreatePreThread(thread_tree T)
{
    node *pre = NULL;
    if (T != NULL)
    {
        PreThread(T, pre);
        pre->right = NULL;
        pre->rTag = 1;
    }
}


void PostThread(thread_tree T, node *pre)
{
    if (T != NULL)
    {
        PostThread(T->left, pre);
        PostThread(T->right, pre);
        Visit(T);
    }
}


void CreatePostThread(thread_tree T)
{
    node *pre = NULL;
    if (T != NULL)
    {
        PostThread(T, pre);
        if (pre->right == NULL) pre->rTag = 1;
    }
}

// 找到以 p 为根的子树中，第一个被中序遍历的节点
node *FirstNodeInOrder(node *p)
{
    while (p->lTag == 0)
        p = p->left;
    return p;
}

// 找到以 p 为根的子树中，最后一个被中序遍历的节点
node *LastNodeInOrder(node *p)
{
    while (p->rTag == 0)
        p = p->right;
    return p;
}

// 找到 p 的中序后继节点
node *NextNodeInOrder(node *p)
{
    if (p->rTag == 0) return FirstNode(p->right);
    else return p->right;
}

// 找到 p 的中序前驱节点
node *PreNodeInOrder(node *p)
{ 
    if (p->lTag == 0) return LastNode(p->left);
    else return p->left;
}

// 线索二叉树的中序遍历的非递归实现
void InOrderNonRecursion(thread_tree T)
{
    for(node* p = FirstNode(T); p != NULL; p = NextNode(p))
        Visit(p);
}

// 线索二叉树的逆中序遍历的非递归实现
void InReverseOrderNonRecursion(thread_tree T)
{
    for(node* p = LastNode(T); p != NULL; p = PreNode(p))
        Visit(p);
}

// 找到以 p 为根的子树中，第一个被先序遍历的节点
node *FirstNodePreOrder(node *p)
{
    return p;    // 原地 TP
}

// 找到以 p 为根的子树中，最后一个被先序遍历的节点
node *FirstNodePreOrder(node *p)
{
    if (p->left == NULL && p->right == NULL) return p;
    // 未完成
}

// 找到 p 的先序后继节点
node *NextNodePreOrder(node *p)
{
    if (p->rTag == 1 || p->lTag == 1) return p->right;
    else return p->left;
}

// 找到 p 的先序前驱节点
node *PreNodePreOrder(node *p)
{
    if (p->lTag == 1) return p->left;
    else return p;   // 若 lTag == 0，则无法找到 p 的先序前驱节点，除非是改用三叉链表找到父节点或从根节点开始遍历
}

// 找到 p 的后序后继节点
node *NextNodePostOrder(node *p)
{
    if (p->rTag == 1) return p->right;
    else return p;   // 若 rTag == 0，则无法找到 p 的后序后续节点，除非是改用三叉链表找到父节点或从根节点开始遍历
}

// 找到 p 的后序前驱节点
node *PreNodePostOrder(node *p)
{
    if (p->lTag == 1) return p->lTag;
    else if (p->rTag == 0 && p->right != NULL) return p->right;
    else return p->left;
}

int main()
{
    cin.get();
}