#pragma once

namespace Algo_Sort {
template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
void selectionSort(std::vector<T>& vec) {
    if (vec.empty() || vec.size() < 2) return;

    for (size_t i = 0; i < vec.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[minIndex]) minIndex = j;
        }
        std::swap(vec[i], vec[minIndex]);
    }
}

template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
void bubbleSort(std::vector<T>& vec) {
    if (vec.empty() || vec.size() < 2) return;

    for (size_t i = vec.size() - 1; i > 0; --i) {
        for (size_t j = 0; j < i; ++j) {
            if (vec[j] > vec[j + 1]) std::swap(vec[j], vec[j + 1]);
        }
    }
}

template <typename T, typename = decltype(std::declval<T>() < std::declval<T>())>
void insertSort(std::vector<T>& vec) {
    if (vec.empty() || vec.size() < 2) return;

    for (int i = 1; i < vec.size(); ++i) {
        for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; --j) std::swap(vec[j], vec[j + 1]);
    }
}

void mergeSort(std::vector<int>& nums, size_t L, size_t R);
void merge(std::vector<int>& nums, size_t L, size_t mid, size_t R);

void quickSort_v1(std::vector<int>& nums, int L, int R);
int partition_v1(std::vector<int>& nums, int L, int R, int cmp);
void quickSort_v2(std::vector<int>& nums, int L, int R);
std::pair<int, int> partition_v2(std::vector<int>& nums, int L, int R, int cmp);

/// @brief 无序数组中第K大的元素
/// @param nums
/// @param k
/// @return
/// @details https://leetcode.cn/problems/kth-largest-element-in-an-array/
int findKthLargest(std::vector<int>& nums, int k);
/// @details 随机选择算法，时间复杂度O(n)  如果nums排序的话，在i位置的数字是什么
int randomizedSelect(std::vector<int>& nums, int k);

void heapinsert(std::vector<int>& nums, int index);
void heapify(std::vector<int>& nums, int index, int size);
void heapSort(std::vector<int>& nums);

class Logarithm {
    PROPERTY_CREATE(int, rounds)
    PROPERTY_CREATE(int, maxSize)
    PROPERTY_CREATE(int, maxVal)

   private:
    template <typename T>
    using func = void (*)(std::vector<T>& vec);

   public:
    Logarithm();
    void randomVec(std::vector<int>& vec, int maxSize, int maxVal);
    void check(func<int> func1, func<int> func2);
};
}  // namespace Algo_Sort
