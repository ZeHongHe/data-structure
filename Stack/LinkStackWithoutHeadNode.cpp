// 链头 = 栈顶

#include <iostream>
using namespace std;

struct LNode {
    int data;
    struct LNode *Next;
};

typedef struct LNode LNode;
typedef struct LNode *LinkStack;

void initStack(LinkStack &LS) { }

void DestroyStack(LinkStack &LS) { }

// 进栈：与对头节点的后插入操作相同
void Push(LinkStack &LS, int e) { }

// 出栈：与对头节点的后删操作相同
void Pop(LinkStack &LS, int e) { }

void GetTop(LinkStack LS) { }

void isEmpty(LinkStack LS) { }

void isFull(LinkStack LS) { }

int main() { 
    cin.get();
}