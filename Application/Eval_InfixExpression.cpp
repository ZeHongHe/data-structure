// g++ Eval_InfixExpression.cpp -o Eval_InfixExpression

#include <iostream>
using namespace std;

// 链栈
typedef struct LNode {
    char data;
    struct LNode *next;
} LNode, *LinkStack;

// 初始化
bool InitStack(LinkStack &LS) {
    LS = (LNode *)malloc(sizeof(LNode));
    if (LS == NULL)
        return false;
    LS->next = NULL;
    return true;
}

// 入栈
bool Push(LinkStack &LS, char e) {
    LNode *PushNode = (LNode *)malloc(sizeof(LNode));
    if (PushNode == NULL) 
        return false;
    PushNode->data = e;
    PushNode->next = LS->next;
    LS->next = PushNode;
    return true;
}

// 出栈
bool Pop(LinkStack &LS, char &e) {
    if (LS->next == NULL)
        return false;
    LNode *PopNode = LS->next;
    e = PopNode->data;
    LS->next = PopNode->next;
    free(PopNode);
    return true;
}

// 中缀表达式转后缀表达式
void InFix2PostFix(char str[]) { }

// 后缀表达式求值
void EvalPostFix(char str[]) { }


int main() {

    cin.get();
}