// g++ SqStack.cpp -o SqStack

#include <iostream>
#define MaxSize 10
using namespace std;

struct Stack 
{
    int data[MaxSize];    // 静态数组存放栈中元素
    int top;              // 栈顶指针，指向栈顶元素
};

// 初始化
void InitStack(Stack &S) {
    S.top = -1;
    // 若初始化时设置 S.top = 0, 则 top 指向栈内可以插入元素的下一个位置
    // 此时 Push 和 Pop 操作中，栈操作和指针操作相反
};

// 销毁
bool DestroyStack(Stack &S) { };

// 进栈
bool Push(Stack &S, int e) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = e;    // 指针先加一，后进栈
    return true; 
};

// 出栈
bool Pop(Stack &S, int &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top--];    // 先出栈，指针后减一
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