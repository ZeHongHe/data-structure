#include <iostream>

int partition(int *arr, int lower, int upper)
{
    int pivot = arr[lower];
    while (lower < upper)
    {
        while (lower < upper && arr[upper] >= pivot) upper--;
        arr[lower] = arr[upper];
        while (lower < upper && arr[lower] <= pivot) lower++;
        arr[upper] = arr[lower];
    }

    arr[lower] = pivot;
    /* return piovt now position for next partition */
    return lower;
}

void quick_sort(int *arr, int lower, int upper)
{
    if (lower < upper)
    {
        int partition_index = partition(arr, lower, upper);
        quick_sort(arr, lower, partition_index);
        quick_sort(arr, partition_index + 1, upper);
    }
}

int main()
{
    std::cin.get();
}