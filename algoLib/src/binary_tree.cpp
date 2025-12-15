#include <BinaryTree/binary_tree.h>

namespace Algo_BinaryTree {
std::vector<int> preorderTraversal(TreeNode* head) {
#ifdef Recursion
    if (!head) return {};
    std::vector<int> res{head->val};
    std::vector<int> left = preorderTraversal(head->left);
    std::vector<int> right = preorderTraversal(head->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
#else
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
#endif
}

std::vector<int> inorderTraversal(TreeNode* head) {
#ifdef Recursion
    if (!head) return {};
    std::vector<int> res;
    std::vector<int> left = inorderTraversal(head->left);
    res.insert(res.end(), left.begin(), left.end());
    res.push_back(head->val);
    std::vector<int> right = inorderTraversal(head->right);
    res.insert(res.end(), right.begin(), right.end());
    return res;
#else
    if (!head) return {};
    std::vector<int> res;
    std::stack<TreeNode*> stack;
    while (head || !stack.empty()) {
        if (head) {
            stack.push(head);
            head = head->left;
        } else {
            head = stack.top();
            stack.pop();
            res.push_back(head->val);
            head = head->right;
        }
    }
    return res;
#endif
}

std::vector<int> postorderTraversal(TreeNode* head) {
#ifdef Recursion
    if (!head) return {};
    std::vector<int> res;
    std::vector<int> left = postorderTraversal(head->left);
    std::vector<int> right = postorderTraversal(head->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    res.push_back(head->val);
    return res;
#else
#if 0
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
#else
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
#endif
#endif
}
}  // namespace Algo_BinaryTree
