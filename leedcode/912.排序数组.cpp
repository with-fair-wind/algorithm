// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        // mergeSort(nums, 0, nums.size() - 1);
        // quickSort_v1(nums, 0, nums.size() - 1);
        quickSort_v2(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(std::vector<int> &nums, int L, int R)
    {
#ifdef Recursion
        if (L == R)
            return;
        int mid = L + (R - L) >> 1;
        mergeSort(nums, L, mid);
        mergeSort(nums, mid + 1, R);
        merge(nums, L, mid, R);
#else
        int size = R - L + 1;
        for (int left, mid, right, step = 1; step < size; step <<= 1)
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

    void merge(std::vector<int> &nums, int L, int mid, int R)
    {
        std::vector<int> help(R - L + 1);
        int pLeft = L, pRight = mid + 1, index = 0;
        while (pLeft <= mid && pRight <= R)
            help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
        while (pLeft <= mid)
            help[index++] = nums[pLeft++];
        while (pRight <= R)
            help[index++] = nums[pRight++];
        for (int i = 0; i < help.size(); ++i)
            nums[L + i] = help[i];
    }

    void quickSort_v1(std::vector<int> &nums, int L, int R)
    {
        if (L >= R)
            return;
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(L, R);
        int cmp = nums[distribution(generator)];
        int index = partition_v1(nums, L, R, cmp);
        quickSort_v1(nums, L, index - 1);
        quickSort_v1(nums, index + 1, R);
    }

    int partition_v1(std::vector<int> &nums, int L, int R, int cmp)
    {
        // 设为int类型防止bound - 1为无穷大
        int bound = L, cmp_index;
        for (int i = L; i <= R; ++i)
        {
            if (nums[i] <= cmp)
            {
                std::swap(nums[i], nums[bound]);
                if (nums[bound] == cmp)
                    cmp_index = bound;
                bound++;
            }
        }
        std::swap(nums[cmp_index], nums[bound - 1]);
        return bound - 1;
    }

    void quickSort_v2(std::vector<int> &nums, int L, int R)
    {
        if (L >= R)
            return;
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(L, R);
        int cmp = nums[distribution(generator)];
        std::pair<int, int> bound = partition_v2(nums, L, R, cmp);
        quickSort_v2(nums, L, bound.first - 1);
        quickSort_v2(nums, bound.second + 1, R);
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
};
// @lc code=end
