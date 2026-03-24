//
// Created by dayub on 2026/3/24.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 二叉树节点类
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
int main() {
    // 二叉树构建
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    //     1
    //    / \
    //   2   3
    //  /   / \
    // 4   5   6
    // 在一般的算法题中，会把实际问题抽象成二叉树结构，但并不需要真的用 TreeNode 创建一棵二叉树
    // 而是直接用类似哈希表的结构来表示二叉树/多叉树
    // 用哈希表，其中键是父节点id，值是子节点id的列表（每个节点的id是唯一），即一个键值对就是一个多叉树节点
    // 1 -> {2,3}
    // 2 -> {4}
    // 3 -> {5,6}
    unordered_map<int, vector<int>> tree;
    tree[1] = {2,3};
    tree[2] = {4};
    tree[3] = {5,6};
    // 模拟二叉树多叉树结构，图论里面的邻接表
}

// 满二叉树：每一层节点都是满的
// 总节点2^n -1  等比数列求和

// 完全二叉树：二叉树的每一层的节点都紧凑靠左排列，且除了最后一层，其他每层都必须是满的
// 由于它的节点紧凑排列，如果从左到右从上到下对它的每个节点编号，那么父子节点的索引存在明显的规律
// 完全二叉树的左右子树也是完全二叉树。
// 完全二叉树的左右子树中，至少有一棵是满二叉树。

// 完全二叉树对应英文 Complete Binary Tree
// 满二叉树的定义对应英文的 Perfect Binary Tree
// 而英文中的 Full Binary Tree 是指一棵二叉树的所有节点要么没有孩子节点，要么有两个孩子节点。

// 二叉搜索树（Binary Search Tree，简称 BST）
// 对于树中的每个节点，其左子树的每个节点的值都要小于这个节点的值，
// 右子树的每个节点的值都要大于这个节点的值。你可以简单记为「左小右大」。
// BST 是非常常用的数据结构。因为左小右大的特性，可以让我们在 BST 中快速找到某个节点，或者找到某个范围内的所有节点

// 高度平衡二叉树（Height-Balanced Binary Tree）
// 它的「每个节点」的左右子树的高度差不超过 1。
// 重要：假设高度平衡二叉树中共有N个节点，那么高度平衡二叉树的高度是O(log N)

// 自平衡二叉树（Self-Balanced Binary Tree）
// 红黑树，一种自平衡的二叉搜素树

