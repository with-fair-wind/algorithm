/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
   public:
    MyCircularDeque(int capacity) : m_capacity(capacity), m_arr(new int[m_capacity]) {}
    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            m_L = m_R = 0;
            m_arr[m_L] = value;
        } else {
            m_L = m_L ? m_L - 1 : m_capacity - 1;
            m_arr[m_L] = value;
        }
        m_size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            m_L = m_R = 0;
            m_arr[m_R] = value;
        } else {
            m_R = m_R == m_capacity - 1 ? 0 : m_R + 1;
            m_arr[m_R] = value;
        }
        m_size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        m_L = m_L == m_capacity - 1 ? 0 : m_L + 1;
        m_size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        m_R = m_R ? m_R - 1 : m_capacity - 1;
        m_size--;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : m_arr[m_L]; }
    int getRear() { return isEmpty() ? -1 : m_arr[m_R]; }
    bool isEmpty() { return !m_size; }
    bool isFull() { return m_size == m_capacity; }

   private:
    const int m_capacity;
    int* m_arr = nullptr;
    int m_L = 0;
    int m_R = 0;
    unsigned int m_size = 0;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
