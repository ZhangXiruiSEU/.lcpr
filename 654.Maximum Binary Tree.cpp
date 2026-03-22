/*
 * @lc app=leetcode id=654 lang=cpp
 * @lcpr version=30305
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        
        return build(nums,nums.begin(),nums.end());
    }
    TreeNode* build(vector<int>& nums,vector<int>::iterator begin,vector<int>::iterator end){
        if (begin==end) return nullptr;
        
        auto it = max_element(begin,end);
        auto root= new TreeNode(*it);

        root->left = build(nums,begin,it);
        root->right = build(nums,it+1,end);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

