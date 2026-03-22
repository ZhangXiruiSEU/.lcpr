/*
 * @lc app=leetcode id=437 lang=cpp
 * @lcpr version=30400
 *
 * [437] Path Sum III
 */

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
#include <unordered_map>
class Solution
{
  public:
    unordered_map<long long, int> mp;
    long long sum{};
    int k;
    int res{};
    int pathSum(TreeNode *root, int targetSum)
    {
        k = targetSum;
        dfs(root);
        return res;
    }

    void dfs(TreeNode *r)
    {
        if (!r)
            return;
        // 参考 560 题，但是这个要会用前后序遍历

        //进入节点，把情况记录下来
        mp[sum]++;
        sum += r->val;
        // 如果发现有满足条件的，那就记录次数吧
        if (mp.count(sum - k))
        {
            res += mp[sum - k];
        }


        //去左右分别做
        dfs(r->left);
        
        dfs(r->right);

        // 撤销掉这个节点的影响
        sum -= r->val;
        mp[sum]--;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
