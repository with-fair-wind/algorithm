/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode *ans = nullptr, *cur = nullptr;
        int carry = 0;
        while (head1 || head2) {
            int sum = (head1 ? head1->val : 0) + (head2 ? head2->val : 0) + carry;
            carry = sum / 10;
            int val = sum % 10;
            if (!ans) {
                ans = new ListNode(val);
                cur = ans;
            } else {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
            head1 = head1 ? head1->next : nullptr;
            head2 = head2 ? head2->next : nullptr;
        }
        if (carry) cur->next = new ListNode(1);

        return ans;
    }
};
// @lc code=end
