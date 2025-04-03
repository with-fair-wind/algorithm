#pragma once

namespace Algo_Sort
{
    template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
    void selectionSort(std::vector<T> &vec)
    {
        if (vec.empty() || vec.size() < 2)
            return;

        for (size_t i = 0; i < vec.size() - 1; ++i)
        {
            size_t minIndex = i;
            for (size_t j = i + 1; j < vec.size(); ++j)
            {
                if (vec[j] < vec[minIndex])
                    minIndex = j;
            }
            std::swap(vec[i], vec[minIndex]);
        }
    }

    template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
    void bubbleSort(std::vector<T> &vec)
    {
        if (vec.empty() || vec.size() < 2)
            return;

        for (size_t i = vec.size() - 1; i > 0; --i)
        {
            for (size_t j = 0; j < i; ++j)
            {
                if (vec[j] > vec[j + 1])
                    std::swap(vec[j], vec[j + 1]);
            }
        }
    }

    template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
    void insertSort(std::vector<T> &vec)
    {
        if (vec.empty() || vec.size() < 2)
            return;

        for (size_t i = 1; i < vec.size(); ++i)
        {
            for (size_t j = i - 1; j >= 0 && vec[j] > vec[j + 1]; --j)
                std::swap(vec[j], vec[j + 1]);
        }
    }

    void mergeSort(std::vector<int> &nums, size_t L, size_t R);
    void merge(std::vector<int> &nums, size_t L, size_t mid, size_t R);
    /// 归并分治
    /// @brief 小和问题
    /// @param nums
    /// @param L
    /// @param R
    /// @details https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
    /// @details 结果比较大，用int会溢出的，所以返回long类型
    /// @details 返回arr[l...r]范围上，小和的累加和，同时请把arr[l..r]变有序
    /// @details 时间复杂度O(n * logn)
    long smallSum(std::vector<int> &nums, size_t L, size_t R);
    long merge_smallSum(std::vector<int> &nums, size_t L, size_t mid, size_t R);
    /// @brief 翻转对
    /// @details https://leetcode.cn/problems/reverse-pairs/
    /// @param nums
    int reversePairs(std::vector<int> &nums, size_t L, size_t R);
    int merge_reversePairs(std::vector<int> &nums, size_t L, size_t mid, size_t R);

    class Logarithm
    {
        PROPERTY_CREATE(int, rounds)
        PROPERTY_CREATE(int, maxSize)
        PROPERTY_CREATE(int, maxVal)

    private:
        template <typename T>
        using func = void (*)(std::vector<T> &vec);

    public:
        Logarithm();
        void randomVec(std::vector<int> &vec, int maxSize, int maxVal);
        void check(func<int> func1, func<int> func2);
    };
} // namespace Sort
