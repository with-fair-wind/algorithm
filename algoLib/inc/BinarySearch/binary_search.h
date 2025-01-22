#pragma once

#include <stdafx.h>

namespace Algo_BinarySearch
{
    // 升序数组中，寻找mum值
    template <typename T>
    bool findNum(const std::vector<T> &vec, T num)
    {
        if (vec.empty())
            return false;
        size_t L = 0, R = vec.size() - 1;
        while (L <= R)
        {
            size_t mid = L + ((R - L) >> 1);
            if (vec[mid] == num)
                return true;
            else if (vec[mid] > num)
                R = mid - 1;
            else
                L = mid + 1;
        }
        return false;
    }

    // 升序数组中找>=num的最左位置
    template <typename T>
    int findLeft(const std::vector<T> &vec, T num)
    {
        if (vec.empty())
            return -1;
        int L = 0, R = vec.size() - 1, res = -1;
        while (L <= R)
        {
            int mid = L + ((R - L) >> 1);
            if (vec[mid] >= num)
            {
                res = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        return res;
    }

    // 升序数组中找<=num的最右位置
    template <typename T>
    int findRight(const std::vector<T> &vec, T num)
    {
        if (vec.empty())
            return -1;
        int L = 0, R = vec.size() - 1, res = -1;
        while (L <= R)
        {
            int mid = L + ((R - L) >> 1);
            if (vec[mid] <= num)
            {
                res = mid;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }
        return res;
    }

    // 峰值元素是指其值严格大于左右相邻值的元素
    // 给你一个整数数组 nums，已知任何两个相邻的值都不相等
    // 找到峰值元素并返回其索引
    // 数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
    // 你可以假设 nums[-1] = nums[n] = 无穷小
    template <typename T>
    int findPeakElement(const std::vector<T> &vec)
    {
        if (vec.empty())
            return -1;
        if (vec.size() == 1)
            return 0;
        if (vec[0] > vec[1])
            return 0;
        if (vec[vec.size() - 2] < vec[vec.size() - 1])
            return vec.size() - 1;
        int L = 1, R = vec.size() - 2, res = -1;
        while (L <= R)
        {
            int mid = L + ((R - L) >> 1);
            if (vec[mid - 1] > vec[mid])
                R = mid - 1;
            else if (vec[mid + 1] > vec[mid])
                L = mid + 1;
            else
            {
                res = mid;
                break;
            }
        }
        return res;
    }

} // namespace Algo_BinarySearch
