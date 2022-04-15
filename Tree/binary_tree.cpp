/* Binary tree implement using link list*/

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#define NDEBUG

#define ElemType int

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

typedef struct Node node;
typedef struct Node *tree;

void init_tree(tree T) 
{
    T = (node *)malloc(sizeof(node));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
}

node *create_node(ElemType data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

bool insert_node(node *T, ElemType e) {
    node *newNode = create_node(e);
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

void visit(node *T)
{
    printf("%d", T->data);
}

void inorder_traversal(tree T)
{
    if (T != NULL)
    {
        inorder_traversal(T->left);
        visit(T);
        inorder_traversal(T->right);
    }
}

vector<int> inorder_traversal_no_recursion(tree T)
{
    vector<int> res;
    stack<node *> s;
    node *temp = T;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        res.push_back(temp->data);

        temp = temp->right;
    }

    return res;
}

void inorder_traversal_no_recursion2(tree T) { }

void preorder_traversal(tree T)
{
    if (T != NULL)
    {
        visit(T);
        preorder_traversal(T->left);
        preorder_traversal(T->right);
    }
}

vector<int> preorder_traversal_no_recursion(tree T)
{
    vector<int> res;

    if (T == nullptr) return res;

    stack<node *> s;
    node *temp = T;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {   
            res.push_back(temp->data);
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        temp = temp->right;
    }

    return res;
}

vector<int> preorder_traversal_no_recursion2(tree T)
{
    vector<int> res;

    if (T == nullptr) return res;

    stack<node *> s;

    node *temp = T;
    s.push(temp);

    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        res.push_back(temp->data);

        if (temp->right != nullptr) s.push(temp->right); 

        if (temp->left != nullptr) s.push(temp->left);
    }
    
    return res;
}

void postorder_traversal(tree T)
{
    if (T != NULL)
    {
        postorder_traversal(T->left);
        postorder_traversal(T->right);
        visit(T);
    }
}

vector<int> postorder_traversal_no_recursion(tree T)
{
    vector<int> res;
    if (T == nullptr) return res;

    stack<node *> s;
    node *temp = T;
    node *pre = nullptr;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        if (temp->right == nullptr || temp->right == pre)
        {
            res.push_back(temp->data);
            pre = temp;
            temp = nullptr;
        }
        else
        {
            s.push(temp);
            temp = temp->right;
        }
    }
    return res;
}

void postorder_traversal_no_recursion2(tree T) { }

vector<vector<int>> LevelOrder(tree T)
{
    vector<vector<int>> res;
    if (T == nullptr) return res;

    queue<node *> q;
    node *temp = T;
    q.push(temp);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> row;
        for (int i = 0; i < size; i++)
        {
            temp = q.back();
            q.pop();
            row.push_back(temp->data);

            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }

        res.push_back(row);
    }

    return res;
}

int main()
{
    cin.get();
}