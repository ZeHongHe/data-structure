struct Node;
struct Queue;

typedef struct Node node;
typedef struct Queue *queue;

void init_queue(queue);
void en_queue(queue, int);
int de_queue(queue);
bool isEmpty(queue);
