#include <iostream>
using namespace std;
struct DNode {
    int data;    // 数据域
    struct DNode *prior, *next;    // 前驱和后继
};

typedef struct DNode DNode;
typedef struct DNode *DLinkList;

// 初始化
bool initList(DLinkList &L) {
    L = (DNode *)malloc(sizeof(DNode));    // 分配一个头节点
    if (L == NULL)
        return false;
    L->prior = NULL;    // 头节点的 prior 永远指向 NULL
    L->next = NULL;    // 头节点的 next 暂时指向 NULL
    return true;
}

// 插入： 在 p 节点后插入 s 节点
bool listInsert(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}



// 判空
bool isEmpty(DLinkList L) {
    return (L->next == NULL);
}

int main() {
    DLinkList L;
    initList(L);
    
    system("pause");
    return 0;
}