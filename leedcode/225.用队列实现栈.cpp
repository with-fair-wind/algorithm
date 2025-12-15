/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <queue>

// @lc code=start
class MyStack {
   public:
    void push(int x) {
        m_queue.push(x);
        for (int i = 0; i < m_queue.size() - 1; ++i) {
            m_queue.push(m_queue.front());
            m_queue.pop();
        }
    }

    int pop() {
        int ans = m_queue.front();
        m_queue.pop();
        return ans;
    }
    int top() { return m_queue.front(); }
    bool empty() { return m_queue.empty(); }

   private:
    std::queue<int> m_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
