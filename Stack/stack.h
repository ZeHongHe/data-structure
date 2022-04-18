// Stack interface

#include <cstdbool>

struct node;

typedef struct node node;
typedef struct node *stack;

void init_stack(stack);
bool isEmpty(stack);
void destroy_stack(stack);
void push(stack, int);
void pop(stack, int)
