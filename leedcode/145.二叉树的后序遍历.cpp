/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* head) {
        if (!head) return {};
        std::vector<int> res;
        std::stack<TreeNode*> stack;
        stack.push(head);
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            if (cur->left && head != cur->left && head != cur->right)
                stack.push(cur->left);
            else if (cur->right && head != cur->right)
                stack.push(cur->right);
            else {
                stack.pop();
                head = cur;
                res.push_back(head->val);
            }
        }
        return res;
    }
};
// @lc code=end
