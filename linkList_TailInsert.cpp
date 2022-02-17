#include <iostream>
using namespace std;

struct LNode {
    int data;
    struct LNode *next;
};

typedef struct LNode LNode;
typedef struct LNode *LinkList;

bool initList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)     // 内存分配失败则返回 false 
        return false;
    L->next = NULL;
    return true;
};

// 尾插法
LinkList listTailInsert(LinkList &L) {
    int e;
    initList(L);
    LNode *p, *r = L;
    scanf("%d", &e);
    while (e != 9999) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = e;
        r->next = p;
        r = p; 
        scanf("%d", &e);
    }
    r->next = NULL;
    return L;
}

// 输出
void printList(LinkList &L) {
    int len = 0;
    LNode *p = L->next;
    while(p != NULL) {
        printf("The %d node's data is %d. \n", len, p->data);
        p = p->next;
        len++;
    }
}

int main() {
    LinkList L;
    listTailInsert(L);
    printList(L);

    system("pause");
    return 0;
}