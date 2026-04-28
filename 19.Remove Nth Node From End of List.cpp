/*
 * @lc app=leetcode id=19 lang=cpp
 * @lcpr version=30400
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy;
        dummy.next = head;
        auto p = &dummy;
        //先走 n+1 步
        for (int i = 0; i < n+1; i++)
        {
            p = p->next;
        }
        // 同走 直到p 到达结尾
        auto p2 = &dummy;
        while (p != nullptr)
        {
            p2=p2->next;
            p = p->next;
        }
        //此时 p2 就是倒数的n+1 个
        p2->next = p2->next->next;
        return dummy.next;
        
    }

    ListNode *removeNthFromEnd_old(ListNode *head, int n)
    {
        int i = 0;
        ListNode *target = nullptr;

        // 递归 方法
        auto recur = [&](auto &&self, ListNode *node) {
            if (node == nullptr)
            {
                return;
            }
            self(self, node->next);

            i++;
            if (i == n + 1)
            {
                target = node;
            }
        };
        ListNode dummy;
        dummy.next = head;
        recur(recur, &dummy);

        target->next = target->next->next;
        return dummy.next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
