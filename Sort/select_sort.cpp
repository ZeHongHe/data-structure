#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void select_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min]) min = j;
        }

        if (min != i) swap(arr[i], arr[min]);
    }
}

int main()
{
    std::cin.get();
}