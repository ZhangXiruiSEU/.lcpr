/*
 * @lc app=leetcode id=107 lang=cpp
 * @lcpr version=30306
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while (q.empty() != true)
        {
            auto sz = q.size();
            vector<int> res1layer;
            for (int i = 0; i < sz; i++)
            {
                auto temp = q.front();
                q.pop();
                res1layer.push_back(temp->val);
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
            res.push_back(res1layer);
        }
        std::reverse(res.begin(),res.end());
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
