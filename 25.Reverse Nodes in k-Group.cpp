/*
 * @lc app=leetcode id=25 lang=cpp
 * @lcpr version=30400
 *
 * [25] Reverse Nodes in k-Group
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
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {

    auto dummy = new ListNode;
    dummy->next = head;
    auto p = dummy;
    int length = -1;
    while (p != nullptr) {
      p = p->next;
      length++;
    }
    int runtimes = length / k;

    auto run = [&](int left, int right) {
      p = dummy;
      auto l = left;
      while (l - 1 > 0) {
        l--;
        p = p->next;
      } // eg left =2 ,then move once
      auto leftp = p->next;
      if (leftp == nullptr || leftp->next == nullptr || right - left == 0)
        return;

      int n = right - left + 1;
      ListNode *pre = nullptr;
      auto cur = leftp;
      auto nxt = leftp->next;
      while (n > 0) {
        n--;
        cur->next = pre;
        pre = cur;
        cur = nxt;
        if (nxt != nullptr)
          nxt = nxt->next;
      }
      p->next->next = cur;
      p->next = pre;
    };

    for (int i = 0; i < runtimes; i++) {
      run(1 + i * k, k + i * k);
    }

    return dummy->next;
  }
  auto rev(ListNode *head, int k) { return; }
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
