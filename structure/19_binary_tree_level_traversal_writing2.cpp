//
// Created by dayub on 2026/3/25.
//
#include <iostream>
#include <queue>
using namespace std;

// 层序遍历BFS
// 写法二
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 写法二
void levelOrderTraverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    // 记录当前遍历到的层数，根节点视为第一层
    int depth = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* cur = q.front();
            q.pop();
            // 访问cur节点，同时知道它所在的层数
            cout << "depth = " << depth << ",val = " << cur->val << endl;
            // 把cur的左右子节点加入队列
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
        depth++;
    }
}