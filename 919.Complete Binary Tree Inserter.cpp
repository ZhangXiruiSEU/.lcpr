/*
 * @lc app=leetcode id=919 lang=cpp
 * @lcpr version=30400
 *
 * [919] Complete Binary Tree Inserter
 */
#include "lc.h"
#include <cstddef>
#include <deque>
#include <queue>
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
class CBTInserter
{
  public:
    TreeNode *root;
    deque<TreeNode *> dq;
    CBTInserter(TreeNode *root)
    {
        this->root = root;
        queue<TreeNode *> q;
        q.push(root);
        //注意 BFS 的写法，这里虽然不需要记录深度，
        //但是回忆一下万一需要深度的写法
        while (!q.empty())
        
        {
            auto cur = q.front();
            int size = q.size();
            q.pop();

            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
            if (cur->left == nullptr || cur->right == nullptr)
            {
                dq.push_back(cur);
            }
        }
    }

    int insert(int val)
    {
        auto new_node = new TreeNode(val);
        auto cur = dq.front();
        if (cur->left == nullptr)
        {
            cur->left = new_node;
        }
        else
        {
            cur->right = new_node;
            dq.pop_front();
        }
        dq.push_back(new_node);
        return cur->val;
    }

    TreeNode *get_root()
    {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

/*
// @lcpr case=start
// ["CBTInserter","insert","insert","get_root"]\n[[[1,2]],[3],[4],[]]\n
// @lcpr case=end

 */
