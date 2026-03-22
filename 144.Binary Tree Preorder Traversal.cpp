/*
 * @lc app=leetcode id=144 lang=cpp
 * @lcpr version=30400
 *
 * [144] Binary Tree Preorder Traversal
 */
#include "lc.h"
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        // very slow ,just a exercise of problem seperation
        vector<int> res(0);
        if (root == nullptr) return res;

        res.push_back(root->val);
        auto left = preorderTraversal(root->left);
        res.insert(res.end(),left.begin(),left.end());
        auto right = preorderTraversal(root->right);
        res.insert(res.end(),right.begin(),right.end());
        return  res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

