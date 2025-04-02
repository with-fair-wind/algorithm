/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    void mergeSort(std::vector<int> &nums, size_t L, size_t R)
    {
#ifdef Recursion
        if (L == R)
            return;
        int mid = L + (R - L) >> 1;
        mergeSort(nums, L, mid);
        mergeSort(nums, mid + 1, R);
        merge(nums, L, mid, R);
#else
        size_t size = R - L + 1;
        for (size_t left, mid, right, step = 1; step < size; step <<= 1)
        {
            left = L;
            while (left <= R)
            {
                mid = left + step - 1;
                if (mid >= R)
                    break;
                right = std::min(left + (step << 1) - 1, R);
                merge(nums, left, mid, right);
                left = right + 1;
            }
        }
#endif
    }

    void merge(std::vector<int> &nums, size_t L, size_t mid, size_t R)
    {
        std::vector<int> help(R - L + 1);
        size_t pLeft = L, pRight = mid + 1, index = 0;
        while (pLeft <= mid && pRight <= R)
            help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
        while (pLeft <= mid)
            help[index++] = nums[pLeft++];
        while (pRight <= R)
            help[index++] = nums[pRight++];
        for (size_t i = 0; i < help.size(); ++i)
            nums[L + i] = help[i];
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
