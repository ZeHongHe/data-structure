#include <iostream>
#define MAXLEN 255

using namespace std;

struct SqString
{
    char ch[MAXLEN];
    int len;
};
typedef struct SqString String;

void InitString(String &S)
{
    S.len = 0;
}

bool StrAssign(String &AS, String S)
{
    if (S.len > AS.len) return false;

    for (int i = 1; i <= S.len; i++)
    {
        AS.ch[i] = S.ch[i];
    }

    AS.len = S.len;

    return true;
}

/* 若 S > T, 返回值 > 0; 若 S = T, 则返回值 = 0;若 S < T, 则返回值 < 0 */
bool StrCompare(String S, String T)
{
    for (int i = 1; i <= S.len && i <= T.len; i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return (S.ch[i] - T.ch[i]);
        }
    }
    /* 若扫描过的所有字符串都相同，则返回两字符串的长度差 */
    return (S.len - T.len);
}

void StrCopy(String &CS, String S);

bool IsEmpty(String S) { return (S.len == 0); }

int StrLen(String S) { return S.len; }

bool SubString(String &Sub, String S, int pos, int len)
{
    if ((pos + len - 1) > S.len)
    {
        return false;
    }

    for (int i = pos; i < pos + len; i++)
    {
        Sub.ch[i - pos + 1] = S.ch[i];        
    }

    Sub.len = len;

    return true;
}

void Concat(String &S, String ConcatS1, String ConcatS2);

int Index(String S, String T)
{
    int i = 1;
    String Sub;

    while( i <= S.len - T.len + 1)
    {
        SubString(Sub, S, i, T.len);
        if   (StrCompare(Sub, T) != 0) ++i;
        else return i;    /* 返回子串在主串中的位置 */
    }
    return 0;    /* S 中不存在与 T相同的字串 */
}

// 朴素模式匹配 (主串 S， 模式串 T)
int Index_Normal(String S, String T)
{
    int k = 1;        // 待匹配的字串在主串中的数组下标
    int i = k;        // 主串的数组下标
    int j = 1;        // 模式串的数组下标

    while(i <= S.len && j <= T.len)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;      // 继续比较后继字符
        }
        else
        {
            k++;
            i = k;
            j = 1;
        }
    }

    /* 若是因为主串长度不足而退出 while 循环的话， j < T.len */
    if (j > T.len)
        return k;
    else
        return 0;
}

/* 求模式串 T 的 next 数组 */
void GetNext(String T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;

    while(i < T.len)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

/* 求模式串 T 的 nextval 数组 */
void GetNextval(String T, int nextval[])
{
    int next[T.len + 1];
    GetNext(T, next);

    nextval[1] = 0;

    for (int j = 2; j <= T.len; j++)
    {
        if (T.ch[next[j]] == T.ch[j])
        {
            nextval[j] = nextval[next[j]];
        }
        else
        {
            nextval[j] = next[j];
        }
    }
}

/* KMP 模式匹配: 时间复杂度 O(m + n) */
int Index_KMP(String S, String T)
{
    int i = 1, j = 1;

    int next[T.len + 1];
    GetNext(T, next);

    // int nextval[T.len + 1];
    // GetNextval(T, nextval);

    while(i <= S.len && j <= T.len)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;                  // 主串的 i 指针不回溯
            ++j;                  // 继续比较后继字符
        }
        else
        {
            j = next[j];          // 模式串的 j 指针按 next 返回，相当于模式串相对于主串向右移
        }
    }
    if (j > T.len)
        return i - T.len;
    else
        return 0;
}

void ClearString(String &S)
{
    for (int i = 1; i <= S.len; i++)
    {
        S.ch[i] = '\0';
    }
}

void DestroyString(String &S);

int main()
{
    cin.get();
}