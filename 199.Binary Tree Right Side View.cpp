/*
 * @lc app=leetcode id=199 lang=cpp
 * @lcpr version=30400
 *
 * [199] Binary Tree Right Side View
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

#include <queue>
#include <vector>
class Solution
{
  public:
    vector<int> res;
    vector<int> rightSideView(TreeNode *root)
    {
        // dfs(root, 0);
        bfs(root);
        return res;
    }

    void dfs(TreeNode *r, int level)
    {
        if (!r)
            return;
        if (level == res.size())
        {
            res.push_back(r->val);
        }
        dfs(r->right, level + 1);
        dfs(r->left, level + 1);
    }
    void bfs(TreeNode *r)
    {//巩固 bfs 写法
        if (!r)
            return;
        queue<TreeNode *> q;
        q.push(r);
        while (!q.empty())
        {
            auto sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                auto cur = q.front();

                q.pop();
                if (i == 0)
                    res.push_back(cur->val);
                if (cur->right)
                    q.push(cur->right);
                if (cur->left)
                    q.push(cur->left);
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
