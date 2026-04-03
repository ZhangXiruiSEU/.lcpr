/*
 * @lc app=leetcode id=307 lang=cpp
 * @lcpr version=30307
 *
 * [307] Range Sum Query - Mutable
 */
#include "lc.h"
#include <vector>
// @lc code=start
class NumArray
{
    vector<int> tree;
    vector<int> nums;
    // 线段树我们这里采用区间左闭右闭来思考，不挖坑了
    void build(int node, int l, int r)
    {
        // 如果区间就剩一个元素，
        if (l == r)
        {
            // 树的节点值就等于num 原来的，停止递归
            tree[node] = nums[l];
            return;
        }

        // 总的来说是后序遍历，因为当前节点的值依赖左右子树的值
        // 从中间分开，
        int mid = l + (r - l) / 2;

        //
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        // 左右之和
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void updateTree(int node, int l, int r, int index, int val)
    {
        // 如果要更新，其实就是要在树中找到我们要的节点
        // 找到了
        if (l == r)
        {
            // 改
            tree[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (index <= mid) // 在左边改，所以每次就找一半就够了
            updateTree(node * 2, l, mid, index, val);
        else
            updateTree(node * 2 + 1, mid + 1, r, index, val);

        // 改完之后要更新上面的值
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        //查询  完全没交集，
        if (qr < l || r < ql)
            return 0;
        
        // 当前节点代表的∈我要查的
        if (ql <= l && r <= qr)
            return tree[node];


        //不是完全包含，但也有交集，只能继续拆
        int mid = l + (r - l) / 2;
        
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

  public:
    NumArray(vector<int> &nums) : tree(nums.size() * 4), nums(nums)
    {
        if (!nums.empty())
            build(1, 0, nums.size() - 1);
    }

    void update(int index, int val)
    {
        if (nums.empty())
            return;

        nums[index] = val;
        updateTree(1, 0, nums.size() - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(1, 0, nums.size() - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

/*
// @lcpr case=start
// ["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]\n
// @lcpr case=end

 */
