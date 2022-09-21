#include <iostream>
#include <cassert>

#define NDEBUG

struct DjSet
{
    int *set;
    int size;
};

typedef struct DjSet *DjSet;

void init_set(DjSet &S, int size)
{
    S = (DjSet)malloc(size * sizeof(int));
    assert(S != nullptr);

    S->size = size;

    /* "-1" means it hasn't parent. */
    for (int i = 0; i < size; i++)
    {
        S->set[i] = -1;
    }
}

/* Vanilla union */
void union_set(DjSet &S, int x, int y)
{
    int x_root = find(S, x);
    int y_root = find(S, y);

    if (x_root != y_root) S->set[y_root] = x_root;
}

/* Vanilla find */
int find(DjSet S, int index)
{
    while (S->set[index] >= 0) index = S->set[index];

    return index;
}

/* union by size ver. */
void union_by_size(DjSet &S, int x, int y)
{
    int x_root = find(S, x);
    int y_root = find(S, y);

    if(x_root == y_root) return;	
    	
  	if(S->set[y_root] > S->set[x_root])
    {	
      	S->set[x_root] += S->set[y_root];
      	S->set[y_root] = x_root;
    }
    else
    {
	    S->set[y_root] += S->set[x_root];
      	S->set[x_root] = y_root;
    }	
}

/* find with path splitting ver. */
int find_with_path_split(DjSet &S, int index)
{
    int root = index;
    while (S->set[root] >= 0) root = S->set[root];

    while (index != root)
    {
        int temp = S->set[index];
        S->set[index = root];
        index = temp;
    }

    return root;
}

int main()
{
    std::cin.get();
}