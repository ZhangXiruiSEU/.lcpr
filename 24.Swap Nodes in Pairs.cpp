/*
 * @lc app=leetcode id=24 lang=cpp
 * @lcpr version=30400
 *
 * [24] Swap Nodes in Pairs
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

class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto *dummy = new ListNode;
        dummy->next = head;
        auto p = dummy;
        while (p ->next!= nullptr&&p->next->next!=nullptr)
        {
            auto p1 = p->next;
            auto p2 = p->next->next;
            p->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            
            p=p->next->next;

        }
        return dummy->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
