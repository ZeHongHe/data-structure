// g++ SqQueueWithSize.cpp -o SqQueueWithSize

#include <iostream>
#define MaxSize 10
using namespace std;

// 队列： 队尾插入，队头取出
struct SqQueue {
    int data[MaxSize];    // 静态数组存放队列元素
    int front, rear;    // 队头指针和队尾指针
    int size;
};

void InitQueue(SqQueue &SQ) {
    SQ.front = SQ.rear = SQ.size = 0;
}

int main() {
    SqQueue SQ;
    InitQueue(SQ);

    cin.get();
}