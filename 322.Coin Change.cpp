/*
 * @lc app=leetcode id=322 lang=cpp
 * @lcpr version=30304
 *
 * [322] Coin Change
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp[n] 凑出 n 的硬币数量

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        // dp[n] = min(for coin in coins: dp[n-coin]+1
        for (int i = 1; i <= amount; i++)
        {

            for (auto &coin : coins)
            {
                if (i - coin >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }

    int coinChange_(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, -2);
        // return dp(coins,amount,memo);
        return dp_array(coins, amount);
    }
    int dp(vector<int> &coins, int amount, vector<int> &memo)
    {

        int res = INT_MAX;
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (memo[amount] != -2)
            return memo[amount];
        for (const int coin : coins)
        {
            int sub = dp(coins, amount - coin, memo);
            if (sub == -1)
                continue;

            res = min(res, sub + 1);
        }
        memo[amount] = (res == INT_MAX ? -1 : res);
        return memo[amount];
    }

    int dp_array(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        // dp[i],when the hell the target amout is i,
        //  the minimum numbers of coins is dp[i]
        // dp[i] = min (dp[i-coin]+1 for coin in coins)
        for (int i = 0; i < dp.size(); i++)
        {
            for (auto coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
