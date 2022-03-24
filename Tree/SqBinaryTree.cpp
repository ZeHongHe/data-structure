#include <iostream>
#define MaxSize 100
using namespace std;

struct SqTreeNode {
    int data;
    bool isEmpty;
};

void InitTree(SqTreeNode ST[]) {
    for(int i = 0; i < MaxSize; i++) {
        ST[i].isEmpty = true;
    }
}

int main() {
    SqTreeNode ST[MaxSize];
    InitTree(ST);

    cin.get();
}