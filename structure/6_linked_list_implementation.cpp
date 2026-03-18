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
