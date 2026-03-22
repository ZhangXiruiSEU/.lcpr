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
		auto p =&dummy;
        function<bool(ListNode *, ListNode *)> cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
		for (auto head:lists){
			if (head!=nullptr){
				pq.push(head);
			}
		}
		while (!pq.empty()){
			auto node = pq.top();
			pq.pop();
			p->next = node;
			if (node ->next!=nullptr) pq.push(node->next);
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
