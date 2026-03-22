/*
 * @lc app=leetcode id=62 lang=cpp
 * @lcpr version=30400
 *
 * [62] Unique Paths
 */
#include "lc.h"
// @lc code=start
class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            dp[0] = 1;
            for (int j = 1; j < n; j++)
            {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */
