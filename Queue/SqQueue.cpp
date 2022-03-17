// g++ SqQueue.cpp -o SqQueue

#include <iostream>
#define MaxSize 10
using namespace std;

// 队列： 队尾插入，队头取出
struct SqQueue {
    int data[MaxSize];    // 静态数组存放队列元素
    int front, rear;    // 队头指针和队尾指针
};

// 初始化
void InitQueue(SqQueue &SQ) {
    SQ.front = SQ.rear = 0;
}

// 入队
bool EnQueue(SqQueue &SQ, int e) {
    if ((SQ.rear + 1) % MaxSize == SQ.front)    // 队列判满的条件
        return false;
    SQ.data[SQ.rear] = e;
    SQ.rear = (SQ.rear + 1) % MaxSize;    // 取模使静态队列变为循环队列
    return true;
}

// 出队
bool DeQueue(SqQueue &SQ, int &e) {
    if (SQ.front == SQ.rear)    // 队列判空的条件
        return false;
    e = SQ.data[SQ.front];
    SQ.front = (SQ.front + 1) % MaxSize;
    return true;
}

// 获取队头元素
bool GetHead(SqQueue SQ, int &e) {
    if (SQ.front == SQ.rear)
        return false;
    e = SQ.data[SQ.front];
    return true;
}

// 获取队列长度
int GetLen(SqQueue SQ) {
    return ((SQ.rear + MaxSize - SQ.front) % MaxSize);
}

// 输出
bool PrintQueue(SqQueue SQ) {
    int PresentFront = SQ.front;
    int PresentRear = SQ.rear;
    if (PresentFront == PresentRear) {
        printf("Sequence Queue is empty!\n");
        return false;
    }
    while (PresentFront != PresentRear) {
        printf("%d\n", SQ.data[PresentFront]);
        PresentFront = (PresentFront + 1) % MaxSize;
    }
    return true;
}

// 判空
bool IsEmpty(SqQueue SQ) {
    return (SQ.front == SQ.rear);
}

// 判满
bool IsFull(SqQueue SQ) {
    return ((SQ.rear + 1) % MaxSize == SQ.front);
}

int main() {
    SqQueue SQ;

    InitQueue(SQ);
    for (int i = 0; i < 10; i++) {
        EnQueue(SQ, i);
    }

    PrintQueue(SQ);

    cin.get();
}