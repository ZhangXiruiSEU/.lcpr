/*
 * @lc app=leetcode id=700 lang=cpp
 * @lcpr version=30400
 *
 * [700] Search in a Binary Search Tree
 */
#include "lc.h"
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root==nullptr) {
            return nullptr;
        }
        if (val<root->val){
            return searchBST(root->left, val);
        }
        if (val>root->val){
            return searchBST(root->right, val);
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */

