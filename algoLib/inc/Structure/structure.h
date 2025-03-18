#pragma once

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

    // 用栈实现队列
    // 测试链接 : https://leetcode.cn/problems/implement-queue-using-stacks/
    class S2Queue
    {
    private:
        void inToOut()
        {
            if (m_out.empty())
            {
                while (!m_in.empty())
                {
                    m_out.push(m_in.top());
                    m_in.pop();
                }
            }
        }

    public:
        void push(int x)
        {
            inToOut();
            m_in.push(x);
        }

        int pop()
        {
            inToOut();
            int ans = m_out.top();
            m_out.pop();
            return ans;
        }

        int peek()
        {
            inToOut();
            return m_out.top();
        }

        bool empty() { return m_in.empty() && m_out.empty(); }

    private:
        std::stack<int> m_in;
        std::stack<int> m_out;
    };

    // 用队列实现栈
    // 测试链接 : https://leetcode.cn/problems/implement-stack-using-queues/
    class Q2Stack
    {
    public:
        void push(int x)
        {
            m_queue.push(x);
            for (int i = 0; i < m_queue.size() - 1; ++i)
            {
                m_queue.push(m_queue.front());
                m_queue.pop();
            }
        }

        int pop()
        {
            int ans = m_queue.front();
            m_queue.pop();
            return ans;
        }
        int top() { return m_queue.front(); }
        bool empty() { return m_queue.empty(); }

    private:
        std::queue<int> m_queue;
    };

    // 最小栈
    // 测试链接 : https://leetcode.cn/problems/min-stack/
    class MinStack
    {
    public:
        void push(int val)
        {
            m_data.push(val);
            m_min.push(m_min.empty() || val < m_min.top() ? val : m_min.top());
        }

        void pop()
        {
            m_data.pop();
            m_min.pop();
        }

        int top() { return m_data.top(); }
        int getMin() { return m_min.top(); }

    private:
        std::stack<int> m_data;
        std::stack<int> m_min;
    };

    // 设计循环双端队列
    // 同时在队列里的数字个数，不要超过capacity, 有效范围[L, R]
    // 测试链接 : https://leetcode.cn/problems/design-circular-deque/
    class Deque
    {
        DISABLE_COPY(Deque)
    public:
        Deque(int capacity) : m_capacity(capacity), m_arr(new int[m_capacity]) {}
        ~Deque() { SAFE_DELETE_ARRAY(m_arr) }

        bool insertFront(int value);
        bool insertLast(int value);
        bool deleteFront();
        bool deleteLast();
        int getFront();
        int getRear();
        bool isEmpty() { return !m_size; }
        bool isFull() { return m_size == m_capacity; }

    private:
        const int m_capacity;
        int *m_arr = nullptr;
        int m_L = 0;
        int m_R = 0;
        unsigned int m_size = 0;
    };

} // namespace Algo_Structure
