/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int reversePairs(vector<int>& nums) { return reversePairs(nums, 0, nums.size() - 1); }

    int reversePairs(std::vector<int>& nums, size_t L, size_t R) {
        if (L == R) return 0;
        int mid = L + ((R - L) >> 1);
        return reversePairs(nums, L, mid) + reversePairs(nums, mid + 1, R) + merge_reversePairs(nums, L, mid, R);
    }

    int merge_reversePairs(std::vector<int>& nums, size_t L, size_t mid, size_t R) {
        int res = 0;
        for (size_t i = L, j = mid + 1; i <= mid; ++i) {
            while (j <= R && (long)nums[i] > (long)2 * nums[j]) j++;
            res += (j - mid - 1);
        }

        std::vector<int> help(R - L + 1);
        size_t pLeft = L, pRight = mid + 1, index = 0;
        while (pLeft <= mid && pRight <= R) help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
        while (pLeft <= mid) help[index++] = nums[pLeft++];
        while (pRight <= R) help[index++] = nums[pRight++];
        for (int i = 0; i < help.size(); ++i) nums[L + i] = help[i];
        return res;
    }
};
// @lc code=end
