/*
 * @lc app=leetcode id=236 lang=cpp
 * @lcpr version=30400
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */
#include "lc.h"
#include <cstddef>
#include <functional>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        function<TreeNode*(TreeNode*)> find = [&](TreeNode* root)->TreeNode*{
            if (root==nullptr) return nullptr;
            if (root->val==p->val||root->val==q->val) return root;

            auto left = find(root->left);
            auto right =find(root->right);
            if (left!=nullptr&&right!=nullptr){
                return root;
            }
            return left!=nullptr?left:right;
        };
        return find (root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

