/*
 * @lc app=leetcode id=82 lang=cpp
 * @lcpr version=30400
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) return head;
        //at least 2 nodes
        auto dummy = new ListNode;
        dummy->next = head;
        auto p = dummy;
        
        while (p->next != nullptr && p->next->next != nullptr) {
            if (p->next->val == p->next->next->val){
                auto movep = p->next->next;
                while ( p->next->val == movep->val){
                    movep = movep->next;
                    if (movep == nullptr) break;
                }
                p->next = movep;

            }
            else{
                p =p ->next;
            }
        }
        return  dummy->next;
    }


    ListNode* deleteDuplicates_old_for_No83(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p1!=nullptr && p2!=nullptr){
            if (p2->val == p1 ->val){
                p1->next = p2->next;
                auto tobeDeleted = p2;
                p2 = p2->next;
                delete tobeDeleted;
            }
            else {
                p1 = p1->next;
                if ( p2 != nullptr)
                    p2 =p2 ->next;

            }
            
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

