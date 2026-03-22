/*
 * @lc app=leetcode id=105 lang=cpp
 * @lcpr version=30305
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder,preorder.begin(),preorder.end(),inorder,inorder.begin(),inorder.end());
    }
    TreeNode *build(const vector<int> &preorder,
                    const vector<int>::iterator &preorderBegin,
                    const vector<int>::iterator &preorderEnd,
                    const vector<int> &inorder,
                    const vector<int>::iterator &inorderBegin,
                    const vector<int>::iterator &inorderEnd)
    {
        if(preorderBegin == preorderEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(*preorderBegin);
        auto locationRootIn = find(inorderBegin,inorderEnd,*preorderBegin);
        int leftSize = distance(inorderBegin,locationRootIn);

        root->left = build(preorder,preorderBegin+1,preorderBegin+1+leftSize,
                            inorder,inorderBegin,locationRootIn);
        root->right = build(preorder,preorderBegin+1+leftSize,preorderEnd,
                            inorder,locationRootIn+1,inorderEnd);
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
