/*
 * @lc app=leetcode id=148 lang=cpp
 * @lcpr version=30400
 *
 * [148] Sort List
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
    // 注意各种排序算法的使用场景
    // 不能用快速排序 涉及到交换，链表很难做
    // 直接做归并
    // 归并就是二叉树的后序遍历

    ListNode *sortList(ListNode *head)
    {
        if (!(head != nullptr && head->next != nullptr))
            return head;

        // 找中间节点，如果说偶数是靠前的一个，
        //  因为要断开所以找前面的一个更好
        auto find_mid_pointer = [](ListNode *p) {
            auto p1 = p;
            auto p2 = p->next; // 注意这个小 trick
            while (p2 != nullptr && p2->next != nullptr)
            {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            return p1;
        };

        // 打断链表，返回后半段的开头
        auto break_in_half = [find_mid_pointer](ListNode *p) {
            auto mid_pointer = find_mid_pointer(p);
            auto last_half_head = mid_pointer->next;
            mid_pointer->next = nullptr; // 断开
            return last_half_head;
        };

        // 合并两个有序链表，返回头节点
        auto merge = [](ListNode *l1, ListNode *l2) {
            ListNode dummy;
            ListNode *cur = &dummy;
            while (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    cur->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            cur->next = l1 ? l1 : l2;
            return dummy.next;
        };

        auto sort = [&](auto &self, ListNode *p) -> ListNode * {
            // 递归的截止条件
            if (!p || !p->next)
                return p;
            //打断 并取后半段的头
            auto last_half_head = break_in_half(p);

            // 递归左右两个链表，返回的就是排序好的头节点
            auto left = self(self, p);
            auto right = self(self, last_half_head);
            //合并就行了
            return merge(left, right);
        };

        return sort(sort, head);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
