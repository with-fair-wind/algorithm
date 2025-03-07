/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <vector>
#include <stack>

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

// Definition for a binary tree node.

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *head)
    {
        if (!head)
            return {};
        std::vector<int> res;
        std::stack<TreeNode *> stack;
        while (head)
        {
            stack.push(head);
            head = head->left;
        }
        while (!stack.empty())
        {
            TreeNode *cur = stack.top();
            stack.pop();
            res.push_back(cur->val);
            cur = cur->right;
            while (cur)
            {
                stack.push(cur);
                cur = cur->left;
            }
        }
        return res;
    }
};
// @lc code=end
