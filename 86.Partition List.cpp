/*
 * @lc app=leetcode id=86 lang=cpp
 * @lcpr version=30403
 *
 * [86] Partition List
 */

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
#include <cstddef>
class Solution
{
  public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dummy1, dummy2;
        auto p1 = &dummy1;
        auto p2 = &dummy2;
        auto p = head;
        while (p != nullptr)
        {
            if (p->val < x)
            {
                p1->next = p;
                p1 = p1->next;
                
            }
            else
            {
                p2->next = p;
                p2 = p2->next;
                
            }
            p = p->next;
        }
        p1->next = dummy2.next;
        p2->next = nullptr;
        return dummy1.next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
