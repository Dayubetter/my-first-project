//
// Created by dayub on 2026/3/18.
//
#include <iostream>
using namespace std;

// 关键点一、同时持有头尾节点的引用，尾部添加就可以O(1)
// 关键点二、虚拟头尾节点  无论链表是否为空，这两个节点都存在
//      dummyHead <-> 1 <-> 2 <-> 3 <-> dummyTail  都只从中间插入
//      对于单链表，虚拟头结点有一定的简化作用，但虚拟尾节点没有太大作用
// 关键点三、内存泄露

template<typename E>
class MyLinkedList {
    struct Node {
        E val;
        Node* next;
        Node* prev;

        Node(E value) : val(value), next(nullptr), prev(nullptr) {}
    };
    // 虚拟头尾节点
    Node* head;
    Node* tail;
    int size;

public:
    // 初始化虚拟头尾节点  head ... tail
    MyLinkedList() {
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~MyLinkedList() {
        while (size > 0) {
            removeFirst();
        }
        delete head;
        delete tail;
    }

    // ****** 增 *****
    void addLast(E e) {}

    void addFirst(E e) {}

    void add(int index, E e) {}

    // ***** 删 *****
    E removeFirst() {}

    E removeLast() {}

    E remove(int index) {}

    // ***** 查 *****
    E get(int index) {}

    E getFirst() {}

    E getLast() {}

    // ***** 改 *****
    E set(int index, E val) {}

    // **** 工具函数 ****
    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void display() {
        cout << "size = " << size << endl;
        for (Node* p = head->next; p != tail; p = p->next) {
            cout << p->val << " <-> ";
        }
        cout << "nullptr" << endl;
        cout << endl;
    }

private:
    Node* getNode(int index) {
        checkElementIndex(index);
        Node* p = head->next;
        // TODO:可以优化，通过index判断从head还是tail开始遍历
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p;
    }

    bool isElementIndex(int index) const {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) const {
        return index >= 0 && index <= size;
    }

    // 检查index索引位置是否可以存在元素
    void checkElementIndex(int index) const {
        if (!isElementIndex(index))
            throw out_of_range("Index: " + to_string(index) + ",size: " + to_string(size));
    }

    // 检查index 索引位置是否可以添加元素
    void checkPositionIndex(int index) const {
        if (!isPositionIndex(index))
            throw out_of_range("Index: " + to_string(index) + ",size: " + to_string(size));
    }

};

int main() {
    MyLinkedList<int> list;
    list.display();
    cout << list.getSize() << endl;
    cout << list.isEmpty() << endl;
    return 0;
}