// g++ SqQueueWithSize.cpp -o SqQueueWithSize

#include <iostream>
#define MaxSize 10
using namespace std;

// 队列： 队尾插入，队头取出
struct SqQueue {
    int data[MaxSize];    // 静态数组存放队列元素
    int front;            // 队头指针
    int rear;             // 队尾指针
    int size;             // 队列当前长度
};

// 初始化
void InitQueue(SqQueue &SQ) {
    SQ.front = SQ.rear = SQ.size = 0;
}

// 入队
bool EnQueue(SqQueue &SQ, int e) {
    if (SQ.size == MaxSize)
        return false;
    SQ.data[SQ.rear] = e;
    SQ.rear = (SQ.rear + 1) % MaxSize;
    SQ.size++;
    return true;
}

// 出队
bool DeQueue(SqQueue &SQ, int &e) {
    if (SQ.size == 0)
        return false;
    e = SQ.data[SQ.front];
    SQ.front = (SQ.front + 1) % MaxSize;
    SQ.size--;
    return true;
}

// 获取队头元素
bool GetHead(SqQueue SQ, int e) {
    if (SQ.size == 0)
        return false;
    e = SQ.data[SQ.front];
    return true;
}

// 获取队列长度
int GetLen(SqQueue SQ) {
    return SQ.size;
}

// 输出
bool PrintQueue(SqQueue SQ) {
    int PresentFront = SQ.front;
    int PresentRear = SQ.rear;
    int PresentSize = SQ.size;
    if (PresentSize == 0) 
        printf("Sequence Queue is empty!\n");
        return false;
    while (PresentFront != PresentRear) {
        printf("%d\n", SQ.data[PresentFront]);
        PresentFront = (PresentFront + 1) % MaxSize;
        PresentSize++;
    }
    return true;
}

// 判空
bool IsEmpty(SqQueue SQ) {
    return (SQ.size == 0);
}

// 判满
bool IsFull(SqQueue SQ) {
    return (SQ.size == MaxSize);
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