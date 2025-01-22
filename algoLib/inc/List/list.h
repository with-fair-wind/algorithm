#pragma once

#include <stdafx.h>

namespace Algo_List
{
    template <typename T, typename = std::void_t<decltype(T{})>>
    struct SinglyList
    {
        T _val = T{};
        std::shared_ptr<SinglyList<T>> _next = nullptr;
        SinglyList(const T &val, std::shared_ptr<SinglyList<T>> next = nullptr) : _val{val}, _next{next} {}
    };

    template <typename T, typename = std::void_t<decltype(T{})>>
    struct DoublyList
    {
        T _val = T{};
        std::shared_ptr<DoublyList<T>> _next = nullptr;
        std::shared_ptr<DoublyList<T>> _last = nullptr;
        DoublyList(const T &val, std::shared_ptr<DoublyList<T>> next = nullptr, std::shared_ptr<DoublyList<T>> last = nullptr) : _val{val}, _next{next}, _last{last} {}
    };

    template <typename T>
    std::shared_ptr<SinglyList<T>> reverseSinglyList(std::shared_ptr<SinglyList<T>> head)
    {
        std::shared_ptr<SinglyList<T>> pre = nullptr, next = nullptr;
        while (head)
        {
            next = head->_next;
            head->_next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    template <typename T>
    void printSinglyList(std::shared_ptr<SinglyList<T>> head)
    {
        while (head)
        {
            std::cout << head->_val << " ";
            head = head->_next;
        }
        std::cout << "\n";
    }

    template <typename T>
    std::shared_ptr<DoublyList<T>> reverseDoublyList(std::shared_ptr<DoublyList<T>> head)
    {
        std::shared_ptr<DoublyList<T>> pre = nullptr, next = nullptr;
        while (head)
        {
            next = head->_next;
            head->_next = pre;
            head->_last = next;
            pre = head;
            head = next;
        }
        return pre;
    }

    template <typename T>
    void printDoublyList(std::shared_ptr<DoublyList<T>> head)
    {
        std::shared_ptr<DoublyList<T>> pre = nullptr;
        std::cout << "next derection: ";
        while (head)
        {
            std::cout << head->_val << " ";
            pre = head;
            head = head->_next;
        }
        std::cout << "\nlast derection: ";
        while (pre)
        {
            std::cout << pre->_val << " ";
            pre = pre->_last;
        }
        std::cout << "\n";
    }

} // namespace Algo_List
