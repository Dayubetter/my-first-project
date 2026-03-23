//
// Created by dayub on 2026/3/23.
//
// 哈希表伪代码逻辑
#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
private:
    vector<void*> table;
public:
    // 增/改  O(1)
    void put(auto key,auto value) {
        int index = hash(key);
        table[index] = value;
    }

    // 查 O(1)
    auto get(auto key) {
        int index = hash(key);
        return table[index];
    }

    // 删 O(1)
    void remove(auto key) {
        int index = hash(key);
        table[index] = nullptr;
    }

private:
    // 哈希函数，把key转化成table中的合法索引
    // 时间复杂度必须是O(1),才嫩保证上述方法的复杂度O(1)
    int hash(auto key) {
        int h = key.hashCode();
        // int 最小值是 -2^31，而最大值是 2^31 - 1
        // int 就是 32 个二进制位，其中最高位（最左边那位）是符号位，符号位是 0 时表示正数，是 1 时表示负数
        // 保证非负数
        // 这个 0x7fffffff 的二进制表示是 0111 1111 ... 1111
        // 即除了最高位（符号位）是 0，其他位都是 1
        // 把 0x7fffffff 和其他 int 进行 & 运算之后，最高位（符号位）就会被清零，即保证了 h 是非负数
        h = h & 0x7fffffff;
        // 映射到 table 数组的合法索引
        return h % table.length;
    }
};

// 负载因子：负载因子是一个哈希表装满的程度的度量。
// 一般来说，负载因子越大，说明哈希表里面存储的 key-value对越多，哈希冲突的概率就越大，哈希表的操作性能就越差
// 负载因子计算公式：size / table.length
// 其中 size 是哈希表里面的 key-value 对的数量，table.length 是哈希表底层数组的容量
// 用拉链法实现的哈希表，负载因子可以无限大，因为链表可以无限延伸；用线性探查法实现的哈希表，负载因子不会超过 1
// 像 Java 的 HashMap，允许我们创建哈希表时自定义负载因子，不设置的话默认是 0.75，这个值是经验值
// 当哈希表内元素达到负载因子时，哈希表会扩容，和动态数组类似
// 把哈希表底层 table 数组的容量扩大，把数据搬移到新的大数组中。size 不变，table.length 增加，负载因子就减小了

// 哈希冲突
// 两个不同的key通过哈希函数得到相同的索引
// 哈希冲突解决：一、拉链法（纵向延申）  二、线性探查法（也经常被叫做开放寻址法）（横向延申）
// 如：key的插入顺序为 k2  k4  k5  k3  k1
//      拉链法：冲突的存储一个链表             开放寻址法：index+1 去找空位，直到找到
//   k1  k2  k3  k4  k5               k1  k2  k3      k4   k5
//      |           |                      |             |
//      k1          k5                 k2  k3  k1      k4  k5
//      k3          k4
//      k2

// 用拉链法实现哈希表TODO
// 用线性探查法实现哈希表TODO  基于以下假设场景两个难点？  删除元素的空洞，两个方法解决
// 线性探查法的两种代码实现TODO
// 哈希集合的实现TODO 哈希表封装，哈希表的键，其实就是哈希集合

// 哈希表的各种变换：
// TODO 用链表加强哈希表（LinkedHashMap）
// Java的LinkedHashMap，它能让所有键按照插入顺序排列，
// 是因为它把标准的哈希表和链表结合起来，组成了一种新的数据结构：哈希链表
// 兼具了哈希表O(1)的增删查改效率，同时又可以像数组链表一样保持键的插入顺序
// TODO 用数组加强哈希表（ArrayHashMap）
// TODO布隆过滤器

// 线性探查法的基本逻辑，伪码实现
class KVNode {
public:
    int key;
    int value;
    KVNode(int k, int v) : key(k), value(v) {}
};

class MyLinearProbingHashMap {
private:
    // 数组中每个元素都存储一个键值对
    KVNode* table[10] = {nullptr};

    int hash(int key) {
        return key % 10;
    }

public:
    // 析构函数
    ~MyLinearProbingHashMap() {
        for (int i = 0; i < 10; i++) {
            if (table[i] != nullptr) {
                delete table[i];
                table[i] = nullptr;
            }
        }
    }

    void put(int key, int value) {
        int index = hash(key);
        KVNode* node = table[index];
        if (node == nullptr) {
            table[index] = new KVNode(key, value);
        } else {
            // 线性探查法的逻辑
            // 向后探查，直到找到 key 或者找到空位
            while (index < 10 && table[index] != nullptr && table[index]->key != key) {
                index++;
            }
            delete table[index];
            table[index] = new KVNode(key, value);
        }
    }

    int get(int key) {
        int index = hash(key);
        // 向后探查，直到找到 key 或者找到空位
        while (index < 10 && table[index] != nullptr && table[index]->key != key) {
            index++;
        }
        if (index >= 10 || table[index] == nullptr) {
            return -1;
        }
        return table[index]->value;
    }

    void remove(int key) {
        int index = hash(key);
        // 向后探查，直到找到 key 或者找到空位
        while (index < 10 && table[index] != nullptr && table[index]->key != key) {
            index++;
        }
        // 删除 table[index]
        // ...
    }
};


