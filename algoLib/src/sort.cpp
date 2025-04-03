#include <Sort/sort.h>
#include <Utility/utility.h>

namespace Algo_Sort
{
    void mergeSort(std::vector<int> &nums, size_t L, size_t R)
    {
#ifdef Recursion
        if (L == R)
            return;
        int mid = L + ((R - L) >> 1);
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
                // 左侧拿不满/刚好拿满就停止
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
        for (int i = 0; i < help.size(); ++i)
            nums[L + i] = help[i];
    }

    long smallSum(std::vector<int> &nums, size_t L, size_t R)
    {
        if (L == R)
            return 0;
        int mid = L + ((R - L) >> 1);
        return smallSum(nums, L, mid) + smallSum(nums, mid + 1, R) + merge_smallSum(nums, L, mid, R);
    }

    long merge_smallSum(std::vector<int> &nums, size_t L, size_t mid, size_t R)
    {
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
        for (size_t i = L, j = mid + 1, sum = 0; j <= R; ++j)
        {
            while (i <= mid && nums[i] <= nums[j])
                sum += nums[i++];
            res += sum;
        }

        std::vector<int> help(R - L + 1);
        size_t pLeft = L, pRight = mid + 1, index = 0;
        while (pLeft <= mid && pRight <= R)
            help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
#endif
        while (pLeft <= mid)
            help[index++] = nums[pLeft++];
        while (pRight <= R)
            help[index++] = nums[pRight++];
        for (int i = 0; i < help.size(); ++i)
            nums[L + i] = help[i];
        return res;
    }

    int reversePairs(std::vector<int> &nums, size_t L, size_t R)
    {
        if (L == R)
            return 0;
        int mid = L + ((R - L) >> 1);
        return reversePairs(nums, L, mid) + reversePairs(nums, mid + 1, R) + merge_reversePairs(nums, L, mid, R);
    }

    int merge_reversePairs(std::vector<int> &nums, size_t L, size_t mid, size_t R)
    {
        int res = 0;
        for (size_t i = L, j = mid + 1; i <= mid; ++i)
        {
            while (j <= R && nums[i] > 2 * nums[j])
                j++;
            res += (j - mid - 1);
        }

        std::vector<int> help(R - L + 1);
        size_t pLeft = L, pRight = mid + 1, index = 0;
        while (pLeft <= mid && pRight <= R)
            help[index++] = nums[pLeft] <= nums[pRight] ? nums[pLeft++] : nums[pRight++];
        while (pLeft <= mid)
            help[index++] = nums[pLeft++];
        while (pRight <= R)
            help[index++] = nums[pRight++];
        for (int i = 0; i < help.size(); ++i)
            nums[L + i] = help[i];
        return res;
    }

    Logarithm::Logarithm()
    {
        m_rounds = 100000;
        m_maxSize = 10;
        m_maxVal = 100;
    }

    void Logarithm::randomVec(std::vector<int> &vec, int maxSize, int maxVal)
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, maxSize);

        vec.resize(distribution(generator));

        distribution = std::uniform_int_distribution<int>(-maxVal, maxVal);
        for (auto &cur : vec)
            cur = distribution(generator);
    }

    void Logarithm::check(func<int> func1, func<int> func2)
    {
        bool success = true;
        for (int i = 0; i < m_rounds; ++i)
        {
            std::vector<int> ori;
            randomVec(ori, m_maxSize, m_maxVal);
            std::vector<int> vec1 = ori;
            std::vector<int> vec2 = ori;

            func1(vec1);
            func2(vec2);

            for (size_t i = 0; i < vec1.size(); ++i)
            {
                if (vec1[i] != vec2[i])
                {
                    success = false;
                    break;
                }
            }

            if (!success)
            {
                std::cout << "Failure Use Case: \n ";
                Algo_Utility::Utility::printVec(ori);
                Algo_Utility::Utility::printVec(vec1);
                Algo_Utility::Utility::printVec(vec2);
                return;
            }
        }
        std::cout << "Pass!\n";
    }
} // namespace Sort
