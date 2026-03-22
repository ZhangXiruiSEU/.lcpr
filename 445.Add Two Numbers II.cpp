/*
 * @lc app=leetcode id=445 lang=cpp
 * @lcpr version=30307
 *
 * [445] Add Two Numbers II
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
        vector<int> s1, s2;
        while (l1 != nullptr)
        {
            s1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push_back(l2->val);
            l2 = l2->next;
        }
        int temp_sum = 0, sum = 0, carry = 0;
        ListNode dummy;
        while (!s1.empty() || !s2.empty() || carry > 0)
        {
            temp_sum = 0;
            if (!s1.empty())
            {
                temp_sum += s1.back();
                s1.pop_back();
            }
            if (!s2.empty())
            {
                temp_sum += s2.back();
                s2.pop_back();
            }
            temp_sum += carry;
            carry = temp_sum / 10;
            sum = temp_sum % 10;

            ListNode *newNode = new ListNode(sum);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }
        return dummy.next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */
