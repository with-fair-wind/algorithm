/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <stack>

// @lc code=start
class MyQueue
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
        // if (m_out.empty())
        //     return -1;
        int ans = m_out.top();
        m_out.pop();
        return ans;
    }

    int peek()
    {
        inToOut();
        // return m_out.empty() ? -1 : m_out.top();
        return m_out.top();
    }

    bool empty() { return m_in.empty() && m_out.empty(); }

private:
    std::stack<int> m_in;
    std::stack<int> m_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
