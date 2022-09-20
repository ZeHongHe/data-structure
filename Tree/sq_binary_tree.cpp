/* sequence binary tree implement using array */

#include <iostream>
#include <cassert>

#define ElemType int
#define NDEBUG

struct node
{
    ElemType data;
    bool isEmpty;
};

struct tree
{
    struct node *node_arr;
    int len;
};

typedef struct node node;
typedef struct tree tree, *Tree;

void init_binary_tree(Tree T, int len)
{
    T = (tree *)malloc(sizeof(tree));
    assert(T != nullptr);

    T->len = len;
    T->node_arr = (node *)malloc(len * sizeof(node));
    assert(T->node_arr != nullptr);

    for (int i = 0; i < len; i++)
    {
        T->node_arr[i].isEmpty = true;
    }
}

bool isEmpty(Tree T, int index)
{
    assert(index >= 0 && index < T->len);

    return T->node_arr[index].isEmpty;
}

int get_parent(Tree T, int index)
{
    /* root node hasn't parent */
    if (index == 0) return -1;

    int parent = (index + 1) / 2 - 1;
    assert(isEmpty(T ,parent));

    return parent;
}

int get_left_child(Tree T, int index)
{
    // left child node index equals "(i + 1) * 2 - 1 = 2 * i + 1"
    int left_child = index * 2 + 1;
    assert(isEmpty(T, left_child));

    return left_child;
}

int get_right_child(Tree T, int index)
{
    // right child node index equals "[(i + 1) * 2 + 1] - 1 = 2*i + 2"
    int right_child = index * 2 + 2;
    assert(isEmpty(T, right_child));

    return right_child;
}

void visit(Tree T, int index) {}

void preorder_traversal(Tree T, int index)
{
    assert(T != nullptr);
    if (isEmpty(T, index)) return;

    preorder_traversal(T, get_left_child(T, index));
    visit(T, index);
    preorder_traversal(T, get_right_child(T, index));
}

void inorder_traversal(Tree T, int index)
{
    assert(T != nullptr);
    if (isEmpty(T, index)) return;

    inorder_traversal(T, get_left_child(T, index));
    visit(T, index);
    inorder_traversal(T, get_right_child(T, index));
}

void postorder_traversal(Tree T, int index)
{
    assert(T != nullptr);
    if (isEmpty(T, index)) return;

    postorder_traversal(T, get_left_child(T, index));
    postorder_traversal(T, get_right_child(T, index));
    visit(T, index);
}

int main()
{
    std::cin.get();
}