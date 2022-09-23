#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;
}

void bubble_sort(int *arr, int len)
{
    bool flag;
    for (int i = 0; i < len; i++)
    {
        flag = false;
        for (int j = len - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                flag = true;
            }
        }
        /* if no swap in this turn, array is ordered. */
        if (!flag) return;
    }
}

int main()
{
    std::cin.get();
}