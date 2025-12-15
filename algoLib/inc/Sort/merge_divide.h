#pragma once

namespace Algo_Merge_Divide {
/// 归并分治
/// @brief 小和问题
/// @param nums
/// @param L
/// @param R
/// @details https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
/// @details 结果比较大，用int会溢出的，所以返回long类型
/// @details 返回arr[l...r]范围上，小和的累加和，同时请把arr[l..r]变有序
/// @details 时间复杂度O(n * logn)
long smallSum(std::vector<int>& nums, size_t L, size_t R);
long merge_smallSum(std::vector<int>& nums, size_t L, size_t mid, size_t R);
/// @brief 翻转对
/// @details https://leetcode.cn/problems/reverse-pairs/
/// @param nums
int reversePairs(std::vector<int>& nums, size_t L, size_t R);
int merge_reversePairs(std::vector<int>& nums, size_t L, size_t mid, size_t R);
}  // namespace Algo_Merge_Divide
