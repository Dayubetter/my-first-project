//
// Created by dayub on 2026/3/26.
//

/**
 *      144.二叉树的前序遍历
 * 给你二叉树的根节点 root ，返回它节点值的前序遍历。
 * 示例 1：
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 */

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
        vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        return v;
    }
private:
    void preorder(TreeNode* root, vector<int> & v) {
        if (root == nullptr) {
            return;
        }
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
        return;
    }
};