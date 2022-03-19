#include <iostream>
#define MAXLEN 255
using namespace std;

// 字符串：从数组下标 1 开始储存字符
typedef struct SqString {
    char ch[MAXLEN];
    int len;
} SqString;

// 初始化
void InitString(SqString &S) {
    S.len = 0;
}

// 赋值
bool StrAssign(SqString &AS, SqString S) {
    if (S.len > AS.len)
        return false;
    for (int i = 1; i <= S.len; i++)
        AS.ch[i] = S.ch[i];
    AS.len = S.len;
    return true;
}

// 比较
void StrCompare(SqString S, SqString T) { }

// 复制
void StrCopy(SqString &CS, SqString S) { }

// 判空
bool IsEmpty(SqString S) {
    return (S.len == 0);
}

// 获取长度
int StrLen(SqString S) {
    return S.len;
}

// 获取指定字串
bool SubString(SqString &Sub, SqString S, int pos, int len) {
    // 判断子串范围越界
    if ((pos + len - 1) > S.len)
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub[i - pos + 1] = S.ch[i];
    Sub.len = len;
    return true;
}

// 串拼接
void Concat(SqString &S, SqString ConcatS1, SqString ConcatS2) { }

// 定位
void index(SqString S, SqString Sub) { }

// 清空
void ClearString(SqString &S) { }

// 销毁
void DestroyString(SqString &S) { }


int main() {
    SqString S;
    InitString(S);

    cin.get();
}