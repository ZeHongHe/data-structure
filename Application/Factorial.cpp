#include <iostream>
using namespace std;

int Factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return  num * Factorial(num - 1);
    }
}

int main() {
    int num = 10;
    printf("%d 's factorial is %d.\n", num, Factorial(num));
    cin.get();
}