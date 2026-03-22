/*
 * @lc app=leetcode id=83 lang=cpp
 * @lcpr version=30304
 *
 * [83] Remove Duplicates from Sorted List
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
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
class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr; // very important; or we need change the coe in the if
        auto fast = head;
        auto slow = head;
        while (fast != nullptr)
        {
            if (fast->val != slow->val)
            {
                slow = slow->next;
                slow->val = fast->val;
            }
            fast = fast->next;
        }

        slow->next = nullptr;
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */
