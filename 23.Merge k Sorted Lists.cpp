/*
 * @lc app=leetcode id=23 lang=cpp
 * @lcpr version=30400
 *
 * [23] Merge k Sorted Lists
 */
#include "lc.h"
#include <cstddef>
#include <functional>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy;
        auto p = &dummy;

        struct cmp
        {
            bool operator()(ListNode *a, ListNode *b)
            {
                return a->val > b->val;
            }
        };

        // 传大于号 其实是小顶堆
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        // 把当前的每个节点的头的值都压入
        for (auto head : lists)
        {
            if (head != nullptr)
            {
                pq.push(head);
            }
        }
        // 还不为空的时候
        while (!pq.empty())
        {
            auto node = pq.top();//取出
            pq.pop();//pop
            p->next = node;//链接
            if (node->next != nullptr)//如果链接的节点后面还有就把后面的压入
                pq.push(node->next);
            p = p->next;
        }
        return dummy.next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */
