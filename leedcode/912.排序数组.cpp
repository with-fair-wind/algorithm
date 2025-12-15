// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include <algorithm>
#include <cmath>
#include <random>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        // mergeSort(nums, 0, nums.size() - 1);
        // quickSort_v1(nums, 0, nums.size() - 1);
        // quickSort_v2(nums, 0, nums.size() - 1);
        heapSort(nums);
        return nums;
    }

    void mergeSort(std::vector<int>& nums, int L, int R) {
#ifdef Recursion
        if (L == R) return;
        int mid = L + (R - L) >> 1;
        mergeSort(nums, L, mid);
        mergeSort(nums, mid + 1, R);
        merge(nums, L, mid, R);
#else
        int size = R - L + 1;
        for (int left, mid, right, step = 1; step < size; step <<= 1) {
            left = L;
            while (left <= R) {
                mid = left + step - 1;
                if (mid >= R) break;
                right = std::min(left + (step << 1) - 1, R);
                merge(nums, left, mid, right);
                left = right + 1;
            }
        }
#endif
    }

    void merge(std::vector<int>& nums, int L, int mid, int R) {
        std::vector<int> help(R - L + 1);
        int pLeft = L, pRight = mid + 1, index = 0;
        while (pLeft <= mid && pRight <= R) help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
        while (pLeft <= mid) help[index++] = nums[pLeft++];
        while (pRight <= R) help[index++] = nums[pRight++];
        for (int i = 0; i < help.size(); ++i) nums[L + i] = help[i];
    }

    void quickSort_v1(std::vector<int>& nums, int L, int R) {
        if (L >= R) return;
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(L, R);
        int cmp = nums[distribution(generator)];
        int index = partition_v1(nums, L, R, cmp);
        quickSort_v1(nums, L, index - 1);
        quickSort_v1(nums, index + 1, R);
    }

    int partition_v1(std::vector<int>& nums, int L, int R, int cmp) {
        // 设为int类型防止bound - 1为无穷大
        int bound = L, cmp_index;
        for (int i = L; i <= R; ++i) {
            if (nums[i] <= cmp) {
                std::swap(nums[i], nums[bound]);
                if (nums[bound] == cmp) cmp_index = bound;
                bound++;
            }
        }
        std::swap(nums[cmp_index], nums[bound - 1]);
        return bound - 1;
    }

    void quickSort_v2(std::vector<int>& nums, int L, int R) {
        if (L >= R) return;
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(L, R);
        int cmp = nums[distribution(generator)];
        std::pair<int, int> bound = partition_v2(nums, L, R, cmp);
        quickSort_v2(nums, L, bound.first - 1);
        quickSort_v2(nums, bound.second + 1, R);
    }

    std::pair<int, int> partition_v2(std::vector<int>& nums, int L, int R, int cmp) {
        // 设为int类型防止bound - 1为无穷大
        int left = L, right = R, index = L;
        while (index <= right) {
            if (nums[index] < cmp)
                std::swap(nums[index++], nums[left++]);
            else if (nums[index] == cmp)
                index++;
            else
                std::swap(nums[index], nums[right--]);
        }
        return {left, right};
    }

    void heapinsert(std::vector<int>& nums, int index) {
        while (nums[index] > nums[(index - 1) / 2]) {
            std::swap(nums[index], nums[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapify(std::vector<int>& nums, int index, int size) {
        int left = index * 2 + 1;
        while (left < size) {
            int largest = left + 1 < size && nums[left] < nums[left + 1] ? left + 1 : left;
            largest = nums[index] < nums[largest] ? largest : index;
            if (largest == index) break;
            std::swap(nums[index], nums[largest]);
            index = largest;
            left = index * 2 + 1;
        }
    }

    void heapSort(std::vector<int>& nums) {
#if 1
        // 从顶到底建堆
        for (int i = 0; i < nums.size(); ++i) heapinsert(nums, i);
#else
        // 从底到顶建堆
        for (int i = nums.size() - 1; i >= 0; --i) heapify(nums, i, nums.size());
#endif
        int size = nums.size();
        while (size > 1) {
            std::swap(nums[0], nums[--size]);
            heapify(nums, 0, size);
        }
    }
};
// @lc code=end
