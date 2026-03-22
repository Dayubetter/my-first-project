//
// Created by dayub on 2026/3/22.
//
#include <list>
#include <iostream>

using namespace std;
// 用链表作为底层数据结构实现队列
template <typename E>
class MyLinkedQueue {
private:
    list<E> list_;

public:
    // 向队尾插入元素 O(1)
    void push(const E& e) {
        list_.push_back(e);
    }
    // 从队头删除元素 O(1)
    E pop() {
        E front = list_.front();
        list_.pop_front();
        return front;
    }
    // 查看队头元素 O(1)
    E peek() {
        return list_.front();
    }
    // 返回队列中的元素个数 O(1)
    int size() {
        return list_.size();
    }
};

int main() {
    MyLinkedQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << queue.peek() << endl; // 1
    cout << queue.pop() << endl; // 1
    cout << queue.pop() << endl; // 2
    cout << queue.peek() << endl; // 3

    return 0;
}