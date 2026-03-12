//
// Created by dayub on 2026/3/12.
//
#include <iostream>
#include <vector>
using namespace std;

class DoublyListNode {
    public:
    int data;
    DoublyListNode* next;
    DoublyListNode* prev;
    DoublyListNode(int x) : data(x), next(NULL), prev(NULL) {}
};
DoublyListNode* createDoublyLinkedList(const vector<int>& arr) {
    if (arr.empty()) {
        return NULL;
    }
    DoublyListNode* head = new DoublyListNode(arr[0]);
    DoublyListNode* cur = head;
    // for循环迭代创建双链表
    for (int i = 1; i < arr.size(); i++) {
        DoublyListNode* newNode = new DoublyListNode(arr[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
}

// todo