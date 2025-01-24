#pragma once

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

} // namespace Algo_BinaryTree
