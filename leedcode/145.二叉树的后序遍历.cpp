/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *head)
    {
        if (!head)
            return {};
        std::vector<int> res;
        std::stack<TreeNode *> stack;
        std::stack<TreeNode *> stackReverse;
        stack.push(head);
        while (!stack.empty())
        {
            TreeNode *cur = stack.top();
            stack.pop();
            stackReverse.push(cur);
            if (cur->left)
                stack.push(cur->left);
            if (cur->right)
                stack.push(cur->right);
        }
        while (!stackReverse.empty())
        {
            res.push_back(stackReverse.top()->val);
            stackReverse.pop();
        }
        return res;
    }
};
// @lc code=end
