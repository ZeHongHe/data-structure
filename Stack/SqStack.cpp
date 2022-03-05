// g++ SqStack.cpp -o SqStack

#include <iostream>
#define MaxSize 10
using namespace std;

struct Stack 
{
    int data[MaxSize];    // 静态数组存放栈中元素
    int top;              // 栈顶指针
};

// 初始化
void InitStack(Stack &S) {
    S.top = -1;
};

// 销毁
bool DestroyStack(Stack &S) { };

// 进栈
bool Push(Stack &S, int e) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = e;
    return true; 
};

// 出栈
bool Pop(Stack &S, int &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
};

// 读取栈顶元素
bool GetTop(Stack S, int &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top];
    return true;
};

// 判空
bool isEmpty(Stack S) {
    return (S.top == -1);
};

int main() {
    Stack S;
    
    InitStack(S);
    DestroyStack(S);

    cin.get();
}