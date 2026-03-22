/*
 * @lc app=leetcode id=102 lang=cpp
 * @lcpr version=30306
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res; 
        res.reserve(2000);
        queue<TreeNode*> q;
        q.push(root);
        //int depth =1;
        while(q.empty()==false){
            size_t CurrentLevelSize = q.size();
            vector<int> resTemp;
            resTemp.reserve(CurrentLevelSize);
            for (size_t i = 0;i<CurrentLevelSize;i++){
                
                auto rootTemp = q.front();
                resTemp.push_back(rootTemp->val);
                q.pop();
                if (rootTemp->left!=nullptr) q.push(rootTemp->left);
                if (rootTemp->right!=nullptr) q.push(rootTemp->right);
                
            }
            res.push_back(move(resTemp));
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

