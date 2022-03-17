#include <iostream>
using namespace std;

// 链队列中的元素
typedef struct LinkNode {
    int data;
    struct LNode *next;
} LinkNode;

// 链队列
typedef struct LinkQueue {
    LinkNode *front, *rear;    // 队头指针和队尾指针，都指向链队列中的元素
} LinkQueue;

// 初始化
void InitQueue(LinkQueue &LQ) {
    // 不带头节点的情况下，需要让链队列的队头队尾指针指向 NULL
    LQ.front = NULL;
    LQ.rear = NULL;
}

// 入队
void EnQueue(LinkQueue &LQ, int e) {
    LinkNode *InsertNode = (LinkNode *)malloc(sizeof(LinkNode));
    InsertNode->data = e;
    InsertNode->next = NULL;
    if (LQ.front == NULL) {        // 若入队前链队列为空
        LQ.front = InsertNode;        // 需要令队头指针指向入队节点
        LQ.rear = InsertNode;         // 令表尾指针指向新节点
    } else {
        LQ.rear->next = InsertNode;
        LQ.rear = InsertNode;
    }
}

// 出队
bool DeQueue(SqQueue &LQ, int &e) { }

// 获取队头元素
void GetHead(LinkQueue LQ, int &e) { }

// 获取链队列的长度
void GetLen(LinkQueue LQ) { }

// 输出
void PrintQueue(LinkQueue LQ) { }

// 判空
bool IsEmpty(LinkQueue LQ) {
    return (LQ.front == NULL);
}

// 判满
void IsFull(LinkQueue LQ) { }

int main() {
    LinkQueue LQ;
    InitQueue(LQ);

    PrintQueue(LQ);
    cin.get();
}