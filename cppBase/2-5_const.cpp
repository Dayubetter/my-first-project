//
// Created by dayub on 2026/3/13.
//
#include <iostream>
using namespace std;
int main() {
    typedef char* pstring;
    const pstring cstr = 0; // cstr是指向char的常量指针
    const pstring *ps; // ps是一个指针，他的对象是指向char的常量指针
    // const是对给定类型的修饰。pstring实际上是指向char的指针，因此，const pstring就是指向char的常量指针，而非指向常量字符的指针

}