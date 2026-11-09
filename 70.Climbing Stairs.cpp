/*
 * @lc app=leetcode id=70 lang=cpp
 * @lcpr version=30400
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <vector>
class Solution
{
    // 经典 dp，其实就是斐波那契数列，
    //  今后也可以尝试用 回溯和 for 循环的方式去解
  public:
    int climbStairs(int n)
    {
        // dp(n) 表示到第 n 级的方法数量
        // dp(n) = dp(n-1) + dp(n-2)

        vector<int> dp(n+1);
        dp[1] = 1;
        dp[0] = 1;
        for (int i = 2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
    int climbStairs_recurdp(int n)
    {
        vector<int> memo(n + 1, -1);
        auto dp = [&](auto &self, int i) {
            if (i == 1)
            {
                return 1;
            }
            if (i <= 0)
            {
                return 1;
            }

            if (memo[i] != -1)
            {
                return memo[i];
            }

            memo[i] = self(self, i - 1) + self(self, i - 2);
            return memo[i];
        };
        return dp(dp, n);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
