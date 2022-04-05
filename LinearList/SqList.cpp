#include <iostream>
#include <cstdlib>
#define maxSize 10    // 定义最大长度

using namespace std;

// 定义顺序表
struct sqList
{
    int data[maxSize];
    int length;
};

// 1. 初始化
void initList(sqList &L) {
    for (int i = 0; i < maxSize - 1; i++)
        L.data[i] = 0;
    L.length = 0;
}

// 3. 插入
bool listInsert(sqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= maxSize) 
        return false;
    for (int j = L.length - 1; j >= i; j--)    // 将第 i 个元素及之后的元素后移
        L.data[j] == L.data[j - 1];
    L.data[i - 1] = e;
    L.length ++;
    return true;
}

// 4. 删除：被删元素赋值给 e
bool listDelete(sqList &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
	e = L.data[i - 1];
	for (int j = i - 1; j <= L.length - 1; j++)
		L.data[j] = L.data[j + 1];
	L.length --;
    return true;
}

// 5. 按值查找：返回位序 i + 1
int locateElem(sqList L, int e){
	int i;
	for (int j = 0; j <= L.length; j++) {
		if (L.data[j] == e) 
			return i + 1;
	}
	return 0;
}

// 6. 按位查找：返回元素 e
int getElem(sqList L, int i) {
	return L.data[i - 1];
}


// 7. 获取长度
int length(sqList L) {
	return L.length;
}

// 8. 打印
void printList(sqList &L) {
    for (int i = 0; i < L.length - 1; i++) 
        printf("data[%d] = %d\n", i + 1, L.data[i]);
}

// 9. 判空
bool isEmpty(sqList &L) {
    if (L.length == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
	sqList L;
    initList(L);

    for (int i = 1; i <= 10; i++) {
		listInsert(L, i - 1, i - 1);
    }
    
    int deleteNumber;
    for (int i = 1; i <= 10; i++) {
		listDelete(L, i - 1, deleteNumber);
    }
    
    printList(L);
    printf("length is %d.\n", length(L));

    cin.get();
}
