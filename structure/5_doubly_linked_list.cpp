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

void printDoublyLinkedList(DoublyListNode* head) {
    DoublyListNode* cur = head;
    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << endl;
}

// 双链表的遍历/查找/修改
// 对于双链表的遍历和查找，从头节点或者尾节点开始向前向后遍历 最坏时间复杂度O(1) 访问和修改可以根据靠近头还是尾，选遍历方向
void searchDoublyLinkedList() {
    DoublyListNode* head = createDoublyLinkedList({1,2,3,4,5});
    DoublyListNode* tail = nullptr;

    // 从头节点向后遍历双链表
    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data << " ";
        tail = cur;
    }
    cout << endl;
    // 从尾节点向前遍历双链表
    for (DoublyListNode* cur = tail; cur != nullptr; cur = cur->prev) {
        cout << cur->data << " ";
    }
    cout << endl;
}

// 增加
// 头部插入元素，O(1) 需要调整新节点和源节点
void headAdd() {
    DoublyListNode* head = createDoublyLinkedList({1,2,3,4,5});
    // 在双链表头部插入新节点99
    DoublyListNode* newHead = new DoublyListNode(99);
    newHead->next = head;
    head->prev = newHead;
    head = newHead;
    printDoublyLinkedList(head);
}

// 尾部插入新元素 O(n) 需要先遍历到尾节点
void lastAdd() {
    DoublyListNode* head = createDoublyLinkedList({1,2,3,4,5});
    DoublyListNode* tail = head;
    // 先走到链表的最后一个节点
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    // 在双链表尾部插入新节点99
    DoublyListNode* newNode = new DoublyListNode(99);
    tail->next = newNode;
    newNode->prev = tail;
    // 更新尾节点引用
    tail = newNode;
    printDoublyLinkedList(head);
}

// 在双链表中间插入元素 O(n)，需先遍历链表位置
void midAdd() {
    DoublyListNode* head = createDoublyLinkedList({1,2,3,4,5});
    // 在索引3，第四个节点处插入99
    // 想要插入到索引3:第4个节点
    // 需要操作索引2:第三个节点的指针
    DoublyListNode* cur = head;
    for (int i = 0 ; i < 2; i++) {
        cur = cur->next;
    }
    // 组装新节点
    DoublyListNode* newNode = new DoublyListNode(99);
    newNode->next = cur->next;
    newNode->prev = cur;
    // 插入新节点
    cur->next->prev = newNode;
    cur->next = newNode;
    printDoublyLinkedList(head);
}

// 删除 TODO

int main() {
    searchDoublyLinkedList();
    headAdd();
    lastAdd();
    midAdd();
    return 0;
}