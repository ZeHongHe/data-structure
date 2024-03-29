/* stack implementation using array */

#include <iostream>
#include <cassert>

#define NDEBUG
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

    assert(S.data != NULL);

    S.top = -1;
}

bool isEmpty(stack S) { return (S.top == -1); }

bool isFull(stack S) { return (S.top == MAXSIZE - 1); }

void push(stack &S, int e)
{
    if (!isFull(S))
    {
        S.data[++S.top] = e;
    }
}

void pop(stack &S, int &e)
{
    if (!isEmpty(S))
    {
        e = S.data[S.top--];
    }
}

int main()
{
    cin.get();
}
