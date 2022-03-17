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
bool EnQueue(LinkQueue &LQ, int e) {
    LinkNode *EnNode = (LinkNode *)malloc(sizeof(LinkNode));
    if (EnNode == NULL)        // 若内存不足分配失败
        return false;
    EnNode->data = e;
    EnNode->next = NULL;       // 新节点在队尾，需指向 NULL
    LQ.rear->next = EnNode;    // 令新节点插入到头节点之后 
    LQ.rear = EnNode;          // 令队尾指针指向新节点
    return true;
}

// 出队
bool DeQueue(SqQueue &LQ, int &e) {
    if (LQ.front == LQ.rear) 
        return false;
    LinkNode *DeNode = LQ.front->next;
    e = DeNode->data;
    LQ.front->next = DeNode->next;
    if (LQ.rear == DeNode)            // 若此时出队的节点是队列最后一个节点
        LQ.rear = LQ.front;           // 令队尾指针指向头节点，使队列重新变为空队列
    free(DeNode);
    return true;
}

// 获取队头元素
bool GetHead(LinkQueue LQ, int &e) {
    if (LQ.front == LQ.rear)
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
    return (LQ.front == LQ.rear);
}

int main() {
    LinkQueue LQ;
    InitQueue(LQ);

    PrintQueue(LQ);
    cin.get();
}