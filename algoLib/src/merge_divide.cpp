#include <Sort/merge_divide.h>

namespace Algo_Merge_Divide {
long smallSum(std::vector<int>& nums, size_t L, size_t R) {
    if (L == R) return 0;
    int mid = L + ((R - L) >> 1);
    return smallSum(nums, L, mid) + smallSum(nums, mid + 1, R) + merge_smallSum(nums, L, mid, R);
}

long merge_smallSum(std::vector<int>& nums, size_t L, size_t mid, size_t R) {
    long res = 0.;
#if 0
        std::vector<int> help(R - L + 1);
        size_t pLeft = L, pRight = mid + 1, index = 0;
        while (pLeft <= mid && pRight <= R)
        {
            res += nums[pLeft] <= nums[pRight] ? nums[pLeft] * (R - pRight + 1) : 0;
            help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
        }
#else
    // 统计部分
    for (size_t i = L, j = mid + 1, sum = 0; j <= R; ++j) {
        while (i <= mid && nums[i] <= nums[j]) sum += nums[i++];
        res += sum;
    }

    std::vector<int> help(R - L + 1);
    size_t pLeft = L, pRight = mid + 1, index = 0;
    while (pLeft <= mid && pRight <= R) help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
#endif
    while (pLeft <= mid) help[index++] = nums[pLeft++];
    while (pRight <= R) help[index++] = nums[pRight++];
    for (int i = 0; i < help.size(); ++i) nums[L + i] = help[i];
    return res;
}

int reversePairs(std::vector<int>& nums, size_t L, size_t R) {
    if (L == R) return 0;
    int mid = L + ((R - L) >> 1);
    return reversePairs(nums, L, mid) + reversePairs(nums, mid + 1, R) + merge_reversePairs(nums, L, mid, R);
}

int merge_reversePairs(std::vector<int>& nums, size_t L, size_t mid, size_t R) {
    int res = 0;
    for (size_t i = L, j = mid + 1; i <= mid; ++i) {
        while (j <= R && nums[i] > 2 * nums[j]) j++;
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
}  // namespace Algo_Merge_Divide
