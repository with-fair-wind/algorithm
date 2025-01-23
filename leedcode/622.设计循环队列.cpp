/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue
{
public:
    MyCircularQueue(int capacity) : m_capacity(capacity), m_arr(new int[m_capacity]) {}
    ~MyCircularQueue()
    {
        if (m_arr)
            delete[] m_arr;
        m_arr = nullptr;
    }

    bool enQueue(int value)
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

    int Front()
    {
        if (isEmpty())
            return {-1};
        return m_arr[m_L];
    }

    int Rear()
    {
        if (isEmpty())
            return {-1};
        return m_arr[m_R == 0 ? m_capacity - 1 : m_R - 1];
    }

    bool isEmpty()
    {
        return !m_size;
    }

    bool isFull()
    {
        return m_size == m_capacity;
    }

private:
    const int m_capacity;
    int *m_arr = nullptr;
    size_t m_L = 0;
    size_t m_R = 0;
    size_t m_size = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
