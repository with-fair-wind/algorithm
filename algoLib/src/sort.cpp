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
        for (int i = L; i < R; ++i)
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

    int findKthLargest(std::vector<int> &nums, int k)
    {
        return randomizedSelect(nums, nums.size() - k);
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
        // return -1;
    }

    void heapinsert(std::vector<int> &nums, int index)
    {
        while (nums[index] > nums[(index - 1) / 2])
        {
            std::swap(nums[index], nums[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapify(std::vector<int> &nums, int index, int size)
    {
        int left = index * 2 + 1;
        while (left < size)
        {
            int largest = left + 1 < size && nums[left] < nums[left + 1] ? left + 1 : left;
            largest = nums[index] < nums[largest] ? largest : index;
            if (largest == index)
                break;
            std::swap(nums[index], nums[largest]);
            index = largest;
            left = index * 2 + 1;
        }
    }

    void heapSort(std::vector<int> &nums)
    {
#if 0
        // 从顶到底建堆 O(N*logN)
        for (int i = 0; i < nums.size(); ++i)
            heapinsert(nums, i);
#else
        for (int i = nums.size() - 1; i >= 0; --i)
            heapify(nums, i, nums.size());
#endif
        // 从底到顶建堆 O(N)
        int size = nums.size();
        while (size > 1)
        {
            std::swap(nums[0], nums[--size]);
            heapify(nums, 0, size);
        }
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
