//
// Created by dayub on 2026/3/25.
//
#include <iostream>
#include <queue>
using namespace std;
// 层序遍历二叉树节点的顺序也是固定，三种不同写法，对应不同场景
// 简单-无法记录深度，常用-可记录深度，灵活-常用于复杂场景

// 层序遍历BFS
// 写法一
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void levelOrderTraverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        // 访问cur节点
        cout << cur->val << endl;
        // 把cur的左右子节点加入队列
        if (cur->left != nullptr) {
            q.push(cur->left);
        }
        if (cur->right != nullptr) {
            q.push(cur->right);
        }
    }
}