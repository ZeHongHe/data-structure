// Stack interface

#include <cstdbool>

struct LNode;

typedef struct LNode node;
typedef struct LNode *stack;

void init_stack(stack);
bool isEmpty(stack);
void destroy_stack(stack);
void push(stack, int);
void pop(stack, &int)
