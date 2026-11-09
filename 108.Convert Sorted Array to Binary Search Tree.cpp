/*
 * @lc app=leetcode id=108 lang=cpp
 * @lcpr version=30403
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode *build(vector<int> &nums, int left, int right)
    {
        if (right - left < 0)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        auto leftptr = build(nums, left, mid - 1);
        auto rightptr = build(nums, mid + 1, right);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = leftptr;
        root->right = rightptr;
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */
