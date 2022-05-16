#include <iostream>
using namespace std;

int Fibonacci(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
}

int main()
{
    int num = 10;
    printf("%d 's Fibonacci sequence result is %d\n", num, Fibonacci(num));

    cin.get();
}