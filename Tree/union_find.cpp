#include <iostream>

class union_find
{
private:
    int *size;
    int *parent;
    int cnt;
public:
    union_find(int n);
    ~union_find();

    bool validate(int p);
    int count();
    int find(int p);
    bool isConnected(int p, int q);
    void Union(int p, int q);
};

union_find::union_find(int n)
{
    cnt = n;
    parent = (int *)malloc(n * sizeof(int));
    size = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < cnt; i++)
    {
        parent[i] = i;
        size[i] = 0;
    }
}

union_find::~union_find()
{
    free(parent);
    free(size);
}

bool union_find::validate(int p)
{
    if (p > cnt || p < 0) return false;

}

int union_find::count() { return cnt; }


int union_find::find(int p)
{
    validate(p);
    while (p != parent[p])
        p = parent[p];
    return p;
}

bool union_find::isConnected(int p, int q)
{
    return find(p) == find(q);
}

void union_find::Union(int p, int q)
{
    int p_root = find(p);
    int q_root = find(q);

    if (size[p_root] > size[q_root])
    {
        parent[q_root] = p_root;
        size[p_root] += size[q_root];
    }
    else
    {
        parent[p_root] = q_root;
        size[q_root] += size[p_root];
    }

    cnt--;
}


int main()
{
    union_find set(5);

    set.Union(0, 1);
    set.Union(1, 2);

    set.~union_find();

    std::cin.get();
}
