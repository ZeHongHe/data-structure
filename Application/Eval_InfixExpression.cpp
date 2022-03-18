// g++ Eval_InfixExpression.cpp -o Eval_InfixExpression

#include <iostream>
using namespace std;

typedef struct LNode {
    char data;
    struct LNode *next;
} LNode, *LinkStack;

void InitStack(LinkStack &LS) { }

void Push(LinkStack &LS, char e) { }

void Pop(LinkStack &LS, char &e) { }

void InFix2PostFix(char str[]) { }

void EvalPostFix(char str[]) { }

int main() {
    char InFix[11] = "3+6*(4-2)/3";
    cout << EvalPostFix(InFix2PostFix(InFix)) << endl;
    cin.get();
}