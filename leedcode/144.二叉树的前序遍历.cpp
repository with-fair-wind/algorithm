/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* head) {
        if (!head) return {};
        std::vector<int> res;
        std::stack<TreeNode*> stack;
        stack.push(head);
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            stack.pop();
            res.push_back(cur->val);
            if (cur->right) stack.push(cur->right);
            if (cur->left) stack.push(cur->left);
        }
        return res;
    }
};
// @lc code=end
