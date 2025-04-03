/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <vector>
#include <random>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        return randomizedSelect(nums, nums.size() - k);
    }

    std::pair<int, int> partition_v2(std::vector<int> &nums, int L, int R, int cmp)
    {
        // 设为int类型防止bound - 1为无穷大
        int left = L, right = R, index = L;
        while (index <= right)
        {
            if (nums[index] < cmp)
                std::swap(nums[index++], nums[left++]);
            else if (nums[index] == cmp)
                index++;
            else
                std::swap(nums[index], nums[right--]);
        }
        return {left, right};
    }

    int randomizedSelect(std::vector<int> &nums, int k)
    {
        for (int L = 0, R = nums.size() - 1; L <= R;)
        {
            std::mt19937 generator(std::random_device{}());
            std::uniform_int_distribution<int> distribution(L, R);
            int cmp = nums[distribution(generator)];
            std::pair<int, int> bound = partition_v2(nums, L, R, cmp);
            if (k >= bound.first && k <= bound.second)
                return nums[k];
            else if (k < bound.first)
                R = bound.first - 1;
            else
                L = bound.second + 1;
        }
        return -1;
    }
};
// @lc code=end
