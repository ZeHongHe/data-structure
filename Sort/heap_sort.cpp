#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void build_max_heap(int *arr, int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        adjust_root(arr, i, len);
    }
}

void adjust_root(int *arr, int root, int len)
{
    arr[0] = arr[root];
    for (int i = 2 * root; i <= len; i *= 2)
    {
        if (i < len && arr[i] < arr[i + 1]) i++;
        if (arr[0] >= arr[i])
        {
            break;
        }
        else
        {
            arr[root] = arr[i];
            root = i;
        }
    }
    
    arr[root] = arr[0];
}

void heap_sort(int *arr, int len)
{
    build_max_heap(arr, len);
    for (int i = len; i > 1; i--)
    {
        swap(arr[i], arr[1]);;
        adjust_root(arr, 1, i - 1);
    }
}