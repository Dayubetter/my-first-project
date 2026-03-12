//
// Created by dayub on 2026/3/13.
//
#include <iostream>
using namespace std;

// 静态局部变量保存上一次函数调用时的状态
// 0, 1, 1, 2, 3, 5, 8, 13, 21...
long long
next_fib(void) {
    static long long a =0;
    static long long b =1;
    long long tmp =a;
    a = b;
    b = tmp + a;
    return a;
}

// 递归
// Fibonacci 数列，输出第n项的值

/**        |-                 0,n = 0
 * F(n) =  |                  1,n = 1
 *         |_     F(n-2)+F(n-1),n >= 2
 */

long long
fib(int n) {
    if (n==0 || n==1) {
        return n;
    }
    return fib(n-1) + fib(n-2);;
}

// 递归大量重复计算 动态规划
// 顺序求解子问题,并且将子问题的解保存起来，从而避免重复计算,最终求解到大问题
// 对于求解Fibnacci数列来说，并不需要保存前面所有项的值，只需要保存最近两项即可
long long
fib_dp(int n) {
    if (n==0 || n==1) {
        return n;
    }
    long long a = 0,b = 1;
    for (int i =2; i<=n; i++) {
        // 计算fib_dp(i)的值
        long long tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}

// todo

int main() {
    cout << next_fib() << endl;
    cout << next_fib() << endl;
    cout << next_fib() << endl;
    cout << next_fib() << endl;
    cout << "========" << endl;
    cout << fib(4) << endl;
    cout << "========" << endl;
    cout << fib_dp(4) << endl;
    return 0; // exit(EXIT_SUCCESS);
}