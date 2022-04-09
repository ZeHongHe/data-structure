/* circular queuequeue implementation using array */

#include <iostream>
#define MAXSIZE 10
using namespace std;

struct Queue
{
    int *data;
    int head;
    int tail;
    int size;
};

typedef struct Queue queue;

void init_queue(queue &Q)
{
    Q.data = (int *)malloc(MAXSIZE * sizeof(int));

    if (Q.data == NULL) printf("Out of space!");

    Q.head = Q.tail = Q.size = 0;
}

bool isEmpty(queue Q) { return (Q.size == 0); }

bool isFull(queue Q) { return (Q.size == MAXSIZE); }

int size(queue Q) { return Q.size; }

void en_queue(queue &Q, int e)
{
    if (isFull(Q)) printf("Queue is full!");

    Q.data[Q.tail] = e;
    Q.tail = (Q.tail + 1) % MAXSIZE;

    Q.size++;
}

void de_queue(queue &Q, int &e)
{
    if (isEmpty(Q)) printf("Queue is empty!");

    e = Q.data[Q.head];
    Q.head = (Q.head + 1) % MAXSIZE;

    Q.size--;
}

int main()
{
    cin.get();
}
