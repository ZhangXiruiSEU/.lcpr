/*
 * @lc app=leetcode id=98 lang=cpp
 * @lcpr version=30400
 *
 * [98] Validate Binary Search Tree
 */
#include "lc.h"
#include <climits>
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
class Solution
{
  public:
    bool isValidBST(TreeNode *root)
    {
        long pre = LONG_MIN; // 如果用指针会更泛用
        bool valid = true;
        function<void(TreeNode *)> recur = [&](TreeNode *r) {
            if (r == nullptr || valid == false)
                return;

            // if (r->left!=nullptr && r->left->val>=r->val)
            //     return false;
            // if (r->right!=nullptr && r->right->val<=r->val)
            //     return false;
            recur(r->left);

            if (r->val <= pre)
                valid = false;
            pre = r->val;
            recur(r->right);
        };

        function<bool(TreeNode *, TreeNode *, TreeNode *)> _isValidBST = [&](TreeNode *root, TreeNode *min,
                                                                            TreeNode *max) {
            // base case
            if (root == nullptr)
                return true;
            // 若 root->val 不符合 max 和 min 的限制，说明不是合法 BST
            if (min != nullptr && root->val <= min->val)
                return false;
            if (max != nullptr && root->val >= max->val)
                return false;
            // 根据定义，限定左子树的最大值是 root->val，右子树的最小值是 root->val
            return _isValidBST(root->left, min, root) && _isValidBST(root->right, root, max);
        };

        recur(root);
        //valid = _isValidBST(root, nullptr, nullptr);
        return valid;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */
