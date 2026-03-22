/*
 * @lc app=leetcode id=122 lang=cpp
 * @lcpr version=30400
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <climits>
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        
        vector memo(prices.size(), vector(2, INT_MIN));
        auto dp = [&](auto &self, int i, int hold) {
            if (i == 0)
            {
                if (hold)
                    return -prices[0];
                else
                    return 0;
            }

            if (memo[i][hold] != INT_MIN)
                return memo[i][hold];

            // 第 i 天，当前交易数的限制为 k，
            if (hold == 0)
            {                                                         // 今天没有股票
                memo[i][hold] = max(self(self, i - 1, 1) + prices[i], // 今天卖出了
                                    self(self, i - 1, 0));            // 今天歇了
            }
            else if (hold == 1)
            {                                                            // 今天有股票
                memo[i][hold] = max(self(self, i - 1, 0) - prices[i], // 今天买了，今天要买，所以之前最多交易 k-1 次
                                       self(self, i - 1, 1));            // 今天歇了
            }
            return memo[i][hold];
        };
        return max(dp(dp, prices.size() - 1, 0), dp(dp, prices.size() - 1, 1));
    }
}

;
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
