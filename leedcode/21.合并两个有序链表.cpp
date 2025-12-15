/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) return head1 ? head1 : head2;

        ListNode* head = head1->val < head2->val ? head1 : head2;
        ListNode* cur1 = head->next;
        ListNode* cur2 = head == head1 ? head2 : head1;
        ListNode* pre = head;
        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                pre->next = cur1;
                cur1 = cur1->next;
            } else {
                pre->next = cur2;
                cur2 = cur2->next;
            }
            pre = pre->next;
        }
        pre->next = cur1 ? cur1 : cur2;
        return head;
    }
};
// @lc code=end
