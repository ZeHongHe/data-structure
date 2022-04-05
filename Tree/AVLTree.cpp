#include <iostream>
#define ElemType int
using namespace std;

// 平衡二叉树
typedef struct AVLNode {
    int key;
    struct AVLNode *left, *right;
    int height;
} AVLNode, *AVLTree;

int main() {
    AVLTree T;

    cin.get();
}