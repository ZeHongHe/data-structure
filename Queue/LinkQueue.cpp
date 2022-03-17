#include <iostream>
using namespace std;

// 链队列中的元素
typedef struct LinkNode {
    int data;
    struct LNode *next;
} LinkNode;

// 链队列
typedef struct LinkQueue {
    LinkNode *front, *rear;
} LinkQueue;

// 初始化
void InitQueue(LinkQueue &LQ) {
    // 申请头节点的内存空间，并让链队列的队头队尾指针指向头节点
    LQ.front = LQ.rear = (LinkNode *)malloc(sizeof(LinkNode));
    // 让头节点的 next 指向 NULL
    LQ.front->next = NULL;
}

// 入队
void EnQueue(LinkQueue &LQ, int e) {
    LinkNode *InsertNode = (LinkNode *)malloc(sizeof(LinkNode));
    InsertNode->data = e;
    InsertNode->next = NULL;       // 新节点在队列尾部，需指向 NULL
    LQ.rear->next = InsertNode;    // 令新节点插入到头节点之后 
    LQ.rear = InsertNode;          // 令表尾指针指向新节点
}

// 出队
void GetHead(LinkQueue &LQ, int &e) { }

// 获取链队列的长度
void GetLen(LinkQueue LQ) { }

// 输出
void PrintQueue(LinkQueue LQ) { }

// 判空
bool IsEmpty(LinkQueue LQ) {
    return (LQ.front == LQ.rear);
}

// 判满
void IsFull(LinkQueue LQ) { }

int main() {
    LinkQueue LQ;
    InitQueue(LQ);

    PrintQueue(LQ);
    cin.get();
}