/*
 * @lc app=leetcode id=70 lang=cpp
 * @lcpr version=30400
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
    // 经典 dp，其实就是斐波那契数列，
    //  今后也可以尝试用 回溯和 for 循环的方式去解
  public:
    int climbStairs(int n)
    {
        int i_2 = 1;
        int i_1 = 1;
        int res = 1;

        for (int i = 2; i <= n; i++)
        {
            res = i_1 + i_2;
            i_2 = i_1;
            i_1 = res;
        }
        return res;
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
