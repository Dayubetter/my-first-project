//
// Created by dayub on 2026/3/25.
//
#include <iostream>
#include <queue>
using namespace std;

// 层序遍历BFS
// 写法三
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 写法三
// 写法二每向下遍历一层就depth+1，可以理解为每条树枝的权重是1，二叉树中的每个节点的深度即为根节点到这个节点的权重和
// 且同一层所有节点权重和是相同的
// 如果每条树枝的权重是任意值，需要在写法一上添加一个State类,每个节点自己负责维护自己的路径权重和
class State {
public:
    TreeNode* node;
    int depth;

    State(TreeNode* node, int depth) : node(node), depth(depth) {}
};
void levelOrderTraverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<State> q;
    // 根节点的路径权重和是1
    q.push(State(root, 1));

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        // 访问cur节点，同时知道它的权重和
        cout << "depth = " << cur.depth << ",val = " << cur.node->val << endl;

        // 把cur的左右子节点加入队列
        if (cur.node->left != nullptr) {
            q.push(State(cur.node->left, cur.depth + 1));
        }
        if (cur.node->right != nullptr) {
            q.push(State(cur.node->right, cur.depth + 1));
        }
    }
}