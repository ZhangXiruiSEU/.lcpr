/*
 * @lc app=leetcode id=25 lang=cpp
 * @lcpr version=30400
 *
 * [25] Reverse Nodes in k-Group
 */
#include "lc.h"
#include <chrono>
#include <cstddef>
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
    ListNode *reverseN(ListNode *head, int n)
    {
        if (head==nullptr||head->next == nullptr)
            return head;
        auto p = head;
        int i  = n-1;
        while (i > 0 && p != nullptr)
        {
            p = p->next;
            i--;
        }
        if (p == nullptr)
            return head;
        ListNode *pre, *cur, *nxt;
        pre = nullptr;
        cur = head;
        nxt = head->next;
        i=n;
        while (i>0)
        {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if (nxt != nullptr)
            {
                nxt = nxt->next;
            }
            i--;
        }
        head->next = reverseN(cur, n);

        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // auto dummy = new ListNode;
        // dummy->next = head;
        // auto p = dummy;
        return reverseN(head, k);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
