#include <iostream>
using namespace std;

struct Stack 
{

};

// 初始化
void InitStack(Stack &S);

// 销毁
void DestroyStack(Stack &S);

// 进栈
void Push(Stack &S, int e);

// 出栈
void Pop(Stack &S, int &e);

// 读取栈顶元素
void GetTop(Stack S, int &e);

// 判空
bool isEmpty(Stack S);

int main() {
    Stack S;
    InitStack(S);
    DestroyStack(S);
    cin.get();
}