#include <iostream>
#define initSize 10   // 默认的最大长度
using namespace std;

// 定义顺序表
struct seqList {
    int *data;    // 动态分配数组的指针
    int maxSize;    // 顺序表的最大容量
    int length;    // 顺序表当前长度
};

// 初始化
void initList(seqList &L) {
    L.data = (int *)malloc(sizeof(int) * initSize);
    L.length = 0;
    L.maxSize = initSize;
}

// 增加长度
void increaseSize(seqList &L, int len) {
    int *pdata = L.data;
    L.data = (int *)malloc(sizeof(int) * (L.maxSize + len));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = pdata[i];
    }
    L.maxSize = L.maxSize + len;
    free(pdata);
}

// 插入
bool listInsert(seqList &L, int i, int e) {
    if (i < 0 || i > L.length + 1)
        return false;
    if (L.length >= L.maxSize)
        return false;
    for (int j = L.length - 1; j >= i; j--)    // 将第 i 个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length ++;
    return true;
}

// 删除：被删元素赋值给 e
bool listDelete(seqList &L, int i, int &e) {
    if (i < 0 || i > L.length)
        return false;
	e = L.data[i - 1];
	for (int j = i - 1; j <= L.length - 1; j++)
		L.data[j] = L.data[j + 1];
	L.length --;
    return true;
}

// 按值查找：返回位序 i + 1
int locateElem(seqList L, int e){
	for (int j = 0; j <= L.length; j++) {
		if (L.data[j] == e) 
			return j + 1;
	}
	return 0;
}

// 按位查找：返回元素 e
int getElem(seqList L, int i) {
	return L.data[i - 1];
}


// 获取长度
int length(seqList L) {
	return L.length;
}

// 打印
void printList(seqList &L) {
    for (int i = 0; i < L.length - 1; i++) 
        printf("data[%d] = %d\n", i + 1, L.data[i]);
}

// 判空
bool isEmpty(seqList &L) {
    if (L.length == 0) {
        return true;
    } else {
        return false;
    }
}


int main() {
    seqList L;
    initList(L);

    for (int i = 0; i <= 10; i++) {
        listInsert(L, i, i);
    }

    increaseSize(L, 10);
    
    for (int i = 10; i <= 20; i++) {
        listInsert(L, i, i);
    }

    printList(L);
    system("pause");
    
    return 0;
}