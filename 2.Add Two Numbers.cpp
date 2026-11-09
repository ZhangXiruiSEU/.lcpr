/*
 * @lc app=leetcode id=2 lang=cpp
 * @lcpr version=30307
 *
 * [2] Add Two Numbers
 */
#include "lc.h"
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
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0, sum = 0;
        ListNode *dummy = new ListNode;
        auto p = dummy;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            // 注意最后可能还有一个进位
            int i1 = 0, i2 = 0;
            if (l1 != nullptr)
            {
                i1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                i2 = l2->val;
                l2 = l2->next;
            }
            sum = carry + i1 + i2;
            carry = sum / 10;
            sum = sum % 10;

            p->next = new ListNode(sum);
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
