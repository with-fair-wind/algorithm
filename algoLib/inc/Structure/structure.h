#pragma once

#include <stdafx.h>

namespace Algo_Structure
{
    // 循环队列
    // 以数组实现队列，尾进头出, 有效范围[L, R)
    // 同时在队列里的数字个数，不要超过capacity
    // 测试链接 : https://leetcode.cn/problems/design-circular-queue/
    template <typename T>
    class Queue
    {
    public:
        Queue(int capacity) : m_capacity(capacity), m_arr(new T[m_capacity]) {}
        ~Queue() { SAFE_DELETE_ARRAY(m_arr) }

        bool enQueue(T value)
        {
            if (isFull())
                return false;
            m_arr[m_R] = value;
            m_R = m_R == m_capacity - 1 ? 0 : (m_R + 1);
            m_size++;
            return true;
        }

        bool deQueue()
        {
            if (isEmpty())
                return false;
            m_L = m_L == m_capacity - 1 ? 0 : (m_L + 1);
            m_size--;
            return true;
        }

        T Front() const
        {
            if (isEmpty())
                return {-1};
            return m_arr[m_L];
        }

        T Rear() const
        {
            if (isEmpty())
                return {-1};
            return m_arr[m_R == 0 ? m_capacity - 1 : m_R - 1];
        }

        bool isEmpty() const { return !m_size; }
        bool isFull() const { return m_size == m_capacity; }

    private:
        const int m_capacity;
        T *m_arr = nullptr;
        size_t m_L = 0;
        size_t m_R = 0;
        size_t m_size = 0;
    };
} // namespace Algo_Structure
