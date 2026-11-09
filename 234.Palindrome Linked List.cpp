/*
 * @lc app=leetcode id=234 lang=cpp
 * @lcpr version=30304
 *
 * [234] Palindrome Linked List
 */

// Definition for singly-linked list.
#include <pthread.h>
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow, *fast;
        slow = fast = head;
        // 快慢针找重点  slow是中点或者中点后的一个
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    bool isPalindrome_old(ListNode *head)
    {
        bool res = true;
        auto left = head;
        auto recur = [&](auto &&self, ListNode *node) {
            // 递归结束条件
            if (node == nullptr)
                return;
            // 递归吧
            self(self, node->next);
            // 如果目前还是回文串
            if (res)
            {
                // 比较
                if (node->val != left->val)
                {
                    res = false;
                }
                // 左边的指针移动
                left = left->next;
            }
        };
        recur(recur, head);

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
