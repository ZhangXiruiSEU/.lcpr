/*
 * @lc app=leetcode id=543 lang=cpp
 * @lcpr version=30400
 *
 * [543] Diameter of Binary Tree
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    int diameterOfBinaryTree(TreeNode* root) {
        // the sum of maxdepth of left and right tree
        
        int diameter = 0;
        function<int(TreeNode *)> recur_maxDep = [&](TreeNode * r){
            if (r==nullptr) {               
                return 0;
            }
        
            int Lmaxdep = recur_maxDep(r->left);
            int Rmaxdep = recur_maxDep(r->right);
            diameter = std::max(Lmaxdep+Rmaxdep,diameter);
            return std::max(Lmaxdep,Rmaxdep)+1;

        };
        recur_maxDep(root);
        return diameter;

        
        
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

