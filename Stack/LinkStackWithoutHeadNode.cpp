// g++ LinkStackWithoutHeadNode.cpp -o LinkStackWithoutHeadNode

#include <iostream>
using namespace std;

struct LNode {
    int data;
    struct LNode *Next;
};

typedef struct LNode LNode;
typedef struct LNode *LinkStack;

void InitStack(LinkStack &LS) { }

void DestroyStack(LinkStack &LS) { }

// 进栈：与对头节点的后插入操作相同
void Push(LinkStack &LS, int e) { }

// 出栈：与对头节点的后删操作相同
void Pop(LinkStack &LS, int e) { }

void PrintStack(LinkStack LS) { }

void GetTop(LinkStack LS) { }

void IsEmpty(LinkStack LS) { }

int main() {
    LinkStack LS;
    InitStack(LS);

    cin.get();
}