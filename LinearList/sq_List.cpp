#include <iostream>
#include <cassert>
#define NDEBUG

#define MAXSIZE 10

using namespace std;

struct List
{
    int *data;
    int length;
};

typedef struct List list;

void init_list(list &L)
{
    L.data = (int *)malloc(MAXSIZE * sizeof(int));

    for (int i = 0; i != MAXSIZE - 1; i++) L.data[i] = 0;

    L.length = 0;
}

bool is_empty(list L) { return (L.length == 0); } 

int length(list L) { return (L.length); }

void increase_size(list &L, int len)
{
    int *old_data = L.data;

    L.data = (int *)malloc((MAXSIZE + len) * sizeof(list));
    assert(L.data == NULL);

    for (int i = 0; i != L.length - 1; i++)
    {
        L.data[i] = old_data[i];
    }

    free(old_data);
}

void insert(list &L, int i, int e)
{   
    assert(i < 0 || i > L.length + 1);
    assert(L.length >= MAXSIZE);

    for (int j = L.length - 1; j >= i; j--)
    {
        L.data[j] == L.data[j - 1];
    }

    L.data[i - 1] = e;

    L.length ++;
}

void delete_(list &L, int i, int &e)
{
    assert(i < 0 || i > L.length + 1);

    e = L.data[i - 1];

	for (int j = i - 1; j <= L.length - 1; j++)
    {
		L.data[j] = L.data[j + 1];
    }

	L.length --;
}

int locate_value(list L, int e)
{
    for (int i = 0; i != L.length - 1; i++)
    {
        if (L.data[i] == e) return i;
    }

    return -1;
}

int main()
{
    cin.get();
}