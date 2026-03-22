/*
 * @lc app=leetcode id=297 lang=cpp
 * @lcpr version=30400
 *
 * [297] Serialize and Deserialize Binary Tree
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    wstring serialize(TreeNode* root) {
        wstring res;
        function<void(TreeNode*)> recur = [&](TreeNode* r){
            if (r == nullptr){
                res+=9999;
                return ;
            }
            res+=r->val;
            recur(r->left);
            recur(r->right);
        };
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(wstring data) {
        if (data[0]==9999) return nullptr;
        function<void(TreeNode*)> recur = [&](TreeNode* r){
            

        };
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,null,4,5]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

