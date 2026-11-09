/*
 * @lc app=leetcode id=518 lang=cpp
 * @lcpr version=30307
 *
 * [518] Coin Change II
 */
#include "lc.h"
#include <vector>
// @lc code=start
class Solution
{
  public:
    int change(int amount, vector<int> &coins)
    {
        // dp[i][j]如果只用前 i 个，凑成 j ,那么dp就是方法数
        vector<vector<unsigned long long>> dp(coins.size() + 1, vector<unsigned long long>(amount + 1));
        // 初始条件 如果 i=0  dp 也是0  如果j=0 是 0 还是 1？
        for (int j = 0; j <= amount; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= coins.size(); i++)
        {
            dp[i][0] = 1;
        }
        // dp[i][j] = dp [i][j-coins[i-1]] 用了第 i 个硬币
        //          dp [i-1][j]
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {

                if (j - coins[i - 1] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
        }
        return dp[coins.size()][amount];
    }
    vector<vector<int>> memo;
    int change_(int amount, vector<int> &coins)
    {

        memo.resize(coins.size() + 1, vector<int>((amount + 1), -1));
        return dp(coins, coins.size(), amount);
    }
    int dp(const vector<int> &coins, int coinTypes, int amount)
    {
        // use coinTypes coinTypes coins, when amount = amount,
        // the dp() return the combinations of this situation
        if (coinTypes == 0)
            return 0; // if no coin is used, 0 combination
        if (amount == 0)
            return 1; // if total amount is 0, 1 combination
        if (amount < 0)
            return 0; // if total amount < 0, 0 combination

        // if the situation is computed, then return directly;
        if (memo[coinTypes][amount] != -1)
            return memo[coinTypes][amount];

        //
        memo[coinTypes][amount] = dp(coins, coinTypes - 1, amount) + // if we don't use the i-th coin type;
                                  dp(coins, coinTypes, amount - coins[coinTypes - 1]); // if we use the i-th coin type;
        // eg  3 types, but the 3rd type is actually coins[2];

        return memo[coinTypes][amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[1,2,5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
