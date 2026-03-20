//
// Created by dayub on 2026/3/18.
//
#include <iostream>
#include <string>
#include <stdexcept>
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

        Node(E value) : val(value), next(nullptr), prev(nullptr) {
            cout<<"Node(){}"<<endl;
        }
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
        cout<<"MyLinkedList(){}"<<endl;
    }

    ~MyLinkedList() {
        while (size > 0) {
            removeFirst();
        }
        delete head;
        delete tail;
        cout<<"MyLinkedList()~"<<endl;
    }

    // ****** 增 *****
    void addLast(E e) {
        Node* newNode = new Node(e);
        Node* temp = tail->prev;

        temp->next = newNode;
        newNode->prev = temp;
        // temp <-> newNode

        newNode->next = tail;
        tail->prev = newNode;
        // temp <-> newNode <-> tail
        size++;
    }

    void addFirst(E e) {
        Node* newNode = new Node(e);
        Node* temp = head->next;
        // head <-> temp
        temp->prev = newNode;
        newNode->next = temp;
        // newNode <-> temp

        head->next = newNode;
        newNode->prev = head;
        // head <-> newNode <-> temp
        size++;
    }

    void add(int index, E e) {
        checkPositionIndex(index);
        if (index == size) {
            addLast(e);
            return;
        }
        // 找到index对应的Node
        Node* cur = getNode(index);
        Node* temp = cur->prev;
        // temp <-> cur

        // 新要插入的Node
        Node* newNode = new Node(e);
        temp->next = newNode;
        newNode->prev = temp;
        // temp <-> newNode

        newNode->next = cur;
        cur->prev = newNode;
        // temp <-> newNode <-> cur
        size++;
    }

    // ***** 删 *****
    E removeFirst() {
        if (size < 1) {
            throw out_of_range("List is empty");
        }
        // 虚拟节点的存在是我们不用考虑空指针的问题
        Node* toDelete = head->next;
        Node* temp = toDelete->next;
        // head <-> toDelete <-> temp
        head->next = temp;
        temp->prev = head;

        E val = toDelete->val;
        delete toDelete;
        // head <-> temp
        size--;
        return val;
    }

    E removeLast() {
        if (size < 1) {
            throw out_of_range("List is empty");
        }
        Node* toDelete = tail->prev;
        Node* temp = toDelete->prev;
        // temp <-> toDelete <-> tail
        temp->next = tail;
        tail->prev = temp;
        // temp <-> tail
        E val = toDelete->val;
        toDelete->prev = nullptr;
        toDelete->next = nullptr;
        delete toDelete;
        // temp <-> tail
        size--;
        return val;
    }

    E remove(int index) {
        checkElementIndex(index);
        // 找到index 对应的Node
        Node* toDelete = getNode(index);
        Node* prev = toDelete->prev;
        Node* next = toDelete->next;
        // prev <-> toDelete <-> next
        prev->next = next;
        next->prev = prev;
        E val = toDelete->val;
        toDelete->prev = nullptr;
        toDelete->next = nullptr;
        delete toDelete;
        // prev <-> next
        size--;
        return val;
    }

    // ***** 查 *****
    E get(int index) {
        checkElementIndex(index);
        Node* toGet = getNode(index);
        return toGet->val;
    }

    E getFirst() {
        if (size < 1) {
            throw out_of_range("List is empty");
        }
        return head->next->val;
    }

    E getLast() {
        if (size < 1) {
            throw out_of_range("List is empty");
        }
        return tail->prev->val;
    }

    // ***** 改 *****
    E set(int index, E val) {
        checkElementIndex(index);
        Node* toSet = getNode(index);
        E oldVal = toSet->val;
        toSet->val = val;
        return oldVal;
    }

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
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.addFirst(0);
    list.add(3,33);
    list.display();
    list.removeFirst();
    list.display();
    list.removeLast();
    list.display();
    list.remove(1);
    list.display();
    int first = list.getFirst();
    int last = list.getLast();
    int index0 = list.get(0);
    int index1 = list.get(1);
    cout << first << last << index0 << index1 << endl;
    cout<<"========"<<endl;
    list.set(0,11);
    list.display();
    int index99 = list.get(99);
    cout << index99 << endl;
    cout << list.getSize() << endl;
    cout << list.isEmpty() << endl;
    return 0;
}