/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = nullptr, *leftTail = nullptr;
        ListNode *rightHead = nullptr, *rightTail = nullptr;
        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            head->next = nullptr;
            if (head->val < x) {
                if (!leftHead)
                    leftHead = head;
                else
                    leftTail->next = head;
                leftTail = head;
            } else {
                if (!rightHead)
                    rightHead = head;
                else
                    rightTail->next = head;
                rightTail = head;
            }
            head = next;
        }
        if (leftTail) leftTail->next = rightHead;
        return leftHead ? leftHead : rightHead;
    }
};
// @lc code=end
