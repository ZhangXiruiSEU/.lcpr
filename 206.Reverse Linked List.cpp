/*
 * @lc app=leetcode id=206 lang=cpp
 * @lcpr version=30304
 *
 * [206] Reverse Linked List
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

//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        if (head==nullptr || head->next == nullptr)
            return head;
        auto p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
    ListNode *reverseList_(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // 由于单链表的结构，至少要用三个指针才能完成迭代反转
        // cur 是当前遍历的节点，pre 是 cur 的前驱结点，nxt 是 cur 的后继结点
        ListNode *pre, *cur, *nxt;
        pre = nullptr;
        cur = head;
        nxt = head->next;
        while (cur != nullptr)
        {
            // 逐个结点反转
            cur->next = pre;
            // 更新指针位置
            pre = cur;
            cur = nxt;
            if (nxt != nullptr)
            {
                nxt = nxt->next;
            }
        }
        // 返回反转后的头结点
        return pre;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
