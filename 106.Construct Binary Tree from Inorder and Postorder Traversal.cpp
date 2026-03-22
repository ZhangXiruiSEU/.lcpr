/*
 * @lc app=leetcode id=106 lang=cpp
 * @lcpr version=30306
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,inorder.begin(),inorder.end(),postorder,postorder.begin(),postorder.end());
    }
    public:


    TreeNode *build(const vector<int> &inorder,
                    const vector<int>::iterator &inorderBegin,
                    const vector<int>::iterator &inorderEnd,
                    const vector<int> &postorder,
                    const vector<int>::iterator &postorderBegin,
                    const vector<int>::iterator &postorderEnd)
    {
        if(postorderBegin == postorderEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(*(postorderEnd-1));
        auto locationRootIn = find(inorderBegin,inorderEnd,*(postorderEnd-1));
        int leftSize = distance(inorderBegin,locationRootIn);

        root->left = build(inorder,inorderBegin,locationRootIn,
                            postorder,postorderBegin,postorderBegin+leftSize);
        root->right = build(inorder,locationRootIn+1,inorderEnd,
                            postorder,postorderBegin+leftSize,postorderEnd-1);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

