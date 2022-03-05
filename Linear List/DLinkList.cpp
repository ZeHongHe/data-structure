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
    if (p == NULL | s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 插入： 在 p 节点前插入 s 节点
bool listPriorInsert(DNode *p,DNode *s) {
    if (p == NULL | s == NULL)
        return false;
    s->next = p;
    if (p->prior != NULL)
        p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;
    return true;
}

// 删除：在 p 节点后删除 s 节点
bool deleteNextNode(DNode *p) {
    if (p == NULL)
        return false;
    DNode *s = p->next;
    if (s == NULL)
        return false;
    p->next = s->next;
    if (p->next != NULL)
        p->next->prior = p;
    free(s);
    return true;
}

// 销毁
void destroyList(DLinkList &L) {
    while (L->next != NULL) {
        deleteNextNode(L->next);
    }
    free(L);
    L = NULL;
}

// 判空
bool isEmpty(DLinkList L) {
    return (L->next == NULL);
}

// 长度
int length(DLinkList L) {
    int len = 0;
    DNode *p = L;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 输出
void printList(DLinkList &L) {
    int len = 0;
    DNode *p = L;
    while(p != NULL) {
        printf("The %d node's data is %d \n", len, p->data);
        p = p->next;
        len++;
    }
}

int main() {
    DLinkList L;
    initList(L);
    destroyList(L);
    cin.get();
    return 0;
}