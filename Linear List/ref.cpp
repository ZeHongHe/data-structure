/* 什么时候需要传入参数的引用？
 * 对参数的修改结果需要带回来时
 */

#include <iostream>
using namespace std;

void test(int &x) {
    x = 1024;
    printf("In test function, x = %d\n", x);
}

int main(){
    int x;
    scanf("%d", &x);
    printf("before callback test, x = %d\n", x);
    test(x);
    printf("after callback test, x = %d\n", x);
    return 0;
}