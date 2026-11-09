/*
 * @lc app=leetcode id=121 lang=cpp
 * @lcpr version=30400
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <climits>
#include <vector>
class Solution
{
  public:
    // 所谓股票购买问题
    // 去看教程里面的通用思路
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = INT_MIN;

        for (int i = 1; i <= prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1],  - prices[i - 1]);
        }
        return dp[prices.size()][0];
    }
    int maxProfit_(vector<int> &prices)
    {
        vector memo(prices.size(), vector(2, vector<int>(2, -1)));
        auto dp = [&](auto &self, int i, int k, int hold) {
            if (i == 0)
            {
                if (hold)
                    return -prices[0];
                else
                    return 0;
            }
            if (k == 0)
            {
                return 0;
            }
            if (memo[i][k][hold] != -1)
                return memo[i][k][hold];

            // 第 i 天，当前交易数的限制为 k，
            if (hold == 0)
            {                                                               // 今天没有股票
                memo[i][k][hold] = max(self(self, i - 1, k, 1) + prices[i], // 今天卖出了
                                       self(self, i - 1, k, 0));            // 今天歇了
            }
            else if (hold == 1)
            { // 今天有股票
                memo[i][k][hold] =
                    max(self(self, i - 1, k - 1, 0) - prices[i], // 今天买了，今天要买，所以之前最多交易 k-1 次
                        self(self, i - 1, k, 1));                // 今天歇了
            }
            return memo[i][k][hold];
        };
        return max(dp(dp, prices.size() - 1, 1, 0), dp(dp, prices.size() - 1, 1, 1));
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
