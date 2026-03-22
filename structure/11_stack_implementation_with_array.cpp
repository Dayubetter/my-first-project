//
// Created by dayub on 2026/3/22.
//
#include <vector>
#include <iostream>
using namespace std;

// 用数组作为底层数据结构实现栈
template <typename T>
class MyArrayStack {
private:
    vector<T> arr_;
public:
    // 向栈顶加入元素 O(1)
    void push (const T& e) {
        arr_.push_back(e);
    }
    // 从栈顶弹出元素 O(1)
    T pop () {
        T topElement = arr_.back();
        arr_.pop_back();
        return topElement;
    }

    // 查看栈顶元素 O(1)
    T peek () {
        return arr_.back();
    }

    // 返回栈中的元素个数 O(1)
    int size() const {
        return arr_.size();
    }
};

