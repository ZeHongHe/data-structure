/* stack implementation using array */

#include <iostream>
#define MAXSIZE 10
using namespace std;

struct Stack
{
    int *data;
    int top;
};

typedef struct Stack stack;

void init_stack(stack &S)
{
    S.data = (int *)malloc(MAXSIZE * sizeof(int));

    if (S == NULL) printf("Out of space!");

    S.top = -1;
}

bool isEmpty(stack S) { return (S.top == -1); }

bool isFull(stack S) { return (S.top == MAXSIZE); }

void push(stack &S, int e)
{
    if (isFull(S)) printf("Stack is full!");

    S.data[++S.top] = e;
}

void pop(stack &S, int &e)
{
    if (isEmpty(S)) printf("Stack is empty!");

    e = S.data[S.top--];
}

int main()
{
    cin.get();
}
