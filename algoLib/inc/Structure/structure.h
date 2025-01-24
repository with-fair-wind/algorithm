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
        DISABLE_COPY(Queue)
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
        int m_L = 0;
        int m_R = 0;
        unsigned int m_size = 0;
    };

    // 以数组实现栈
    // 同时在栈里的元素个数不会超过capacity
    template <typename T>
    class Stack
    {
        DISABLE_COPY(Stack)

    public:
        Stack(int capacity) : m_capacity{capacity}, m_arr{new T[m_capacity]} {}
        ~Stack() { SAFE_DELETE_ARRAY(m_arr) }

        void push(T val)
        {
            m_arr[m_size++] = val;
        }
        T pop() { return m_arr[--m_size]; }
        T top() const { return m_arr[m_size - 1]; }
        bool empty() const { return !m_size; }
        int size() const { return m_size; }

    private:
        const int m_capacity;
        T *m_arr = nullptr;
        unsigned int m_size = 0;
    };
} // namespace Algo_Structure
