/*
 * @lc app=leetcode id=234 lang=cpp
 * @lcpr version=30304
 *
 * [234] Palindrome Linked List
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution {
    ListNode* left = nullptr;
    bool res = true;
public:
    bool isPalindrome(ListNode* head) {
        enum class Method {Normal, Optimized};
        Method m = Method::Optimized;
        this->left = head;
        switch (m){
            case Method::Normal:
                traverse(head);

                break;
            case Method::Optimized:
                auto slow = head ;
                auto fast = head ; 
                while (fast != nullptr && fast->next != nullptr){
                    fast = fast->next->next;
                    slow = slow->next;

                }
                traverse(slow);
                
                break;
        }
        return res;

    }

    void traverse(ListNode* head){
        if (head == nullptr) return;

        traverse(head->next);
        if (head->val != left->val){
            this->res = false;
            return;
        }
        left = left -> next;

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

