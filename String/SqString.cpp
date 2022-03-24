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

// 比较： 若 S > T, 返回值 > 0; 若 S = T, 则返回值 = 0;若 S < T, 则返回值 < 0
bool StrCompare(SqString S, SqString T) {
    for (int i = 1; i <= S.len && i <= T.len; i++) {
        if (S.ch[i] != T.ch[i])
            return (S.ch[i] - T.ch[i]);
    }
    // 若扫描过的所有字符串都相同，则返回两字符串的长度差
    return (S.len - T.len);
}

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
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.len = len;
    return true;
}

// 串拼接
void Concat(SqString &S, SqString ConcatS1, SqString ConcatS2) { }

// 定位
int Index(SqString S, SqString T) {
    int i = 1;
    SqString Sub;    // 用于暂存子串
    while( i <= S.len - T.len + 1) {
        SubString(Sub, S, i, T.len);
        if   (StrCompare(Sub, T) != 0) ++i;
        else return i;    // 返回子串在主串中的位置
    }
    return 0;    // S 中不存在与 T相同的字串
}

// 朴素模式匹配 (主串 S， 模式串 T)
int Index_Normal(SqString S, SqString T) {
    int k = 1;        // 待匹配的字串在主串中的数组下标
    int i = k;        // 主串的数组下标
    int j = 1;        // 模式串的数组下标
    while(i <= S.len && j <= T.len) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;      // 继续比较后继字符
        } else {
            k++;
            i = k;
            j = 1;
        }
    }
    if (j > T.len)    // 若是因为主串长度不足而退出 while 循环的话， j < T.len
        return k;
    else 
        return 0;
}

// 求模式串 T 的 next 数组
void GetNext(SqString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.len) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

// 求模式串 T 的 nextval 数组
void GetNextval(SqString T, int nextval[]) {
    int next[T.len + 1];
    GetNext(T, next);
    nextval[1] = 0;
    for (int j = 2; j <= T.len; j++) {
        if (T.ch[next[j]] == T.ch[j])
            nextval[j] = nextval[next[j]];
        else 
            nextval[j] = next[j];
    }
}

// KMP 模式匹配: 时间复杂度 O(m + n)
int Index_KMP(SqString S, SqString T) {
    int i = 1, j = 1;

    int next[T.len + 1];
    GetNext(T, next);

    // int nextval[T.len + 1];
    // GetNextval(T, nextval);

    while(i <= S.len && j <= T.len) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;                  // 主串的 i 指针不回溯
            ++j;                  // 继续比较后继字符
        } else {
            j = next[j];          // 模式串的 j 指针按 next 返回，相当于模式串相对于主串向右移
        }
    }
    if (j > T.len)
        return i - T.len;         // 匹配成功
    else
        return 0;                 // 匹配失败
}

// 清空
void ClearString(SqString &S) {
    for (int i = 1; i <= S.len; i++)
        S.ch[i] = '\0';
}

// 销毁
void DestroyString(SqString &S) { }


int main() {

    cin.get();
}