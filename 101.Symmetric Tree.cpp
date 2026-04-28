/*
 * @lc app=leetcode id=101 lang=cpp
 * @lcpr version=30403
 *
 * [101] Symmetric Tree
 */

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
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode* left,TreeNode* right){
        if (left==nullptr && right == nullptr){
            return true;
        }
        if (left==nullptr || right == nullptr)
            return false;
        if (left->val!=right->val)
            return false;
        return isSym(left->left, right->right)&&isSym(left->right, right->left);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

