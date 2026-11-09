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
class Solution
{
  public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->left);
        flatten(root->right);
        auto pleft = root->left;
        if (pleft == nullptr)
            return;
        // 找到左边的最后一个
        while (pleft->right != nullptr)
            pleft = pleft->right;
        // 左边的最后一个直接连上右边的
        pleft->right = root->right;
        // 把右边换成左边
        root->right = root->left;
        // 左边切断
        root->left = nullptr;
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
