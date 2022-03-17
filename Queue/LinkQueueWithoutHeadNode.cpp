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
    LinkNode *EnNode = (LinkNode *)malloc(sizeof(LinkNode));
    if (EnNode == NULL)            // 若内存不足分配失败
        return false;
    EnNode->data = e;
    EnNode->next = NULL;
    if (LQ.front == NULL) {        // 若入队前链队列为空
        LQ.front = EnNode;         // 需要令队头指针指向入队节点
        LQ.rear = EnNode;          // 令表尾指针指向新节点
    } else {
        LQ.rear->next = EnNode;
        LQ.rear = EnNode;
    }
}

// 出队
bool DeQueue(SqQueue &LQ, int &e) {
    if (LQ.front == NULL)
        return false;
    LinkNode *DeNode = LQ.front;
    e = DeNode->data;
    LQ.front = DeNode->next;
    if (LQ.rear == DeNode) {        // 若此时出队的节点是队列最后一个节点
        LQ.rear = NULL;             // 令队头指针和队尾指针都指向 NULL，使队列重新变为空队列
        LQ.front = NULL;
    }
    free(DeNode);
    return true;
}

// 获取队头元素
bool GetHead(LinkQueue LQ, int &e) {
    if (LQ.front == NULL)
        return false;
    e = LQ.front->next->data;
    return true;
}

// 获取链队列的长度
int GetLen(LinkQueue LQ) {
    int len;
    LinkNode *p = LQ.front;
    while(p->next != NULL) {
        p = p->next
        len ++
    }
    return len;
}

// 输出
void PrintQueue(LinkQueue LQ) {
    int len = 1;
    LinkNode *p = LQ.front;
    while(p->next != NULL) {
        printf("The %d node's data is %d \n", len, p->next->data);
        p= p->next;
        len++;
    }
}

// 判空
bool IsEmpty(LinkQueue LQ) {
    return (LQ.front == NULL);
}

int main() {
    LinkQueue LQ;
    InitQueue(LQ);

    PrintQueue(LQ);
    cin.get();
}