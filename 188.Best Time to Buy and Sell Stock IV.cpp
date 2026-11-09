/*
 * @lc app=leetcode id=188 lang=cpp
 * @lcpr version=30404
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <vector>
class Solution
{
  public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int k_ = 0; k_ <= k; k_++)
        {
            dp[0][k_][0] = 0;
            dp[0][k_][1] = INT_MIN;
        }
        for (int i = 1; i <= prices.size(); i++)
        {
            for (int j = 1; j <= k; j++)
            {
                // 前 i 天  允许交易 j 次 0不持有 1 持有
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i-1]);

                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i-1]);
            }
        }
        return dp[prices.size()][k][0];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */
