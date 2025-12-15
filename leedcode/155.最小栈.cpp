/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <stack>

// @lc code=start
class MinStack {
   public:
    void push(int val) {
        m_data.push(val);
        m_min.push(m_min.empty() || val < m_min.top() ? val : m_min.top());
    }

    void pop() {
        m_data.pop();
        m_min.pop();
    }

    int top() { return m_data.top(); }
    int getMin() { return m_min.top(); }

   private:
    std::stack<int> m_data;
    std::stack<int> m_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
