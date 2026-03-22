//
// Created by dayub on 2026/3/22.
//

#include <iostream>
#include <deque>

// 环形数组实现队列
template <typename E>
class MyArrayQueue {
private:
    CycleArray<E> arr;

public:
    MyArrayQueue() {
        arr = CycleArray<E>();
    }

    void push(E t) {
        arr.addLast(t);
    }

    E pop() {
        return arr.removeFirst();
    }

    E peek() {
        return arr.getFirst();
    }

    int size() {
        return arr.size();
    }
};