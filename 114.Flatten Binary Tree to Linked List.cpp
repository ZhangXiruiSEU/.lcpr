/*
 * @lc app=leetcode id=114 lang=cpp
 * @lcpr version=30305
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if(root == nullptr) 
            return;
        flatten(root->left);
        flatten(root->right);
        if (root->left == nullptr) return;
        TreeNode *p = root->left;
        for (;p->right!=nullptr;p=p->right){

        }
        p->right = root->right;

        
        root->right = root->left;
        root->left=nullptr;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

