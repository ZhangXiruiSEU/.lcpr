/*
 * @lc app=leetcode id=95 lang=cpp
 * @lcpr version=30400
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode *> generateTrees(int n)
    {
        // Given an integer n, 
        // return all the structurally unique BST's (binary search trees), 
        // which has exactly n nodes of unique values from 1 to n. 
        // Return the answer in any order

        // recursive function:
        // generate the list of BST tree, 
        std::function<vector<TreeNode *>(int, int)> generate = 
        //wich nodes from start to end , [start, end]
        [&](int start, int end) -> vector<TreeNode *> {
            // no node
            if (start == end + 1) return vector<TreeNode *>(1, nullptr);
            // just one node ,  omissible
            //if (start == end)
            //    return vector<TreeNode *>(1, new TreeNode(end));
            // normal case:
            vector<TreeNode *> res;//result list
            for (int i = start; i <= end; i++){
                // possible cases list of left child 
                auto leftList = generate(start, i - 1);
                // possible cases list of right child 
                auto rightList = generate(i + 1, end);

                //double for loop to permutate
                for (auto &l : leftList){
                    for (auto &r : rightList){
                        //a brand new root every time
                        TreeNode *root = new TreeNode(i); 
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
            return res;
        };
        return generate(1,n);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
