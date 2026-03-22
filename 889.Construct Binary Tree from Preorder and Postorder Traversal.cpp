/*
 * @lc app=leetcode id=889 lang=cpp
 * @lcpr version=30306
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder,preorder.begin(),preorder.end(),postorder,postorder.begin(),postorder.end());
    }   



    TreeNode *build(const vector<int> &preorder,
                    const vector<int>::iterator &preorderBegin,
                    const vector<int>::iterator &preorderEnd,
                    const vector<int> &postorder,
                    const vector<int>::iterator &postorderBegin,
                    const vector<int>::iterator &postorderEnd)
    {
        if(preorderBegin == preorderEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(*preorderBegin);
        
        if (preorderBegin+1 == preorderEnd)
            return root;
        auto locationNextLeftPost = find(postorderBegin,postorderEnd,*(preorderBegin+1));

        int LeftSize = distance(postorderBegin,locationNextLeftPost);

        root->left = build(preorder,preorderBegin+1,preorderBegin+1+LeftSize+1,
                            postorder,postorderBegin,postorderBegin+LeftSize+1);
        root->right = build(preorder,preorderBegin+1+LeftSize+1,preorderEnd,
                            postorder,postorderBegin+LeftSize+1,postorderEnd-1);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */

