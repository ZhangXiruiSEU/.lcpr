/*
 * @lc app=leetcode id=92 lang=cpp
 * @lcpr version=30400
 *
 * [92] Reverse Linked List II
 */
#include "lc.h"
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
class Solution {
public:
    ListNode* reverseBetween1(ListNode* head, int left, int right) {
        auto dummy = new ListNode;
        dummy->next = head;
        auto p = dummy;
        auto l = left;
        while (l-1>0){
            l--;
            p=p->next;
        }//eg left =2 ,then move once 
        auto leftp = p->next;
        if (leftp==nullptr||leftp->next==nullptr||right-left==0) return head;
        
        int n  = right - left +1;
        ListNode* pre = nullptr;
        auto cur = leftp;
        auto nxt = leftp->next;
        while(n>0){
            n--;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if (nxt!=nullptr)
            nxt = nxt->next;
            
        }
        p->next->next = cur;
        p->next = pre;
        return dummy->next;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode;
        dummy->next = head;
        auto p = dummy;
        auto l = left;
        while (l-1>0){
            l--;
            p=p->next;
        }//eg left =2 ,then move once 
        auto leftp = p->next;
        if (leftp==nullptr||leftp->next==nullptr||right-left==0) return head;
        
        int n  = right - left ;
        auto pre = p; //反转区间前面的一个
        auto cur = leftp;//反转区间的第一个
        //auto nxt = leftp->next;//即将反转的那个
        while(n>0){
            n--;
            auto nxt = cur ->next;
            cur->next = nxt->next;   //把 nxt 从链表中“切掉”，让 cur 连上 nxt 的后面
            nxt->next = pre->next;// 把 nxt 接到当前反转区间的头部
            pre->next = nxt; //让 pre 指向新的头部
            
            
            
        }
        
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

