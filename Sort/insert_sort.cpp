#include <iostream>

using namespace std;


void insert_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int j;
            int temp = arr[i];

            /* move elememt greater than temp */
            for (j = i - 1; j >= 0 && temp < arr[j]; j--)
            {
                arr[j + 1] = arr[j];
            }

            /* sorted position for temp */
            arr[j + 1] = temp;
        }
    }
}

int main()
{   
    cin.get();
}