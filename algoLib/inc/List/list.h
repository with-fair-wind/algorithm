#pragma once

#include <stdafx.h>

namespace Algo_List
{
    template <typename T, typename = std::void_t<decltype(T{})>>
    struct SinglyList
    {
        T _val{};
        std::shared_ptr<SinglyList<T>> _next = nullptr;
        SinglyList() = default;
        SinglyList(const T &val, std::shared_ptr<SinglyList<T>> next = nullptr) : _val{val}, _next{next} {}
    };

    template <typename T, typename = std::void_t<decltype(T{})>>
    struct DoublyList
    {
        T _val{};
        std::shared_ptr<DoublyList<T>> _next = nullptr;
        std::shared_ptr<DoublyList<T>> _last = nullptr;
        DoublyList() = default;
        DoublyList(const T &val, std::shared_ptr<DoublyList<T>> next = nullptr, std::shared_ptr<DoublyList<T>> last = nullptr) : _val{val}, _next{next}, _last{last} {}
    };

    // https://leetcode.cn/problems/reverse-linked-list/
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

    // 将两个升序链表合并为一个新的 升序 链表并返回
    // 新链表是通过拼接给定的两个链表的所有节点组成的
    // 测试链接 : https://leetcode.cn/problems/merge-two-sorted-lists/
    template <typename T>
    std::shared_ptr<SinglyList<T>> mergeLists(std::shared_ptr<SinglyList<T>> head1, std::shared_ptr<SinglyList<T>> head2)
    {
        if (!head1 || !head2)
            return head1 ? head1 : head2;

        std::shared_ptr<SinglyList<T>> head = head1->_val < head2->_val ? head1 : head2;
        std::shared_ptr<SinglyList<T>> cur1 = head->_next;
        std::shared_ptr<SinglyList<T>> cur2 = head == head1 ? head2 : head1;
        std::shared_ptr<SinglyList<T>> pre = head;
        while (cur1 && cur2)
        {
            if (cur1->_val < cur2->_val)
            {
                pre->_next = cur1;
                cur1 = cur1->_next;
            }
            else
            {
                pre->_next = cur2;
                cur2 = cur2->_next;
            }
            pre = pre->_next;
        }
        pre->_next = cur1 ? cur1 : cur2;
        return head;
    }

    // 给你两个 非空 的链表，表示两个非负的整数
    // 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字
    // 请你将两个数相加，并以相同形式返回一个表示和的链表。
    // 你可以假设除了数字 0 之外，这两个数都不会以 0 开头
    // 测试链接：https://leetcode.cn/problems/add-two-numbers/
    std::shared_ptr<SinglyList<int>> addLists(std::shared_ptr<SinglyList<int>> head1, std::shared_ptr<SinglyList<int>> head2);

    // 给你一个链表的头节点 head 和一个特定值 x
    // 请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
    // 你应当 保留 两个分区中每个节点的初始相对位置
    // 测试链接 : https://leetcode.cn/problems/partition-list/
    template <typename T>
    std::shared_ptr<SinglyList<T>> partitionList(std::shared_ptr<SinglyList<T>> head, T x)
    {
        std::shared_ptr<SinglyList<T>> leftHead = nullptr, leftTail = nullptr;
        std::shared_ptr<SinglyList<T>> rightHead = nullptr, rightTail = nullptr;
        std::shared_ptr<SinglyList<T>> next = nullptr;
        while (head)
        {
            next = head->_next;
            head->_next = nullptr;
            if (head->_val < x)
            {
                if (!leftHead)
                    leftHead = head;
                else
                    leftTail->_next = head;
                leftTail = head;
            }
            else
            {
                if (!rightHead)
                    rightHead = head;
                else
                    rightTail->_next = head;
                rightTail = head;
            }
            head = next;
        }
        if (leftTail)
            leftTail->_next = rightHead;
        return leftHead ? leftHead : rightHead;
    }
} // namespace Algo_List
