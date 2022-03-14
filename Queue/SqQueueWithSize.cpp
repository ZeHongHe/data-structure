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
void EnQueue(SqQueue &SQ) { }

// 出队
void DeQueue(SqQueue &SQ) { }

// 获取队头元素
void GetHead(SqQueue SQ) { }

// 获取队列长度
void GetLen(SqQueue SQ) { }

// 输出
void PrintQueue(SqQueue SQ) { }

// 判空
void IsEmpty(SqQueue SQ) { }

// 判满
void IsFull(SqQueue SQ) { }

int main() {
    SqQueue SQ;
    InitQueue(SQ);

    PrintQueue(SQ);
    cin.get();
}