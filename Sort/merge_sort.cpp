#include <iostream>


int *arr_copy;


void merge(int *arr, int lower, int middle, int upper)
{
    int i, j, k;
    for (i = lower; i <= upper; i++)
    {
        arr_copy[i] = arr[i];
    }

    for (i = lower, j = middle + 1, k = i; i <= middle && j <= upper; k++)
    {
        if (arr_copy[i] <= arr_copy[j])
        {
            arr[k] = arr_copy[i++];
        }
        else
        {
            arr[k] = arr_copy[j++];
        }
    }

    while (i <= middle) arr[k++] = arr_copy[i++];
    while (j <= middle) arr[k++] = arr_copy[j++];
}

void merge_sort(int *arr, int lower, int upper)
{
    if (lower < upper)
    {
        int middle = (lower + upper) / 2;
        merge_sort(arr, lower, middle - 1);
        merge_sort(arr, middle + 1, upper);
        merge(arr, lower, middle, upper);
    }
}

void display(int *arr, int len)
{
    for (int i = 0; i < len; i ++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}


int main()
{
    std::cin.get();
}