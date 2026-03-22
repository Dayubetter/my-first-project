//
// Created by dayub on 2026/3/22.
//

// 队列的基本API
template <typename E>
class MyQueue {
public:
    // 向队尾插入元素，O(1)
    void push (const E& e);
    // 从队头删除元素，O(1)
    E pop();

    // 查看队头元素，O(1)
    E peek() const;
    // 返回队列中的元素个数，O(1)
    int size() const;
};

// 栈的基本API
template <typename E>
class MyStack {
public:
    // 向栈顶插入元素 O(1)
    void push (const E& e);
    // 栈顶删除元素，O(1)
    E pop();
    // 查看栈顶元素 O(1)
    E peek() const;
    // 返回栈中的元素个数 O(1)
    int size() const;
};