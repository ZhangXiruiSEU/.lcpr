/*
 * @lc app=leetcode id=104 lang=cpp
 * @lcpr version=30400
 *
 * [104] Maximum Depth of Binary Tree
 */
#include "lc.h"
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
    int maxDepth(TreeNode* root) {
        int max=0;
        function<int(TreeNode*)> recur = [&](TreeNode* r)->int{
            if (r == nullptr) return 0;
            
            if (r->left == nullptr && r->right==nullptr){
                return 1;
            }
            return std::max(recur(r->left),recur(r->right))+1;
            
            
        };

        max = recur(root);
        return max;
    }
    int maxDepth_recur(TreeNode* root) {
        int depth=0;
        int max=0;
        function<void(TreeNode*)> recur = [&](TreeNode* r){
            if (r == nullptr) return;
            depth ++;
            if (r->left == nullptr && r->right==nullptr){
                max = depth>max?depth:max;
            }
            recur(r->left);
            recur(r->right);
            depth--;
        };

        recur(root);
        return max;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

