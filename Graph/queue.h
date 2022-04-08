typedef struct node node;
typedef struct Queue *queue;

void init_queue(queue);
void en_queue(queue, int);
int de_queue(queue);
bool is_empty(queue);
