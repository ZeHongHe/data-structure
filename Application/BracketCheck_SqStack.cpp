// g++ BracketCheck_SqStack.cpp -o BracketCheck_SqStack

#include <iostream>
#define MaxSize 10
using namespace std;

typedef struct SqStack {
    char data[MaxSize];    // char 型数据域
    int top;               // 栈顶指针
} SqStack;

// 初始化
void InitStack(SqStack &S) {
    S.top = -1;
}

// 入栈
bool Push(SqStack &S, char e) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = e;
    return true;
}

// 出栈
bool Pop(SqStack &S, char &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

// 判空
bool IsEmpty(SqStack S) {
    return (S.top == -1);
}

// 括号匹配
bool BracketCheck(char str[], int len) {
    SqStack S;
    InitStack(S);
    for(int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else {
            if (IsEmpty(S))
                return false;
            char TopElem;
            Pop(S, TopElem);
            if (str[i] == ')' && TopElem != '(')
                return false;
            if (str[i] == ']' && TopElem != '[')
                return false;
            if (str[i] == '}' && TopElem != '{')
                return false;
        }
    }
    return (IsEmpty(S));
}

int main() {
    char ValidStr[3] = "()";
    if (BracketCheck(ValidStr, 2)) {
        printf("Brackets are Valid!");
    } else {
        printf("Brackets are not Valid!");
    }
    cin.get();
}