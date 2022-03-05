#include <iostream>
using namespace std;

struct LNode {
    int data;
    struct LNode *next;
};

typedef struct LNode LNode;
typedef struct LNode *LinkList;

bool initList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)    // 内存分配失败则返回 false 
        return false;
    L->next = NULL;
    return true;
}

LinkList listHeadInsert(LinkList &L) {
    int e;
    LNode *p; 
    initList(L);
    scanf("%d", &e);
    while ( e != 9999) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = e;
        p->next = L->next;
        L->next = p;    // 将新节点 p 插入表中
        scanf("%d", &e);
    }
    return L;
}

void printList(LinkList L) {
    int len = 0;
    LNode *p = L->next;
    while (p != NULL) {
        printf("The %d node's data is %d. \n", len, p->data);
        p = p->next;
        len++;
    }
}

int main() {
    LinkList L;
    listHeadInsert(L);
    printList(L);

    system("pause");
    return 0;
}