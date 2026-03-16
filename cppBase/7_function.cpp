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
/**
 * 问题有递归结构：大问题可以分解为若干个子问题，子问题的求解方式和大问题一致，只是问题规模不一致；子问题的解可以合并成大问题的解
 *
 * 如果不存在重复计算问题，且递归的层次不是很深时，就可以使用递归。
 *
 * (1)边界条件 (2)递归公式
 *
 */
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

// 汉诺塔
/*
 * 有三根杆子ABC。A杆上有N个（N>1）穿孔圆盘，盘的尺寸由上到下以此变小。要求按下列规则将所有圆盘移至C杆
 * 1.每次只能移动一个圆盘
 * 2.大盘不能叠在小盘上面
 *  问：最少需要移动多少次？如何移动？
 *
 *  f(n)= 移动n个盘子的最少次数
 *  移动思路（关键三步）
 *  1.先把上面n−1个盘子从起点移到辅助柱：需要f(n−1)次
 *  2.再把最底下那1个最大盘子从起点移到目标柱：需要1次
 *  3.最后把那n−1个盘子从辅助柱移到目标柱：又要f(n−1)次
 *  f(n)=2 * f(n-1) +1  ==>  f(n)=2^n - 1
 */
void hanoi(int n, char start, char middle, char target) {
    // 边界条件
    if (n==1) {
        cout<< start <<"->" << target<<endl;
        return;
    }
    // 递归公式
    // 1.将上面n-1个盘子，从start经过target，移动到middle
    hanoi(n-1,start,target,middle);
    // 2.将最大的盘子，从start移动到target
    cout << start <<"->" << target<<endl;
    // 3.将上面n-1个盘子，从middle经过start，移动到target
    hanoi(n-1,middle,start,target);
}

// 约瑟夫环问题
/*
 * 约瑟夫环是一个数学的应用问题：已知 n 个人 (以编号1，2，3, ..., n 分别表示) 围坐在一张圆桌周围。
 * 从编号为 1 的人开始，每两个人出列一个人，直至只剩一个人。
 * 问：最终剩下的这个人的编号是多少？
 */

// 循环链表  时间复杂度:O(n) 空间复杂度O(n)
// 1.定义循环链表节点结构
struct Node {
    int number;  // 存储人员编号
    Node* next;
    Node(int num) : number(num), next(nullptr) {}
};

// 2.约瑟夫环 循环链表
int josephus(int n) {
    // 边界条件 ：1个人直接存活
    if (n == 1) return 1;

    // ====1.创建循环链表====
    Node* head = new Node(1);  // 创建1号节点
    Node* tail = head;              // 尾指针初始指向头节点

    // 循环创建 2 ~ n 号节点
    for (int i = 2; i <= n; ++i) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    tail->next = head; // 尾节点指向头节点，形成环形链表
    // ====2.模拟淘汰====
    Node* pre = tail; // 前驱指针：初始指向最后一个节点
    Node* delNode;    // 待删除的节点

    // 循环淘汰，直到链表只剩下1个节点，即自己指向自己
    while (pre->next != pre) {
        // 每2个人淘汰一个 -》 移动1位，找到要删除的节点
        pre = pre->next;
        /**
         * 每k人，移动k-1次
         * for (int i = 1; i < k; ++i) {
         *      pre = pre->next;
         * }
         */
        delNode = pre->next;
        pre->next = delNode->next;
        cout << "delete node number :" << delNode->number << endl;
        delete delNode; // 释放节点内存
    }
    // 最后剩余的节点
    int result = pre->number;
    delete pre; // 释放最后一个节点
    return result;
}


// 递归  时间复杂度：O(log n)  空间复杂度 O(log n)
int joseph(int n) {
    // 边界条件
    if (n==1 || n==2) {
        return 1;
    }
    // 递归公式
    if (n & 0x1) {
        return 2*joseph(n >> 1) + 1;
    }
    return 2 * joseph(n >> 1) - 1;
}

int main() {
    cout << next_fib() << endl;
    cout << next_fib() << endl;
    cout << next_fib() << endl;
    cout << next_fib() << endl;
    cout << "========" << endl;
    cout << fib(4) << endl;
    cout << "========" << endl;
    cout << fib_dp(4) << endl;
    cout << "====hannoi====" << endl;
    int n = 3;
    cout << "move " << (1<<n) - 1 << " times" << endl;
    hanoi(n,'A','B','C');
    cout << "====joseph====" << endl;
    int n_joseph = 10;
    cout <<"last save number:" << joseph(n_joseph) << endl;
    cout <<"last save number: \n" << josephus(n_joseph) << endl;
    return 0; // exit(EXIT_SUCCESS);
}