/*
 * @lc app=leetcode id=138 lang=cpp
 * @lcpr version=30400
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// 一个哈希表 + 两次遍历。

#include <cstddef>
#include <unordered_map>
class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        auto p = head;
        while (p != nullptr)
        {
            auto copy = new Node(p->val);
            mp[p] = copy;
            p = p->next;
        }
        p = head;
        while (p != nullptr)
        {
            mp[p]->next = mp[p->next];
            mp[p]->random = mp[p->random];
            p = p->next;
        }
        return mp[head];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */
