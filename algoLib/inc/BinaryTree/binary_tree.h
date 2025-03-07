#pragma once

#include <stdafx.h>
// 懒得写模板与智能指针了，Demo中的示例需手动delete
// 和 leedcode 中结构统一

namespace Algo_BinaryTree
{
    struct TreeNode
    {
        int val = 0;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        TreeNode(int data = 0, TreeNode *L = nullptr, TreeNode *R = nullptr) : val(data), left(L), right(R) {}
    };

    std::vector<int> preorderTraversal(TreeNode *head);  // 先序遍历(头左右)也是深度遍历
    std::vector<int> inorderTraversal(TreeNode *head);   // 中序遍历(左头右)
    std::vector<int> postorderTraversal(TreeNode *head); // 后序遍历(左右头)

} // namespace Algo_BinaryTree
