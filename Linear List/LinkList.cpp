#include <iostream>
using namespace std;

struct LNode {
    int data;    // 数据域
    struct LNode *next;  // 后继节点
};

// 简易写法
typedef struct LNode LNode;

// 强调是单链表时，使用 Linklist
// 强调是一个节点时，使用 LNode *
typedef struct LNode *LinkList;

// 初始化：带头节点的单链表
bool initList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));    // 让 L 指向头节点 
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
};

// 尾插法建表
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

// 头插法建表
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

// 按值查找
LNode * locateElem(LinkList &L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

// 按位查找
LNode * GetElem(LinkList L, int i) {
    if (i < 1)
        return L;
    LNode *p;     // p 指向当前扫描到的节点
    int j = 0;    // j 为 p 指向节点的位序
    p = L;        // 令 p 指向第 0 个节点
    while (j < i && p != NULL) {    // 循环找到 i 节点
        p = p->next;
        j++;
    }
    return p;
}

// 插入：按指定节点 p 后插入
bool nodeNextInsert(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *insertNode = (LNode *)malloc(sizeof(LNode));
    if (insertNode == NULL)
        return false;
    insertNode->data = e;
    insertNode->next = p->next;
    p->next = insertNode;
    return true;
}

// 插入：按指定节点 p 前插入
bool nodePriorInsert(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *insertNode = (LNode *)malloc(sizeof(LNode));
    if (insertNode == NULL)
        return false;
    insertNode->next = p->next;
    p->next = insertNode;
    insertNode->data = p->data;
    p->data = e;
    return true;
}

// 插入：按指定位序 i 前插
bool listInsert(LinkList &L, int i, int e) {
    LNode * p = GetElem(L, i - 1);
    return nodeNextInsert(p, e);
}

// 删除：按指定位序 i
bool listDelete(LinkList &L, int i, int &e) {
    LNode *p = GetElem(L, i - 1);
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    LNode *deleteNode = p->next;
    e = deleteNode->data;
    p->next = deleteNode->next;
    free(deleteNode);
    return true;
}

// 删除：按指定节点 deleteNode 删除
bool nodeDelete(LNode *deleteNode) {
    if (deleteNode == NULL)
        return false;
    LNode *p = deleteNode->next;
    deleteNode->data = deleteNode->next->data;
    deleteNode->next = p->next;
    free(deleteNode);
    return true;
}

// 判空
bool isEmpty(LinkList L) {
    return (L->next == NULL);
}

// 长度
int length(LinkList L) {
    LNode *p = L;
    int len = 0;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 输出
void printList(LinkList L) {
    int len = 1;
    LNode *p = L->next;
    while(p != NULL) {
        printf("The %d node's data is %d \n", len, p->data);
        p= p->next;
        len++;
    }
}

int main() {
    LinkList L;

    listHeadInsert(L);
    printList(L);
    
    system("pause");
}