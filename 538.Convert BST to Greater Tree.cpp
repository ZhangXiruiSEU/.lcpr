/*
 * @lc app=leetcode id=538 lang=cpp
 * @lcpr version=30400
 *
 * [538] Convert BST to Greater Tree
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
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        
        function<void(TreeNode *)> recur = [&](TreeNode *r) {
            if (r == nullptr)
                return;

            recur(r->right);
            sum += r->val;
            r->val = sum;
            
            recur(r->left);
            
            
        };
        recur(root);

        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

 */
