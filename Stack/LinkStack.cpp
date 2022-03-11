#include <iostream>
using namespace std;

struct LNode {
    int data;
    struct LNode *Next;
};

typedef struct LNode LNode;
typedef struct LNode *LinkStack;

void initStack(LinkStack &LS) { }

void DestroyStack(LinkStack &LS) {}

void Push(LinkStack &LS, int e) { }

void Pop(LinkStack &LS, int e) { }

void GetTop(LinkStack LS) { }

void isEmpty(LinkStack LS) { }

void isFull(LinkStack LS) { }

int main() { 
    cin.get();
}