/*
 * @lc app=leetcode id=96 lang=cpp
 * @lcpr version=30400
 *
 * [96] Unique Binary Search Trees
 */
#include "lc.h"
#include <functional>
#include <vector>
// @lc code=start

class Solution
{
  public:
    int numTrees(int n)
    {
        vector<int>memo(n+1,-1);
        std::function<int(int)> count = [&](int n) {
            if (memo[n]!=-1) return memo[n];
            if (n == 0)
                return 1;
            if (n == 1)
                return 1;
            if (n == 2)
                return 2;
            int kinds = 0;
            for (int i=1;i<=n;i++){
                kinds += count(i-1)*count(n-i);
            }
            memo[n] = kinds;
            return kinds;
        };

        return count(n);
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
