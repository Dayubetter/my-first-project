//
// Created by dayub on 2026/3/25.
//
#include <iostream>
#include <queue>
using namespace std;
// 二叉树只有递归遍历和层序遍历两种，递归衍生出DFS，层序遍历衍生出BFS
// 递归遍历二叉树节点的顺序是固定的，三个关键位置插入代码，产生不同效果，前序中序后序

// 递归遍历DFS
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 二叉树的递归遍历框架
// ！前序位置的代码会在进入节点时立即执行；
// ！中序位置的代码会在左子树遍历完成后，遍历右子树之前执行；
// ！后序位置的代码会在左右子树遍历完成后执行
// 二叉搜索树BST，的中序遍历是有序的（左小又大）
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // 前序位置
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
}



