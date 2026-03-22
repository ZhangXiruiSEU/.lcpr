/*
 * @lc app=leetcode id=230 lang=cpp
 * @lcpr version=30400
 *
 * [230] Kth Smallest Element in a BST
 */
#include "lc.h"
#include <functional>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> seq;
        function<void(TreeNode* )> recur = [&](TreeNode* r){
            if (r == nullptr ) return ;
            recur(r->left);
            seq.push_back(r->val);
            recur(r->right);
        };
        recur(root);
        return seq[k-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */

