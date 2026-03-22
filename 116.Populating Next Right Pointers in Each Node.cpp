/*
 * @lc app=leetcode id=116 lang=cpp
 * @lcpr version=30305
 *
 * [116] Populating Next Right Pointers in Each Node
 */
#include "lc.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr ) 
            return root;
        tra(root->left, root->right);
        return root;

    }

    void tra(Node* n1, Node* n2){
        if (n1 == nullptr || n2 == nullptr) return;
        n1->next=n2;
        tra(n1->left,n1->right);
        tra(n1->right,n2->left);
        tra(n2->left,n2->right);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

