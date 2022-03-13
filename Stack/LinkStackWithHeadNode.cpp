// g++ LinkStackWithHeadNode.cpp -o LinkStackWithHeadNode

#include <iostream>
using namespace std;

struct LNode {
    int data;
    struct LNode *next;
};

typedef struct LNode LNode;
typedef struct LNode *LinkStack;

// 初始化：链栈
bool InitStack(LinkStack &LS) {
    LS = (LNode *)malloc(sizeof(LNode));
    if (LS == NULL)
        return false;
    LS->next = NULL;
    return true;
}

// 销毁
void DestroyStack(LinkStack &LS) {
    while (LS->next != NULL) {
        LNode *deleteNode = LS->next;
        LS->next = deleteNode->next;
        free(deleteNode);
    }
}

// 进栈：与对头节点的后插入操作相同
bool Push(LinkStack &LS, int e) {
    LNode *PushNode = (LNode *)malloc(sizeof(LNode));
    if (PushNode == NULL)
        return false;
    PushNode->data = e;
    PushNode->next = LS->next;
    LS->next = PushNode;
    return true;
}

// 出栈：与对头节点的后删操作相同
bool Pop(LinkStack &LS, int e) {
    if (LS->next == NULL)
        return false;
    LNode *PopNode = LS->next;
    LS->next = PopNode->next;
    e = PopNode->data;
    free(PopNode);
    return true;
}

void PrintStack(LinkStack LS) {
    int len = 1;
    LNode *PresentNode = LS->next;
    while (PresentNode->next != NULL) {
        printf("The value of the %d Node in the Stack is %d.\n", len, PresentNode->data);
        PresentNode = PresentNode->next;
        len++; 
    }
}

// 获取栈顶元素
int GetTop(LinkStack LS) {
    return (LS->next->data);
}

// 链栈判空
bool isEmpty(LinkStack LS) {
    return (LS->next == NULL);
}

int main() {
    LinkStack LS;
    InitStack ;LS;
    for (int i = 0; i < 10; i++) {
        Push(LS, i);
    }
    PrintStack(LS);
    DestroyStack(LS);
    cin.get();
}