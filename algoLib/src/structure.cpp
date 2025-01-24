#include <Structure/structure.h>

namespace Algo_Structure
{
    bool Deque::insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            // 限定 [L, R] eg. 先 push_front 再 pop_back 时，会出现 m_L > m_R, 需重置
            m_L = m_R = 0;
            m_arr[m_L] = value;
        }
        else
        {
            m_L = m_L ? m_L - 1 : m_capacity - 1;
            m_arr[m_L] = value;
        }
        m_size++;
        return true;
    }

    bool Deque::insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            m_L = m_R = 0;
            m_arr[m_R] = value;
        }
        else
        {
            m_R = m_R == m_capacity - 1 ? 0 : m_R + 1;
            m_arr[m_R] = value;
        }
        m_size++;
        return true;
    }

    bool Deque::deleteFront()
    {
        if (isEmpty())
            return false;
        m_L = m_L == m_capacity - 1 ? 0 : m_L + 1;
        m_size--;
        return true;
    }

    bool Deque::deleteLast()
    {
        if (isEmpty())
            return false;
        m_R = m_R ? m_R - 1 : m_capacity - 1;
        m_size--;
        return true;
    }

    int Deque::getFront() { return isEmpty() ? -1 : m_arr[m_L]; }
    int Deque::getRear() { return isEmpty() ? -1 : m_arr[m_R]; }
} // namespace Algo_Structure
