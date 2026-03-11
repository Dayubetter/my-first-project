//
// Created by dayub on 2026/3/8.
//
#include <iostream>
#include <vector>
using namespace std;
// 单链表节点
class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int x)
        :val(x),next(NULL)
    {}
};

// 输入一个数组，转化为一条单链表
ListNode* createLinkList(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1;i < arr.size();i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printLinkList(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

void lookupUpdata() {
    // 查改 时间复杂度O(n) ,n是链表长度，只能for遍历从头往后找
    ListNode* head = createLinkList({1,2,3,4,5});

    printLinkList(head);
}

// 增加
void headAdd() {
    // 头插法 时间复杂度O(1)
    ListNode* head = createLinkList({1,2,3,4,5});
    // 头部插一个新节点0
    ListNode* newNode = new ListNode(0);
    newNode->next = head;
    head = newNode;

   printLinkList(head);
}

void lastAdd() {
    // 尾插法 时间复杂度为O(n)
    ListNode* head = createLinkList({1,2,3,4,5});
    ListNode* newNode = new ListNode(0);
    ListNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    // 现在cur为链表最后一个节点，在cur后面插入新节点
    cur->next = newNode;
    printLinkList(head);
}

void midAdd() {
    // 链表中间插入新元素 O(n) 因为要先找到插入位置的前驱节点
    ListNode* head = createLinkList({1,2,3,4,5});

    // 在第三个节点后插入一个新节点0
    // 先找到前驱节点，即第3个节点
    ListNode* cur = head;
    for (int i = 0;i < 2;i++) {
        cur = cur->next;
    }
    // cur指向第三个
    // 组装新节点的后驱指针
    ListNode* newNode = new ListNode(0);
    newNode->next = cur->next;
    // 插入新节点
    cur->next = newNode;
    printLinkList(head);
}

// 删除
void midRemove() {
    // 删除中间一个节点 需要找到被删除节点的前驱节点，时间复杂度O(n)
    ListNode* head = createLinkList({1,2,3,4,5});
    // 删除第三个,要操作前驱节点
    ListNode* cur = head;
    for (int i = 0;i < 1;i++) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    printLinkList(head);
}

void lastRemove() {
    // 找到倒数第二个 把next置为null 时间复杂度未O(n) 因为遍历到倒数第二个
    ListNode* head = createLinkList({1,2,3,4,5});
    ListNode* cur = head;
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }
    // 此时cur指向倒数第二个
    // 把尾节点从链表删除
    cur->next = nullptr;
    printLinkList(head);
}

void headRemove() {
    // 直接头节点后移，O(1)
    ListNode* head = createLinkList({1,2,3,4,5});
    ListNode* cur = head;
    head = cur->next;
    printLinkList(head);
}

int main() {
    lookupUpdata();
    headAdd();
    lastAdd();
    midAdd();
    midRemove();
    lastRemove();
    headRemove();
}

