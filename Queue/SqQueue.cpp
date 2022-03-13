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
    SQ.front = (SQ.rear + 1) % MaxSize;
    return true;
}

// 获取队头元素
bool GetHead(SqQueue SQ, int &e) {
    if (SQ.front == SQ.rear)
        return false;
    e = SQ.data[SQ.front];
    return true;
}

// 获取队列元素个数
int GetNum(SqQueue SQ) {
    return ((SQ.rear + MaxSize - SQ.front) % MaxSize);
}

// 输出
void PrintQueue(SqQueue SQ) { }

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

    cin.get();
}