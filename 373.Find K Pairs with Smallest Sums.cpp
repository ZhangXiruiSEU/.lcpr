/*
 * @lc app=leetcode id=373 lang=cpp
 * @lcpr version=30400
 *
 * [373] Find K Pairs with Smallest Sums
 */
#include "lc.h"
#include <queue>
#include <vector>
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        struct Cmp
        {
            bool operator()(vector<int> a, vector<int> b)
            {
                return a[0] + a[1] > b[0] + b[1];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;
        vector<vector<int>> res;
        vector<vector<vector<int>>> all;
        for (int i =0;i< nums1.size();i++)
        {
            for (int j =0;j<nums2.size();j++)
            {
                all[i][j] = vector<int>{nums1[i],nums2[j]};
            }
            
        }

        

        return res;
    }
    vector<vector<int>> kSmallestPairs_TLE(vector<int> &nums1, vector<int> &nums2, int k)
    {
        struct Cmp
        {
            bool operator()(vector<int> a, vector<int> b)
            {
                return a[0] + a[1] > b[0] + b[1];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;
        for (auto n1 : nums1)
        {
            for (auto n2 : nums2)
            {
                pq.push(vector<int>{n1, n2});
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */
